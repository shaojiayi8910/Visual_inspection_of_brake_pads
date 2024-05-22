#ifndef RUST_DETECTION_HPP
#define RUST_DETECTION_HPP

#include <opencv2/opencv.hpp>

void detectRust(const cv::Mat& src, double& totalArea);

#endif // RUST_DETECTION_HPP
