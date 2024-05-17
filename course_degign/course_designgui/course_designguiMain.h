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
        //*)

        //(*Identifiers(course_designguiDialog)
        static const wxWindowID ID_BUTTON2;
        static const wxWindowID ID_STATICBITMAP1;
        static const wxWindowID ID_STATICBITMAP2;
        static const wxWindowID ID_STATICBITMAP3;
        static const wxWindowID ID_TEXTCTRL1;
        static const wxWindowID ID_TEXTCTRL2;
        static const wxWindowID ID_TEXTCTRL3;
        static const wxWindowID ID_TEXTCTRL4;
        static const wxWindowID ID_TEXTCTRL5;
        static const wxWindowID ID_TEXTCTRL6;
        static const wxWindowID ID_TEXTCTRL7;
        static const wxWindowID ID_TEXTCTRL8;
        static const wxWindowID ID_STATICBITMAP4;
        static const wxWindowID ID_TEXTCTRL9;
        static const wxWindowID ID_TEXTCTRL10;
        //*)

        //(*Declarations(course_designguiDialog)
        wxButton* Button2;
        wxStaticBitmap* StaticBitmap1;
        wxStaticBitmap* StaticBitmap2;
        wxStaticBitmap* StaticBitmap3;
        wxStaticBitmap* StaticBitmap4;
        wxTextCtrl* TextCtrl10;
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
