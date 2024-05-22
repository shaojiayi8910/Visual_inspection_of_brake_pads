#include "ImageAnnotator.h"

void ImageAnnotator::annotateImage(cv::Mat& image, const std::string& recognizedText) {
    int textHeight = 40; // 文本高度
    int margin = 10;     // 边距

    // 在原始图像上标注前五个字符，左上角
    cv::putText(image, recognizedText.substr(0, 5), cv::Point(margin + 100, textHeight + 1000), cv::FONT_HERSHEY_SIMPLEX, 2, cv::Scalar(0, 0, 255), 8);

    // 在原始图像上标注最后七个字符，右上角
    cv::putText(image, recognizedText.substr(recognizedText.length() - 6, 5), cv::Point((image.cols - textHeight * 3 - margin) - 200, textHeight + 700), cv::FONT_HERSHEY_SIMPLEX, 2, cv::Scalar(0, 0, 255), 8);
}

