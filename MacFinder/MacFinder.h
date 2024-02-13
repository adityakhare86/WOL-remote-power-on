// MacFinder.h : main header file for the MACFINDER application
//

#if !defined(AFX_MACFINDER_H__B62D2A01_B9C3_477B_BFB5_8B21A26D659D__INCLUDED_)
#define AFX_MACFINDER_H__B62D2A01_B9C3_477B_BFB5_8B21A26D659D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMacFinderApp:
// See MacFinder.cpp for the implementation of this class
//

class CMacFinderApp : public CWinApp
{
public:
	CMacFinderApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMacFinderApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMacFinderApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MACFINDER_H__B62D2A01_B9C3_477B_BFB5_8B21A26D659D__INCLUDED_)
