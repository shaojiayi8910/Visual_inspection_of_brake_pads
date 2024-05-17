/***************************************************************
 * Name:      course_designguiMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    01 (01)
 * Created:   2024-05-14
 * Copyright: 01 (01)
 * License:
 **************************************************************/

#include "course_designguiMain.h"
#include <wx/msgdlg.h>
#include <opencv2/opencv.hpp>
#include<iostream>
#include"contour.h"
#include"circle.h"
#include "LineDistanceCalculator.h"
#include "RustDetection.h"
#include "OCRProcessor.h"
#include "ImageAnnotator.h"
#include <wx/aui/aui.h>
#include "image_processing.hpp"
using namespace std;
using namespace cv;

//(*InternalHeaders(course_designguiDialog)
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(course_designguiDialog)
const wxWindowID course_designguiDialog::ID_BUTTON2 = wxNewId();
const wxWindowID course_designguiDialog::ID_STATICBITMAP1 = wxNewId();
const wxWindowID course_designguiDialog::ID_STATICBITMAP2 = wxNewId();
const wxWindowID course_designguiDialog::ID_STATICBITMAP3 = wxNewId();
const wxWindowID course_designguiDialog::ID_TEXTCTRL1 = wxNewId();
const wxWindowID course_designguiDialog::ID_TEXTCTRL2 = wxNewId();
const wxWindowID course_designguiDialog::ID_TEXTCTRL3 = wxNewId();
const wxWindowID course_designguiDialog::ID_TEXTCTRL4 = wxNewId();
const wxWindowID course_designguiDialog::ID_TEXTCTRL5 = wxNewId();
const wxWindowID course_designguiDialog::ID_TEXTCTRL6 = wxNewId();
const wxWindowID course_designguiDialog::ID_TEXTCTRL7 = wxNewId();
const wxWindowID course_designguiDialog::ID_TEXTCTRL8 = wxNewId();
const wxWindowID course_designguiDialog::ID_STATICBITMAP4 = wxNewId();
const wxWindowID course_designguiDialog::ID_TEXTCTRL9 = wxNewId();
const wxWindowID course_designguiDialog::ID_TEXTCTRL10 = wxNewId();
//*)

BEGIN_EVENT_TABLE(course_designguiDialog,wxDialog)
    //(*EventTable(course_designguiDialog)
    //*)
END_EVENT_TABLE()


course_designguiDialog::course_designguiDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(course_designguiDialog)
    Create(parent, wxID_ANY, _("wxWidgets app"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(1215,858));
    Button2 = new wxButton(this, ID_BUTTON2, _("detect picture"), wxPoint(8,824), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxNullBitmap, wxPoint(8,0), wxSize(504,304), 0, _T("ID_STATICBITMAP1"));
    StaticBitmap1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
    StaticBitmap2 = new wxStaticBitmap(this, ID_STATICBITMAP2, wxNullBitmap, wxPoint(592,0), wxSize(592,336), 0, _T("ID_STATICBITMAP2"));
    StaticBitmap2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
    StaticBitmap3 = new wxStaticBitmap(this, ID_STATICBITMAP3, wxNullBitmap, wxPoint(8,392), wxSize(504,360), 0, _T("ID_STATICBITMAP3"));
    StaticBitmap3->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("Detected_Lines"), wxPoint(120,352), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl1->Disable();
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("Contours on Original Image"), wxPoint(648,352), wxSize(264,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextCtrl2->Disable();
    TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, _("Detected Circles"), wxPoint(136,760), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    TextCtrl3->Disable();
    TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, _("circle diameter:"), wxPoint(488,816), wxSize(160,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    TextCtrl4->Disable();
    TextCtrl5 = new wxTextCtrl(this, ID_TEXTCTRL5, _("recognizedText:"), wxPoint(864,816), wxSize(144,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    TextCtrl5->Disable();
    TextCtrl6 = new wxTextCtrl(this, ID_TEXTCTRL6, wxEmptyString, wxPoint(656,816), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    TextCtrl6->Disable();
    TextCtrl7 = new wxTextCtrl(this, ID_TEXTCTRL7, wxEmptyString, wxPoint(1024,816), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    TextCtrl7->Disable();
    TextCtrl8 = new wxTextCtrl(this, ID_TEXTCTRL8, _("Result_image"), wxPoint(744,768), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
    TextCtrl8->Disable();
    StaticBitmap4 = new wxStaticBitmap(this, ID_STATICBITMAP4, wxNullBitmap, wxPoint(584,400), wxSize(616,344), 0, _T("ID_STATICBITMAP4"));
    StaticBitmap4->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
    TextCtrl9 = new wxTextCtrl(this, ID_TEXTCTRL9, _("totalArea:"), wxPoint(184,824), wxSize(104,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL9"));
    TextCtrl9->Disable();
    TextCtrl10 = new wxTextCtrl(this, ID_TEXTCTRL10, wxEmptyString, wxPoint(304,824), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL10"));
    TextCtrl10->Disable();

    Connect(ID_BUTTON2, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&course_designguiDialog::OnButton2Click);
    Connect(ID_TEXTCTRL4, wxEVT_COMMAND_TEXT_UPDATED, (wxObjectEventFunction)&course_designguiDialog::OnTextCtrl4Text);
    Connect(ID_TEXTCTRL5, wxEVT_COMMAND_TEXT_UPDATED, (wxObjectEventFunction)&course_designguiDialog::OnTextCtrl5Text);
    Connect(ID_TEXTCTRL6, wxEVT_COMMAND_TEXT_UPDATED, (wxObjectEventFunction)&course_designguiDialog::OnTextCtrl6Text);
    Connect(wxID_ANY, wxEVT_INIT_DIALOG, (wxObjectEventFunction)&course_designguiDialog::OnInit);
    //*)


}


course_designguiDialog::~course_designguiDialog()
{
    //(*Destroy(course_designguiDialog)
    //*)
}

void course_designguiDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void course_designguiDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void course_designguiDialog::OnButton1Click(wxCommandEvent& event)
{
}

void course_designguiDialog::OnInit(wxInitDialogEvent& event)
{
}

void course_designguiDialog::OnTextCtrl4Text(wxCommandEvent& event)
{
}

void course_designguiDialog::OnTextCtrl5Text(wxCommandEvent& event)
{
}

void course_designguiDialog::OnButton1Click1(wxCommandEvent& event)
{

}

void course_designguiDialog::OnButton2Click(wxCommandEvent& event)
{
     // 创建 ContourDetector 对象
    ContourDetector contourDetector("2.jpg",120.00);
    // 检测轮廓
    contourDetector.detectContours();
    bool success = cv::imwrite("contour_image.jpg", contourDetector.mimage);
    if (!success)
        {
            std::cerr << "Failed to save image." << std::endl;
        }
    else
        {
            std::cout << "Image saved successfully." << std::endl;
        }
    // 加载指定的图片
    wxImage image_1(wxT("contour_image.jpg"), wxBITMAP_TYPE_JPEG);
    if (image_1.IsOk())
    {
        // 将图片设置到静态位图控件中
        // 获取静态位图控件的尺寸
        int width, height;
        StaticBitmap2->GetSize(&width, &height);
        // 缩放图像以适应控件的大小
        image_1.Rescale(width, height, wxIMAGE_QUALITY_HIGH);
        // 将缩放后的图像设置到静态位图控件中
        StaticBitmap2->SetBitmap(wxBitmap(image_1));
    }
  //////////////////圆孔距离的检测
    cv::Mat image = cv::imread("2.jpg");
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
    //显示到相应的控件中
    wxString strCircleDiameter;
    strCircleDiameter.Printf(wxT("%.2f cm"), circleDiameterInCm); // 使用Printf方法将double转换为字符串
    TextCtrl6->SetValue(strCircleDiameter);
    bool success_2 = cv::imwrite("circles_image.jpg", image);
    if (!success_2)
    {
        std::cerr << "Failed to save image." << std::endl;
    }
    else
    {
        std::cout << "Image saved successfully." << std::endl;
    }
    // 加载指定的图片
    wxImage image_2(wxT("circles_image.jpg"), wxBITMAP_TYPE_JPEG);
    if (image_2.IsOk())
    {
    int width, height;
    StaticBitmap3->GetSize(&width, &height);
    // 缩放图像以适应控件的大小
    image_2.Rescale(width, height, wxIMAGE_QUALITY_HIGH);
    // 将缩放后的图像设置到静态位图控件中
    StaticBitmap3->SetBitmap(wxBitmap(image_2));
    }
    cv::Mat image_3 = cv::imread("contour_image.jpg");
    LineDistanceCalculator calculator(image_3);
    cv::namedWindow("Coumpter Distance(click mouse)", cv::WINDOW_NORMAL);
    cv::imshow("Coumpter Distance(click mouse)", image_3);
    cv::setMouseCallback("Coumpter Distance(click mouse)", LineDistanceCalculator::onMouse, &calculator);
    //waitKey(0);
    cv::Mat image_original = cv::imread("shachepian.jpg");
   //字符识别
    OCRProcessor ocrProcessor("eng");
   std::string recognizedText = ocrProcessor.performOCR(image_original);
    //std::cout << "recognized string: \n" << recognizedText << std::endl;
    // 将识别文本设置到 wxTextCtrl 中
    wxString text(recognizedText);
    TextCtrl7->SetValue(text);
    // 标注识别字符在原图的位置
    ImageAnnotator::annotateImage(image_original, recognizedText);
    //计算铁锈总面积并输出
    double totalArea;
    detectRust(image_original, totalArea);
    //缩小显示字符和铁锈面积窗口的大小
    cv::namedWindow("Result_image", cv::WINDOW_NORMAL);
    cv::resizeWindow("Result_image", image_original.cols / 4, image_original.rows / 4);
    //在图片上显示字符、铁锈面积和大小
    cv::imshow("Result_image", image_original);
    wxString totalArea_str;
    totalArea_str.Printf(wxT("%.2f cm"), totalArea); // 使用Printf方法将double转换为字符串
    TextCtrl10->SetValue(totalArea_str);
    bool success_3 = cv::imwrite("Result_image.jpg", image_original);
    if (!success_3)
    {
    std::cerr << "Failed to save image." << std::endl;
    }
    else
    {
    std::cout << "Image saved successfully." << std::endl;
    }
 // 加载指定的图片
    wxImage image_4(wxT("Result_image.jpg"), wxBITMAP_TYPE_JPEG);
    if (image_4.IsOk())
    {
    int width, height;
    StaticBitmap4->GetSize(&width, &height);
    // 缩放图像以适应控件的大小
    image_4.Rescale(width, height, wxIMAGE_QUALITY_HIGH);
    // 将缩放后的图像设置到静态位图控件中
    StaticBitmap4->SetBitmap(wxBitmap(image_4));
    }
    Mat image_5 = imread("Scratch_detection.jpg");
    Mat color_image = image_5.clone(); // 复制彩色图像用于绘制直线
    // 划痕图像处理
    processImage(image_5, color_image);
    // 显示划痕
    //imshow("Detected Lines", color_image);
    bool success_4 = cv::imwrite("Detected_Lines.jpg", color_image);
    if (!success_4)
    {
    std::cerr << "Failed to save image." << std::endl;
    }
    else
    {
    std::cout << "Image saved successfully." << std::endl;
    }
    // 加载指定的图片
    wxImage image_6(wxT("Detected_Lines.jpg"), wxBITMAP_TYPE_JPEG);
    if (image_6.IsOk())
    {
    int width, height;
    StaticBitmap1->GetSize(&width, &height);
    // 缩放图像以适应控件的大小
    image_6.Rescale(width, height, wxIMAGE_QUALITY_HIGH);
    // 将缩放后的图像设置到静态位图控件中
    StaticBitmap1->SetBitmap(wxBitmap(image_6));
    }
    cv::waitKey(0);
}

void course_designguiDialog::OnTextCtrl6Text(wxCommandEvent& event)
{
}


