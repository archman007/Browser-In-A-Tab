/***************************************************************
 * Name:      bitProjMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Mr. Arch Brooks (arch@archbrooks.com)
 * Created:   Mon May 10 08:44:06 2021
 * Copyright: Mr. Arch Brooks (archbrooks.us/b4)
 * License:
 **************************************************************/

#include "bitProjMain.h"
#include <wx/msgdlg.h>
#include <wx/textdlg.h>
#include <wx/filedlg.h>
#include <wx/dirdlg.h>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>
#include <wx/msgdlg.h>

#include <wx/dirdlg.h>
#include <wx/fontdlg.h>
//#include "kwSearch.h"
#include <wx/colordlg.h>
#include <wx/brush.h>
#include "dlgBit.h"


//(*InternalHeaders(bitProjFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

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

//(*IdInit(bitProjFrame)
const long bitProjFrame::ID_PANEL1 = wxNewId();
const long bitProjFrame::ID_MENUITEM1 = wxNewId();
const long bitProjFrame::idMenuQuit = wxNewId();
const long bitProjFrame::ID_MENUITEM2 = wxNewId();
const long bitProjFrame::ID_MENUITEM3 = wxNewId();
const long bitProjFrame::idMenuAbout = wxNewId();
const long bitProjFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(bitProjFrame,wxFrame)
    //(*EventTable(bitProjFrame)
    //*)
END_EVENT_TABLE()

bitProjFrame::bitProjFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(bitProjFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, _("Browser In A Tab"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetBackgroundColour(wxColour(0,166,255));
    pan01 = new wxPanel(this, ID_PANEL1, wxPoint(72,104), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    menXqtOne = new wxMenuItem(Menu1, ID_MENUITEM1, _("Execute Option One"), _("The Primary Option Is Here"), wxITEM_NORMAL);
    Menu1->Append(menXqtOne);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu3 = new wxMenu();
    menFonts = new wxMenuItem(Menu3, ID_MENUITEM2, _("Fonts"), _("Change Fonts Here"), wxITEM_NORMAL);
    Menu3->Append(menFonts);
    menColor = new wxMenuItem(Menu3, ID_MENUITEM3, _("Background Color"), _("Change Background Color Here"), wxITEM_NORMAL);
    Menu3->Append(menColor);
    MenuBar1->Append(Menu3, _("&Enviroment"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    	wxFontData fontData_1;
    	fontData_1.SetInitialFont(*wxNORMAL_FONT);
    FontDialog1 = new wxFontDialog(this, fontData_1);
    ColourDialog1 = new wxColourDialog(this);
    Center();

    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&bitProjFrame::OnmenXqtOneSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&bitProjFrame::OnQuit);
    Connect(ID_MENUITEM2,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&bitProjFrame::OnmenFontsSelected);
    Connect(ID_MENUITEM3,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&bitProjFrame::OnmenColorSelected);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&bitProjFrame::OnAbout);
    //*)

    dlgBit dlg(this, wxID_ANY);
    dlg.ShowModal();
    dlg.Destroy();

    wxCommandEvent event;
    OnQuit(event);

}

void bitProjFrame::OnmenXqtOneSelected(wxCommandEvent& event)
{
}

bitProjFrame::~bitProjFrame()
{
    //(*Destroy(bitProjFrame)
    //*)
}

void bitProjFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void bitProjFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

string bitProjFrame::GetText(bool memo, string initVal, string prompt, string caption)
{
    wxString wxInit;
    wxInit = initVal;
    string rval;
    if (memo)
    {
        wxTextEntryDialog dlg(this, prompt, caption, wxInit, (wxCANCEL | wxOK | wxTE_MULTILINE), wxPoint(50, 50));
        if (dlg.ShowModal() == wxID_OK)
        {
            // We can be certain that this string contains letters only.
            wxString value = dlg.GetValue();
            rval = value;
            return rval;
        }
        else
        {
            rval = "";
            return rval;
        }
    }
    else
    {
        wxTextEntryDialog dlg(this, prompt, caption, wxInit, (wxCANCEL | wxOK), wxPoint(50, 50));
        if (dlg.ShowModal() == wxID_OK)
        {
            // We can be certain that this string contains letters only.
            wxString value = dlg.GetValue();
            rval = value;
            return rval;
        }
        else
        {
            rval = "";
            return rval;
        }

    }
}

string bitProjFrame::GetFileName(string fs)
{
    wxFileDialog openFileDialog(this, _("Open Any file"), defPath, fno, fs, wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    if (openFileDialog.ShowModal() == wxID_CANCEL)
    {
        fileName = " ";
    }
    else
    {
        fileName = openFileDialog.GetPath();
    }

    return fileName;

}

std::string bitProjFrame::SelDir(string initDir)
{
    string selDir;
    wxDirDialog dlg(NULL, "Choose input directory", initDir, wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);
    if (dlg.ShowModal() == wxID_OK)
    {
        selDir = dlg.GetPath().ToStdString();
        return selDir;

    }
    dlg.Destroy();

}

void bitProjFrame::initField(string inputValue, wxTextCtrl * field)
{
    wxString dv = inputValue;
    field->Clear();
    field->SetEditable(true);
    field->ChangeValue(dv);
}

string bitProjFrame::fieldToString(wxTextCtrl * field)
{
    string rstr;
    wxString s1 = field->GetValue();
    rstr = s1.ToStdString();
    return rstr;
}

void bitProjFrame::Xqt(string cmd)
{
    cmd = cmd + " & ";
    int idet = -1;
    if ( boost::filesystem::exists( "/home/archbrooks" ) )
    {
        string frst = "/archman/";
        idet = cmd.find(frst);
        if (idet != -1)
        {
            boost::replace_all(cmd, "/archman/", "/archbrooks/");
        }
    }
    const char * c = cmd.c_str();
    int retval = -1;
    retval = system(c);
}

void bitProjFrame::ListFilesRecursively(const char *dir, const char* ext)
{
    strings.Clear();
    boost::filesystem::recursive_directory_iterator rdi(dir);
    boost::filesystem::recursive_directory_iterator end_rdi;

    std::string buf = "";

    std::string ext_str0(ext);
    for (; rdi != end_rdi; rdi++)
    {
        //rdi++;

        if (ext_str0.compare((*rdi).path().extension().string()) == 0)
        {
            buf = (*rdi).path().string();
            strings.Add(buf);
            std::cout << (*rdi).path().string() << std::endl;
        }
    }
    strings.Sort();
}

int bitProjFrame::yornQues(string caption, string prompt)
{
    int answer;
    answer = wxMessageBox(caption, prompt, wxYES_NO | wxCANCEL, NULL);
    return answer;
}


void bitProjFrame::OnmenFontsSelected(wxCommandEvent& event)
{
    wxFontData fontData;
    wxFont     theFont;
    wxColour   colour;

    theFont = pan01->GetFont();
    fontData.SetInitialFont(theFont);
//    colour pan01->GetForegroundColour();
//    colour = lbxCats->GetForegroundColour();
    fontData.SetColour(colour);
    fontData.SetShowHelp(true);

    wxFontDialog *dialog = new wxFontDialog(this);
//	dlgFont *dialog = new dlgFont( this, &fontData );
    if ( dialog->ShowModal() == wxID_OK )
    {
        fontData = dialog->GetFontData();
        theFont = 	fontData.GetChosenFont();
        pan01->SetFont(theFont);
        /*        lbxCats->SetFont(theFont);
                lbxCats->SetForegroundColour(fontData.GetColour());
                lbxLinks->SetFont(theFont);
                lbxLinks->SetForegroundColour(fontData.GetColour());
                */
    }

}

void bitProjFrame::OnmenColorSelected(wxCommandEvent& event)
{
    wxColourDialog dlgColour(this, &colour_data);

    if (dlgColour.ShowModal() == wxID_OK)
    {
        wxColourData retData = dlgColour.GetColourData();
        wxColour col = retData.GetColour();
        wxBrush brush(col, wxSOLID);
        pan01->SetBackgroundColour(col);

    }

}
