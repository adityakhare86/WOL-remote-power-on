// PowerOn.h : main header file for the POWERON application
//

#if !defined(AFX_POWERON_H__F1C9D41B_9762_4B24_9175_8CE9B5D9E7D6__INCLUDED_)
#define AFX_POWERON_H__F1C9D41B_9762_4B24_9175_8CE9B5D9E7D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPowerOnApp:
// See PowerOn.cpp for the implementation of this class
//

class CPowerOnApp : public CWinApp
{
public:
	CPowerOnApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPowerOnApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPowerOnApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POWERON_H__F1C9D41B_9762_4B24_9175_8CE9B5D9E7D6__INCLUDED_)
