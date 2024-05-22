/***************************************************************
 * Name:      course_designguiMain.h
 * Purpose:   Defines Application Frame
 * Author:    01 (01)
 * Created:   2024-05-14
 * Copyright: 01 (01)
 * License:
 **************************************************************/

#ifndef COURSE_DESIGNGUIMAIN_H
#define COURSE_DESIGNGUIMAIN_H

//(*Headers(course_designguiDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/statbmp.h>
#include <wx/textctrl.h>
//*)

class course_designguiDialog: public wxDialog
{
    public:

        course_designguiDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~course_designguiDialog();

    private:

        //(*Handlers(course_designguiDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnInit(wxInitDialogEvent& event);
        void OnTextCtrl4Text(wxCommandEvent& event);
        void OnTextCtrl5Text(wxCommandEvent& event);
        void OnButton1Click1(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnTextCtrl6Text(wxCommandEvent& event);
        void OnTextCtrl9Text(wxCommandEvent& event);
        void OnTextCtrl8Text(wxCommandEvent& event);
        void OnButton1Click2(wxCommandEvent& event);
        void OnTextCtrl3Text(wxCommandEvent& event);
        void OnButton4Click(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnTextCtrl11Text(wxCommandEvent& event);
        void OnTextCtrl12Text(wxCommandEvent& event);
        void OnTextCtrl10Text(wxCommandEvent& event);
        //*)

        //(*Identifiers(course_designguiDialog)
        static const long ID_STATICBITMAP4;
        static const long ID_BUTTON2;
        static const long ID_STATICBITMAP1;
        static const long ID_STATICBITMAP2;
        static const long ID_STATICBITMAP3;
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_TEXTCTRL3;
        static const long ID_TEXTCTRL4;
        static const long ID_TEXTCTRL5;
        static const long ID_TEXTCTRL6;
        static const long ID_TEXTCTRL7;
        static const long ID_TEXTCTRL8;
        static const long ID_TEXTCTRL9;
        static const long ID_TEXTCTRL10;
        static const long ID_BUTTON1;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_TEXTCTRL11;
        static const long ID_TEXTCTRL12;
        //*)

        //(*Declarations(course_designguiDialog)
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxButton* Button4;
        wxStaticBitmap* StaticBitmap1;
        wxStaticBitmap* StaticBitmap2;
        wxStaticBitmap* StaticBitmap3;
        wxStaticBitmap* StaticBitmap4;
        wxTextCtrl* TextCtrl10;
        wxTextCtrl* TextCtrl11;
        wxTextCtrl* TextCtrl12;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl3;
        wxTextCtrl* TextCtrl4;
        wxTextCtrl* TextCtrl5;
        wxTextCtrl* TextCtrl6;
        wxTextCtrl* TextCtrl7;
        wxTextCtrl* TextCtrl8;
        wxTextCtrl* TextCtrl9;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // COURSE_DESIGNGUIMAIN_H
