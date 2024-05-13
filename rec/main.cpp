#include <opencv2/opencv.hpp>
#include<iostream>
#include"contour.h"
int main()
{
//    // 读取图像
//    cv::Mat image = cv::imread("1.jpg");
//
//    // 将图像转换为灰度图像
//    cv::Mat grayImage;
//    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
//    cv::namedWindow("grayImage", cv::WINDOW_NORMAL);
//    cv::imshow("grayImage", grayImage);
//    // 对灰度图像进行阈值处理
//    cv::Mat binaryImage;
//    cv::threshold(grayImage, binaryImage, 140, 255, cv::THRESH_BINARY_INV);
//    cv::namedWindow("binaryImage", cv::WINDOW_NORMAL);
//    cv::imshow("binaryImage", binaryImage);
//    // 查找轮廓
//    std::vector<std::vector<cv::Point>> contours;
//    cv::findContours(binaryImage, contours, cv::RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE);
//
//    // 设置面积阈值
//    double minArea = 170;
//
//     //在原始图像上绘制大于阈值的轮廓
//    for (size_t i = 0; i < contours.size(); ++i)
//    {
//        double area = cv::contourArea(contours[i]);
//        if (area >= minArea) {
//            cv::drawContours(image, contours, static_cast<int>(i), cv::Scalar(0, 255, 0), 2);
//        }
//    }
////    cv::drawContours(image, contours, -1, cv::Scalar(0, 255, 0), 2);
//    // 显示包含轮廓的图像
//    cv::namedWindow("Contours on Original Image", cv::WINDOW_NORMAL);
//    cv::imshow("Contours on Original Image", image);
//
//    // 等待按下任意键退出
//    cv::waitKey(0);
//    cv::destroyAllWindows();


     // 创建 ContourDetector 对象
    ContourDetector detector("1.jpg", 170);

    // 检测轮廓
    detector.detectContours();
    return 0;
}
