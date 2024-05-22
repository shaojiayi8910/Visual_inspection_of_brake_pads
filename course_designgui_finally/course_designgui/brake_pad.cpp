#include "brake_pad.h"
#include <cmath>
#include <iostream>
#include <string>

// 计算两点间距离的函数
double two_point_distance(cv::Point point1, cv::Point point2) {
    double pixel_distance = std::sqrt(std::pow(point1.x - point2.x, 2) + std::pow(point1.y - point2.y, 2));
    return pixel_distance * MMPIXEL;
}

// 计算刹车片关键尺寸的函数


DistanceResult calculate_length(const cv::Mat &image) {
    DistanceResult result;

    // 灰度化
    cv::Mat img_gray;
    cv::cvtColor(image, img_gray, cv::COLOR_BGR2GRAY);

    // 二值化
    cv::Mat img_thresh1;
    cv::threshold(img_gray, img_thresh1, 130, 255, cv::THRESH_BINARY);

    // 查找轮廓
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(img_thresh1, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

    // 选择刹车片外部的轮廓
    std::vector<cv::Point> cnt = contours[1];

    // 创建灰度图那样大小的黑色底图
    cv::Mat draw_img = cv::Mat::zeros(img_gray.size(), CV_8UC1);
    cv::drawContours(draw_img, std::vector<std::vector<cv::Point>>{cnt}, 0, cv::Scalar(255), 2);

    // 将匹配到的刹车片模板上下关键尺寸位置大致提取出来
    cv::Mat draw_img_ROI = draw_img(cv::Rect(277, 1100, 3753 - 277, 1600 - 1100));

    // 创建原始图像的 ROI
    cv::Mat image_ROI = image(cv::Rect(277, 1100, 3753 - 277, 1600 - 1100)).clone(); // 克隆以避免修改原图像

    // Shi-Tomasi角点检测
    std::vector<cv::Point2f> corners;
    cv::goodFeaturesToTrack(draw_img_ROI, corners, 10, 0.01, 10);

    // 检查角点数量以避免越界
    if (corners.size() < 10) {
        std::cerr << "do not have 10" << std::endl;
        result.distance = 0;
        result.result_image = image.clone(); // 返回原图像
        return result;
    }

    // 获取上部和下部的关键点
    cv::Point top_point = corners[9];
    cv::Point down_point = corners[8];

    // 把点画出来
    cv::circle(image_ROI, top_point, 10, cv::Scalar(0, 0, 255), -1);
    cv::circle(image_ROI, down_point, 10, cv::Scalar(0, 0, 255), -1);

    // 计算距离
    result.distance = two_point_distance(top_point, down_point);

    // 绘制线条
    cv::line(image_ROI, top_point, down_point, cv::Scalar(0, 0, 255), 10);

    // 将距离显示在图像上
    std::string distance_text = "Distance: " + std::to_string(result.distance) + " cm";
    cv::putText(image_ROI, distance_text, cv::Point(450, 450), cv::FONT_HERSHEY_SIMPLEX, 4, cv::Scalar(0, 0, 255), 10);

    // 将图像和距离保存到结果结构体中
    result.result_image = image.clone(); // 使用原始图像并克隆

    // 将绘制的 ROI 图像粘贴回原图像
    image_ROI.copyTo(result.result_image(cv::Rect(277, 1100, 3753 - 277, 1600 - 1100)));

    // 返回结果结构体
    return result;
}
