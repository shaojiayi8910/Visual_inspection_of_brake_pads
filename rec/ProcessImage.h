#include <opencv2/opencv.hpp>
#include<iostream>
class ProcessImage{
public:
    cv::Mat image;
    const std::string& mfilename;
public:
    ProcessImage(const std::string& filename);
    cv::Mat binaryImage();
};
