// MacFinder.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "MacFinder.h"
#include "MacFinderDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMacFinderApp

BEGIN_MESSAGE_MAP(CMacFinderApp, CWinApp)
	//{{AFX_MSG_MAP(CMacFinderApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMacFinderApp construction

CMacFinderApp::CMacFinderApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMacFinderApp object

CMacFinderApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CMacFinderApp initialization

BOOL CMacFinderApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CMacFinderDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
