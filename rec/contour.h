#include <opencv2/opencv.hpp>

class ContourDetector {
private:
    cv::Mat image;
    double minArea;

public:
    ContourDetector(const std::string& filename, double minAreaThreshold);
    void detectContours();

};
