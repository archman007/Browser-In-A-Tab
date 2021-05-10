/***************************************************************
 * Name:      bitProjApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Mr. Arch Brooks (arch@archbrooks.com)
 * Created:   Mon May 10 08:44:06 2021
 * Copyright: Mr. Arch Brooks (archbrooks.us/b4)
 * License:
 **************************************************************/

#include "bitProjApp.h"

//(*AppHeaders
#include "bitProjMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(bitProjApp);

bool bitProjApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	bitProjFrame* Frame = new bitProjFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
