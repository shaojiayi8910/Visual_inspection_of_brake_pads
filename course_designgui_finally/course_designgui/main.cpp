#include <opencv2/opencv.hpp>
#include<iostream>
#include"contour.h"
#include"circle.h"
using namespace std;
using namespace cv;
int main()
{

    // 创建 ContourDetector 对象
    ContourDetector contourDetector("2.jpg",170.00);
    // 检测轮廓
    contourDetector.detectContours();
        // 显示包含轮廓的图像
    cv::namedWindow("Contours on Original Image", cv::WINDOW_NORMAL);
    cv::imshow("Contours on Original Image", contourDetector.mimage);

    //////////////////圆孔距离的检测
    cv::Mat image = cv::imread("2.jpg");
    if (image.empty()) {
        std::cerr << "Failed to load image." << std::endl;
        return -1;
    }

    // 创建圆检测器对象
    CircleDetector detector;

    // 检测圆孔
    detector.detectCircles(image);

    // 绘制检测到的圆
    detector.drawDetectedCircles(image);

    // 计算每厘米的像素数
    double pixelsPerCm = detector.calculatePixelsPerCm();

    // 计算标尺的实际距离
    double circleDiameterInCm = detector.calculateDistance(detector.getCircleCenter1(), detector.getCircleCenter2()) / pixelsPerCm;

    std::cout << "Circle diameter in cm: " << circleDiameterInCm << std::endl;

    // 显示图像
    cv::namedWindow("Detected Circles", cv::WINDOW_NORMAL);
    cv::imshow("Detected Circles", image);

    waitKey(0);
    return 0;


}
