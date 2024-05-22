#include <opencv2/opencv.hpp>
#include <iostream>
struct DistanceResult {
    cv::Mat result_image;
    double distance;
};
// 定义每个像素对应的毫米数
const double MMPIXEL = 17.5 / 4032;
// 计算两点间距离的函数
double two_point_distance(cv::Point point1, cv::Point point2);

// 计算刹车片关键尺寸的函数
DistanceResult calculate_length(const cv::Mat &image);
