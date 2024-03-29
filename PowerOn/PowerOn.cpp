// PowerOn.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "PowerOn.h"
#include "PowerOnDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPowerOnApp

BEGIN_MESSAGE_MAP(CPowerOnApp, CWinApp)
	//{{AFX_MSG_MAP(CPowerOnApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPowerOnApp construction

CPowerOnApp::CPowerOnApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CPowerOnApp object

CPowerOnApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CPowerOnApp initialization

BOOL CPowerOnApp::InitInstance()
{
	AfxEnableControlContainer();

	if(!AfxSocketInit())
		  AfxMessageBox("Failed to Initialize Sockets",MB_OK| MB_ICONSTOP);
	// Standard initialization

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CPowerOnDlg dlg;
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
