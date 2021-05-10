#include "dlgBit.h"

//(*InternalHeaders(dlgBit)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(dlgBit)
const long dlgBit::ID_PANEL1 = wxNewId();
const long dlgBit::ID_PANEL2 = wxNewId();
const long dlgBit::ID_NOTEBOOK1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(dlgBit,wxDialog)
	//(*EventTable(dlgBit)
	//*)
END_EVENT_TABLE()

dlgBit::dlgBit(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(dlgBit)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, _("Dialog For Browser In Tab"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	nbkMain = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxSize(597,285), wxNB_BOTTOM, _T("ID_NOTEBOOK1"));
	Panel1 = new wxPanel(nbkMain, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Panel2 = new wxPanel(nbkMain, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	nbkMain->AddPage(Panel1, _("Primary Options"), false);
	nbkMain->AddPage(Panel2, _("Web Browser"), false);
	BoxSizer3->Add(nbkMain, 1, wxALL|wxEXPAND, 5);
	BoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	Center();
	//*)
}

dlgBit::~dlgBit()
{
	//(*Destroy(dlgBit)
	//*)
}

