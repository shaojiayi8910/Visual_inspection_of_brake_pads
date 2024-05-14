#include"ProcessImage.h"
ProcessImage:: ProcessImage(const std::string& filename) :mfilename(filename)
{
    // 读取图像
    image = cv::imread(filename);
    if (image.empty())
    {
        std::cerr << "Error: Unable to read image file " << filename << std::endl;
    }
}
cv::Mat ProcessImage:: binaryImage()
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
    return binaryImage;
}
