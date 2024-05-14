#include <opencv2/opencv.hpp>
#include<iostream>
#include"contour.h"
int main()
{


    // 创建 ContourDetector 对象
    ContourDetector contourDetector("2.jpg",170.00);
    // 检测轮廓
    cv::Mat contour_image = contourDetector.detectContours();
        // 显示包含轮廓的图像
    cv::namedWindow("Contours on Original Image", cv::WINDOW_NORMAL);
    cv::imshow("Contours on Original Image", contour_image);
    cv::waitKey(0);
    return 0;
}
