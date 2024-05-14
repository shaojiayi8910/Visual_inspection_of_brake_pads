#include"basefunc.h"
class ContourDetector
{
public:
    const std::string& mfilename;
    double minArea;
    cv::Mat mimage;
public:
    ContourDetector(const std::string& filename,double minAreaThreshold);
    void  detectContours();
};


