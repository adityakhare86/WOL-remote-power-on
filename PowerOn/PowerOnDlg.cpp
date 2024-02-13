// PowerOnDlg.cpp : implementation file
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
// CPowerOnDlg dialog

CPowerOnDlg::CPowerOnDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPowerOnDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPowerOnDlg)
	m_mac1 = _T("");
	m_mac2 = _T("");
	m_mac3 = _T("");
	m_mac4 = _T("");
	m_mac5 = _T("");
	m_mac6 = _T("");
	m_port = _T("");
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPowerOnDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPowerOnDlg)
	DDX_Text(pDX, IDC_MAC_1, m_mac1);
	DDV_MaxChars(pDX, m_mac1, 2);
	DDX_Text(pDX, IDC_MAC_2, m_mac2);
	DDV_MaxChars(pDX, m_mac2, 2);
	DDX_Text(pDX, IDC_MAC_3, m_mac3);
	DDV_MaxChars(pDX, m_mac3, 2);
	DDX_Text(pDX, IDC_MAC_4, m_mac4);
	DDV_MaxChars(pDX, m_mac4, 2);
	DDX_Text(pDX, IDC_MAC_5, m_mac5);
	DDV_MaxChars(pDX, m_mac5, 2);
	DDX_Text(pDX, IDC_MAC_6, m_mac6);
	DDV_MaxChars(pDX, m_mac6, 2);
	DDX_Text(pDX, IDC_PORT, m_port);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPowerOnDlg, CDialog)
	//{{AFX_MSG_MAP(CPowerOnDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_POWER_ON, OnPowerOn)
	ON_EN_CHANGE(IDC_MAC_1, OnChangeMac1)
	ON_EN_CHANGE(IDC_MAC_2, OnChangeMac2)
	ON_EN_CHANGE(IDC_MAC_3, OnChangeMac3)
	ON_EN_CHANGE(IDC_MAC_4, OnChangeMac4)
	ON_EN_CHANGE(IDC_MAC_5, OnChangeMac5)
	ON_EN_CHANGE(IDC_MAC_6, OnChangeMac6)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPowerOnDlg message handlers

BOOL CPowerOnDlg::OnInitDialog()
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
	
	// --------------------------------------------
	//Initialization
	
	//This API MUST be called at the beginning of each thread, who wants to use sockets.
//	AfxSocketInit();

	m_port = _T("40000");
	m_mac1 = _T("00");
	m_mac2 = _T("04");
	m_mac3 = _T("61");
	m_mac4 = _T("71");
	m_mac5 = _T("1a");
	m_mac6 = _T("8b");
	UpdateData(FALSE);
	// --------------------------------------------
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPowerOnDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPowerOnDlg::OnPaint() 
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

HCURSOR CPowerOnDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPowerOnDlg::OnOK() 
{
	//Disable Enter->Exit!
//	CDialog::OnOK();
}

void CPowerOnDlg::OnCancel() 
{
	CDialog::OnCancel();
}

//----------------------------------------------
//Turns on the remote computer
void CPowerOnDlg::OnPowerOn() 
{
	//User Input
	UpdateData(TRUE);
	//Socket to send magic packet
	CAsyncSocket s;
	//Buffer for packet
	BYTE magicP[102];

	//Validate Input data
	if ( m_mac1==_T("") || m_mac2==_T("") || m_mac3==_T("") ||
		 m_mac4==_T("") || m_mac5==_T("") || m_mac6==_T("")) {
		AfxMessageBox(_T("You should fill in all fields"));
		return;
	}
	//Create a string containing all numbers (12 charachter)
	CString macAddr = m_mac1+m_mac2+m_mac3+m_mac4+m_mac5+m_mac6;

//   Fill in magic packet with 102 Bytes of data
	//Header
	//fill 6 Bytes with 0xFF
	for (int i=0;i<6;i++)
		magicP[i] = 0xff;

	//First 6 bytes (these must be repeated!!)
	//fill bytes 6-12
	for (i=0;i<6;i++) {
		//Get 2 charachters from mac address and convert it to int to fill
		//magic packet
		magicP[i+6] = HexStrToInt(macAddr.Mid(i*2,2));
	}

	//fill remaining 90 bytes (15 time repeat)
	//Warning : It is higly recommended not to use functions like
	//memcpy, read MSDN for more details.
	for (i=0;i<15;i++) memcpy(&magicP[(i+2)*6],&magicP[6],6);

	//Create a socket to send data
	s.Create(atol(m_port),SOCK_DGRAM);
	//Customize socket to BROADCAST
	BOOL bOptVal = TRUE;
	if (s.SetSockOpt(SO_BROADCAST,(char*)&bOptVal,sizeof(BOOL))==SOCKET_ERROR) 
		return;
	
	//Broadcast Magic Packet, Hope appropriate NIC will take it ;)
	s.SendTo(magicP,102,atol(m_port));

	TRACE(_T("Magic packet sent.Remote computer should turn on now."));

	//Close the socket and release all buffers
	s.Close();
}

//----------------------------------------------
//Converts a hexadecimal number to an integer, Ex.: "0xff"->255
UINT CPowerOnDlg::HexStrToInt(CString hexStr)
{
	char *stop;
	char  num[3];
	UINT res = 0;

	//Nothing happens if return 0, just server will not wakeup
	if (hexStr.GetLength()>2) {
		TRACE(_T("(Length) Invalid Input!"));
		return 0;		//or perhaps exit;
	}

	memset(num,'\0',3);

	//In Unicode it's: wcscpy
	strcpy(num,hexStr);
	//In Unicode it's: wcstol
	res = strtol(num,&stop,16);

	if (res==LONG_MAX || res==LONG_MIN || res==0) {
		TRACE(_T("(OverFlow) Invalid Input!"));
		return 0;		//or perhaps exit;
	}
	
	return res;
}
//----------------------------------------------
//Functions below has nothing to do with WOL
//----------------------------------------------

void CPowerOnDlg::OnChangeMac1() 
{
	UpdateData(TRUE);
	if (m_mac1.GetLength()==2) ManageFocus();
}

void CPowerOnDlg::OnChangeMac2() 
{
	UpdateData(TRUE);
	if (m_mac2.GetLength()==2) ManageFocus();
}

void CPowerOnDlg::OnChangeMac3() 
{
	UpdateData(TRUE);
	if (m_mac3.GetLength()==2) ManageFocus();
}

void CPowerOnDlg::OnChangeMac4() 
{
	UpdateData(TRUE);
	if (m_mac4.GetLength()==2) ManageFocus();
}

void CPowerOnDlg::OnChangeMac5() 
{
	UpdateData(TRUE);
	if (m_mac5.GetLength()==2) ManageFocus();
}

void CPowerOnDlg::OnChangeMac6() 
{
	UpdateData(TRUE);
	if (m_mac6.GetLength()==2) ManageFocus();
}

void CPowerOnDlg::ManageFocus()
{
	CWnd* wN = GetNextDlgTabItem(GetFocus());
	wN->SetFocus();
	wN->SendMessage(EM_SETSEL,0,1024);
}
