#include "OCRProcessor.h"
#include <leptonica/allheaders.h>

// 构造函数，初始化 Tesseract OCR 引擎
OCRProcessor::OCRProcessor(const std::string& language) {
    tess.Init(NULL, language.c_str());
}

// 析构函数，释放 Tesseract OCR 引擎的资源
OCRProcessor::~OCRProcessor() {
    tess.End();
}

// 主 OCR 处理函数，接收一个 OpenCV 图像并返回 OCR 结果
std::string OCRProcessor::performOCR(const cv::Mat& image) {
    // 对图像进行预处理
    cv::Mat processedImage = preprocessImage(image);

    // 找到目标轮廓
    std::vector<std::vector<cv::Point>> filteredContours = findTargetContours(processedImage);

    // 创建一个空白图像，用于绘制轮廓
    cv::Mat contourImage = cv::Mat::ones(processedImage.size(), CV_8UC1) * 255;
    for (size_t i = 0; i < filteredContours.size(); ++i) {
        // 将每个过滤后的轮廓绘制到图像上
        cv::drawContours(contourImage, filteredContours, static_cast<int>(i), cv::Scalar(0), cv::FILLED);
    }

    // 旋转图像 90 度（顺时针）
    cv::Mat rotatedContourImage;
    cv::rotate(contourImage, rotatedContourImage, cv::ROTATE_90_CLOCKWISE);

    // 设置 Tesseract 的输入图像
    tess.SetImage(rotatedContourImage.data, rotatedContourImage.cols, rotatedContourImage.rows, 1, rotatedContourImage.cols);

    // 获取 OCR 结果文本
    char* outText = tess.GetUTF8Text();
    std::string result(outText);
    delete[] outText;  // 释放 Tesseract 分配的内存

    // 格式化结果字符串
    std::string formattedResult;
    int length = result.length();
    if (length > 12) {
        formattedResult = result.substr(0, 5) + '\n' + result.substr(length - 7);
    } else {
        formattedResult = result;
    }

    // 去掉结果中的空格
    formattedResult.erase(std::remove(formattedResult.begin(), formattedResult.end(), ' '), formattedResult.end());

    return formattedResult;
}

// 对图像进行预处理，转换为灰度图并进行二值化处理
cv::Mat OCRProcessor::preprocessImage(const cv::Mat& inputImage) {
    cv::Mat grayImage;
    cv::cvtColor(inputImage, grayImage, cv::COLOR_BGR2GRAY);

    int thresholdValue = 44;
    cv::Mat thresholdedImage;
    cv::threshold(grayImage, thresholdedImage, thresholdValue, 255, cv::THRESH_BINARY_INV);

    int dilationSize = 1;
    // 创建结构元素用于膨胀和腐蚀操作
    cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT,
        cv::Size(2 * dilationSize + 1, 2 * dilationSize + 1),
        cv::Point(dilationSize, dilationSize));

    // 对图像进行膨胀和腐蚀操作
    cv::dilate(thresholdedImage, thresholdedImage, element);
    cv::erode(thresholdedImage, thresholdedImage, element);

    return thresholdedImage;
}

// 找到目标轮廓并进行过滤
std::vector<std::vector<cv::Point>> OCRProcessor::findTargetContours(const cv::Mat& image) {
    std::vector<std::vector<cv::Point>> contours;
    // 查找外部轮廓
    cv::findContours(image.clone(), contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    std::vector<std::vector<cv::Point>> filteredContours;
    for (size_t i = 0; i < contours.size(); ++i) {
        cv::Rect boundingRect = cv::boundingRect(contours[i]);
        int contourWidth = boundingRect.width;
        int contourHeight = boundingRect.height;
        // 根据宽度、高度、面积和长宽比过滤轮廓
        if (contourWidth >= 2 && contourWidth <= 100 &&
            contourHeight >= 10 && contourHeight <= 200) {
            double contourArea = cv::contourArea(contours[i]);
            float aspectRatio = static_cast<float>(contourHeight) / contourWidth;
            if (contourArea >= 20 && contourArea <= 20000 &&
                aspectRatio >= 0.15 && aspectRatio <= 0.7) {
                filteredContours.push_back(contours[i]);
            }
        }
    }
    return filteredContours;
}
