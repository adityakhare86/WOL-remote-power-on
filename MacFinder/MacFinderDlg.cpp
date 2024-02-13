//////////////////////////////////////////////////////////////////////////////
//						Designed and Implemented By Hamed M.				//
//			dedicated to all merciful members of: www.CodeProject.com		//
//																			//
//				You can use this code for free anywhere you want.			//
//																			//
//					This program is provided as is and						//
//		I'm NOT responsible for any damages witch this code may cause to	//
//		you, your Computer, Car, House,... even if it killed your dog, made //
//							your dog to bite you or even...					//
//////////////////////////////////////////////////////////////////////////////


// MacFinderDlg.cpp : implementation file
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
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMacFinderDlg dialog

CMacFinderDlg::CMacFinderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMacFinderDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMacFinderDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMacFinderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMacFinderDlg)
	DDX_Control(pDX, IDC_NIC_MAC_LIST, m_macList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMacFinderDlg, CDialog)
	//{{AFX_MSG_MAP(CMacFinderDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMacFinderDlg message handlers

BOOL CMacFinderDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	GetMacAddress();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMacFinderDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMacFinderDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

HCURSOR CMacFinderDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMacFinderDlg::OnOK() 
{
	CDialog::OnOK();
}

CString CMacFinderDlg::GetMacAddress()
{
	//Function added to dll as a resource (I guess!!)
	hIpHlpApi = LoadLibrary(_T("iphlpapi.dll"));

	//Finding function
	m_pGetAdaptersInfo = 
		(lpfnGetAdaptersInfo)GetProcAddress(hIpHlpApi,"GetAdaptersInfo" );

	//if it can't be found
	if (!hIpHlpApi) {
		AfxMessageBox(_T("Unable to link to module"));
		return "";
	}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//This part is a modified version of Mr.Khalid Shaikh from code guru. Below link
//http://www.codeguru.com/Cpp/I-N/network/networkinformation/article.php/c5451

	//Parts with (*)His code, (+)His code + my changes (m) My codes


	IP_ADAPTER_INFO AdapterInfo[16];       // Allocate information			(*)
											 // for up to 16 NICs			(*)
	DWORD dwBufLen = sizeof(AdapterInfo);  // Save memory size of buffer	(*)

	DWORD dwStatus = m_pGetAdaptersInfo(      // Call GetAdapterInfo		(+)
	  AdapterInfo,                 // [out] buffer to receive data			(*)
	  &dwBufLen);                  // [in] size of receive data buffer		(*)
	ASSERT(dwStatus == ERROR_SUCCESS);  // Verify return value is			(*)
										// valid, no buffer overflow		(*)

	PIP_ADAPTER_INFO pAdapterInfo = AdapterInfo; // Contains pointer to
												 // current adapter info
												// current adapter info
	CString mac = _T("");												//	(m)
	//If you found any MIC at all
	if (!pAdapterInfo) return _T("");									//  (m)
	do {																//  (*)

		//A temporary string
		CString str;													//  (m)
		//If we encountered an error,However i think it					//  (m)
		//Might be impossible to encounter an error here				//  (m)
		if (pAdapterInfo->Address==NULL) return _T("");					//  (m)
		
		//Convert 6 Bytes from Hex. to String and add to list ctrl.		//	(m)
		for (int i=0;i<6;i++) {											//  (m)
			str.Format(_T("%x"),*(pAdapterInfo->Address+i));			//  (+)
			//We must have 2 charachters but last line converts
			//Say 0f to f so we should return back 0. we could use
			//%2x but instead of 0 we had blank, then.
			if (str.GetLength()<2) str = _T("0") + str;					//  (m)
			//Add dashes between characters
			if (i<5) str+=_T(" - ");									//  (m)
			mac += str;													//  (m)
		}																//  (*)  ;)
		m_macList.AddString(mac);										//  (m)
		//Reset our mac str variable.
		mac = _T("");													//  (m)
		//look for next NICs if there are any.
		pAdapterInfo = pAdapterInfo->Next;    // Progress through		//  (*)
												// linked list
	} while(pAdapterInfo);// Terminate if last adapter						(*)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 	FreeLibrary(hIpHlpApi);
	return mac;
}
