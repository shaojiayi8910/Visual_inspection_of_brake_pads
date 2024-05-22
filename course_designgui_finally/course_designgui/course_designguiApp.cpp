/***************************************************************
 * Name:      course_designguiApp.cpp
 * Purpose:   Code for Application Class
 * Author:    01 (01)
 * Created:   2024-05-14
 * Copyright: 01 (01)
 * License:
 **************************************************************/

#include "course_designguiApp.h"

//(*AppHeaders
#include "course_designguiMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(course_designguiApp);

bool course_designguiApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
        course_designguiDialog Dlg(NULL);
        SetTopWindow(&Dlg);
        Dlg.ShowModal();
        wxsOK = false;
    }
    //*)
    return wxsOK;

}
