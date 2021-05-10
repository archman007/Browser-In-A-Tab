/***************************************************************
 * Name:      bitProjMain.h
 * Purpose:   Defines Application Frame
 * Author:    Mr. Arch Brooks (arch@archbrooks.com)
 * Created:   Mon May 10 08:44:06 2021
 * Copyright: Mr. Arch Brooks (archbrooks.us/b4)
 * License:
 **************************************************************/

#ifndef BITPROJMAIN_H
#define BITPROJMAIN_H
#include <wx/textctrl.h>

//(*Headers(bitProjFrame)
#include <wx/colordlg.h>
#include <wx/fontdlg.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
//*)

using namespace std;

class bitProjFrame: public wxFrame
{
public:
    bitProjFrame(wxWindow* parent,wxWindowID id = -1);
    virtual ~bitProjFrame();

private:
    string GetText(bool memo, string initVal, string prompt, string caption);
    string GetFileName(string fs);
    string defPath = "";
    string fno = "";
    string fileName = "";
    string SelDir(string initDir);
    void initField(string inputValue, wxTextCtrl * field);
    string fieldToString(wxTextCtrl * field);
    void Xqt(string cmd);
    void ListFilesRecursively(const char *dir, const char* ext);
    wxArrayString strings;
    int yornQues(string caption, string prompt);
    wxColourData colour_data = wxColourData();

    //(*Handlers(bitProjFrame)
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnmenXqtOneSelected(wxCommandEvent& event);
    void OnmenFontsSelected(wxCommandEvent& event);
    void OnmenColorSelected(wxCommandEvent& event);
    //*)

    //(*Identifiers(bitProjFrame)
    static const long ID_PANEL1;
    static const long ID_MENUITEM1;
    static const long idMenuQuit;
    static const long ID_MENUITEM2;
    static const long ID_MENUITEM3;
    static const long idMenuAbout;
    static const long ID_STATUSBAR1;
    //*)

    //(*Declarations(bitProjFrame)
    wxColourDialog* ColourDialog1;
    wxFontDialog* FontDialog1;
    wxMenu* Menu3;
    wxMenuItem* menColor;
    wxMenuItem* menFonts;
    wxMenuItem* menXqtOne;
    wxPanel* pan01;
    wxStatusBar* StatusBar1;
    //*)

    DECLARE_EVENT_TABLE()
};

#endif // BITPROJMAIN_H
