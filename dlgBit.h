#ifndef DLGBIT_H
#define DLGBIT_H

//(*Headers(dlgBit)
#include <wx/dialog.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/sizer.h>
//*)

class dlgBit: public wxDialog
{
	public:

		dlgBit(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~dlgBit();

		//(*Declarations(dlgBit)
		wxNotebook* nbkMain;
		wxPanel* Panel1;
		wxPanel* Panel2;
		//*)

	protected:

		//(*Identifiers(dlgBit)
		static const long ID_PANEL1;
		static const long ID_PANEL2;
		static const long ID_NOTEBOOK1;
		//*)

	private:

		//(*Handlers(dlgBit)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
