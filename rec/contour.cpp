#include"contour.h"


ContourDetector::ContourDetector(const std::string& filename, double minAreaThreshold) : minArea(minAreaThreshold)
{
    // 读取图像
    image = cv::imread(filename);
    if (image.empty())
    {
        std::cerr << "Error: Unable to read image file " << filename << std::endl;
    }
}

cv:: Mat ContourDetector:: detectContours()//检测轮并绘制
{
    // 检查图像是否为空
    if (image.empty()) {
        std::cerr << "Error: Image is empty." << std::endl;
        return cv::Mat();
    }

    // 将图像转换为灰度图像
    cv::Mat grayImage;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
    cv::namedWindow("grayImage", cv::WINDOW_NORMAL);
    cv::imshow("grayImage", grayImage);
    // 对灰度图像进行阈值处理
    cv::Mat binaryImage;
    cv::threshold(grayImage, binaryImage, 140, 255, cv::THRESH_BINARY_INV);
    cv::namedWindow("binaryImage", cv::WINDOW_NORMAL);
    cv::imshow("binaryImage", binaryImage);
    // 查找轮廓
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(binaryImage, contours, cv::RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE);

    // 在原始图像上绘制大于阈值的轮廓
    for (size_t i = 0; i < contours.size(); ++i) {
        double area = cv::contourArea(contours[i]);
        if (area >= minArea) {
            cv::drawContours(image, contours, static_cast<int>(i), cv::Scalar(0, 255, 0), 2);
        }
    }

    return image;
}


