#include"ProcessImage.h"

class ContourDetector : public ProcessImage
{
private:
    double minArea;
public:
    ContourDetector(const std::string& filename,double minAreaThreshold);
    cv::Mat detectContours();
};


