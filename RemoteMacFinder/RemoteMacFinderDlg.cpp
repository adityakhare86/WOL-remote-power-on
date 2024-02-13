// RemoteMacFinderDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RemoteMacFinder.h"
#include "RemoteMacFinderDlg.h"

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
// CRemoteMacFinderDlg dialog

CRemoteMacFinderDlg::CRemoteMacFinderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRemoteMacFinderDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRemoteMacFinderDlg)
	m_hostName = _T("");
	m_foundHost = _T("");
	m_foundIP = _T("");
	m_foundMac = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRemoteMacFinderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRemoteMacFinderDlg)
	DDX_Control(pDX, IDC_IP_ADDRESS, m_ipAddress);
	DDX_Text(pDX, IDC_HOST_NAME, m_hostName);
	DDX_Text(pDX, IDC_F_HOST, m_foundHost);
	DDX_Text(pDX, IDC_F_IP, m_foundIP);
	DDX_Text(pDX, IDC_F_MAC, m_foundMac);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRemoteMacFinderDlg, CDialog)
	//{{AFX_MSG_MAP(CRemoteMacFinderDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_FIND, OnFind)
	ON_BN_CLICKED(IDC_BY_NAME, OnByName)
	ON_BN_CLICKED(IDC_BY_IP, OnByIp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRemoteMacFinderDlg message handlers

BOOL CRemoteMacFinderDlg::OnInitDialog()
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	//------------------------------------------------------------------------ My Initializations
	//Check first radio button in group
	CheckRadioButton(IDC_BY_NAME,IDC_BY_IP,IDC_BY_NAME);
	//Disable the other control
	GetDlgItem(IDC_IP_ADDRESS)->EnableWindow(FALSE);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRemoteMacFinderDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRemoteMacFinderDlg::OnPaint() 
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

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRemoteMacFinderDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//------------------------------------------------------------------------My job starts here!
void CRemoteMacFinderDlg::OnOK() 
{
//	CDialog::OnOK();
}

void CRemoteMacFinderDlg::OnCancel() 
{
	//Some cleanup!!
	CDialog::OnCancel();
}

//Start finding
void CRemoteMacFinderDlg::OnFind() 
{
	if (!ValidateInput()) return;
	GetDlgItem(IDC_TEXT)->SetWindowText(_T("Searching, Please wait..."));
	hostent* remoteHost;

	if (GetDlgItem(IDC_HOST_NAME)->IsWindowEnabled()) {		//if name field is enabled (=selected)
		remoteHost = gethostbyname(m_hostName);				//We have to find info by Name
		if (remoteHost)
			gethostbyaddr((char*)*remoteHost->h_addr_list, 4, AF_INET);		//Update ARP Table
	} else {												//We have to find it by IP.
		DWORD	addr;
		m_ipAddress.GetAddress(addr);						//Retreive address from addr. 
															//control on the dialog.
		addr = ntohl(addr);									//GetAddress gives us bytes in 
															//reverse order!
		remoteHost = gethostbyaddr((char *) &addr, 4, AF_INET);
	}

	if (WSAGetLastError() != 0) {							//Some error around!
		if (WSAGetLastError() == 11001)
			AfxMessageBox("Host not found...");
		else {
				CString str;
				str.Format("Error #%ld",WSAGetLastError());
				AfxMessageBox(str);
		}
		GetDlgItem(IDC_TEXT)->SetWindowText(_T("Sorry!,No matches found.\nPlease check your input information and try again."));
		return;
	}

	//We got the host name here!
	if (remoteHost->h_name) m_foundHost = remoteHost->h_name;
	//And the host IP here!
	if (remoteHost->h_addr_list) {
		m_foundIP = inet_ntoa (*(struct in_addr *)*remoteHost->h_addr_list);
	}
	//Lets find MAC now!
	//WARNING: DON'T Call this function alone, It will not work because ARP table will be
	//created temporaryly by OS and this function uses that table!. 
	//Here we created table by calling 'gethostbyaddr' function.
	m_foundMac = FindRemoteMAC(m_foundIP);

	GetDlgItem(IDC_TEXT)->SetWindowText(_T("Congratulations! I found something :)"));
	UpdateData(FALSE);
}
//Find by name, radio
void CRemoteMacFinderDlg::OnByName() 
{
	GetDlgItem(IDC_HOST_NAME)->EnableWindow(TRUE);			//Do some enable/disable play!!!
	GetDlgItem(IDC_IP_ADDRESS)->EnableWindow(FALSE);
	GetDlgItem(IDC_HOST_NAME)->SetFocus();					//Give focus to edit box so that 
															//app. is ready for user!

}
//Find by IP, radio
void CRemoteMacFinderDlg::OnByIp() 
{
	GetDlgItem(IDC_HOST_NAME)->EnableWindow(FALSE);			//Just like above
	GetDlgItem(IDC_IP_ADDRESS)->EnableWindow(TRUE);
	GetDlgItem(IDC_IP_ADDRESS)->SetFocus();
}
//Check and find errors, and inform user about them
BOOL CRemoteMacFinderDlg::ValidateInput()
{
	UpdateData(TRUE);

	if (GetDlgItem(IDC_HOST_NAME)->IsWindowEnabled()) {		//if name field is enabled (=selected)
		if (m_hostName.GetLength()==0) {					//if name field is empty entered
			AfxMessageBox(_T("Please fill in name field with remote computers Host name."));
			return FALSE;
		} else return TRUE;									//if a name entered
	} else {												//if IP field is enabled (=selected)
		if (m_ipAddress.IsBlank()) {					//if name field is empty entered
			AfxMessageBox(_T("Please fill in IP field with remote computers IP."));
			return FALSE;
		} else return TRUE;									//if IP entered
		return TRUE;
	}
}

	//WARNING: DON'T Call this function alone, It will not work because ARP table will be
	//created temporaryly by OS and this function uses that table!. 
	//Here we created table by calling 'gethostbyaddr' function.

//Gets an IP as input (like: _T("192.168.1.5") ) and returns relevant MAC
//like( _T("00 - 03 - ff - 49 - 4f - 50") )
CString CRemoteMacFinderDlg::FindRemoteMAC(CString IP)
{
	DWORD dwRetVal;
	PMIB_IPNETTABLE pIPNetTable;
	DWORD dwSize = 0;
	CString res =_T(""),
			strTmp=_T("");

	if (IP==_T("127.0.0.1")) return _T("Can't return local MAC address! Use 'MacFinder' from 'www.CodeProject.com' instead.");
	//Function added to dll as a resource (I guess!!)
	hIpHlpApi = LoadLibrary(_T("iphlpapi.dll"));

	//Finding function
	m_pGetIpNetTable = 
		(lpfnGetIpNetTable)GetProcAddress(hIpHlpApi,"GetIpNetTable");

	//if it can't be found
	if (!hIpHlpApi) {
		AfxMessageBox(_T("Unable to link to module"));
		goto RET;
	}

	pIPNetTable = (MIB_IPNETTABLE*) malloc( sizeof( MIB_IPNETTABLE) );

	// Make an initial call to GetIpAddrTable to get the
	// necessary size into the dwSize variable
	if ( (dwRetVal=m_pGetIpNetTable(pIPNetTable, &dwSize, 0)) == ERROR_INSUFFICIENT_BUFFER) {
	  free( pIPNetTable );
	  pIPNetTable = (MIB_IPNETTABLE *) malloc ( dwSize );
	} else {
		CString strErr;
		LPVOID lpMsgBuf;
		switch(dwRetVal) {
			case ERROR_INVALID_PARAMETER: AfxMessageBox(_T("unable to write to memory.")); break;
			case ERROR_NOT_SUPPORTED: AfxMessageBox(_T("This function is not supported on the operating system in use on the local system.")); break;
			default: {
				if (!FormatMessage( 
					FORMAT_MESSAGE_ALLOCATE_BUFFER | 
					FORMAT_MESSAGE_FROM_SYSTEM | 
					FORMAT_MESSAGE_IGNORE_INSERTS,
					NULL,
					WSAGetLastError(),
					MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
					(LPTSTR) &lpMsgBuf,
					0,
					NULL ))	{   // Handle this error.in error handling!!! your self please.
								goto RET;
				}
				AfxMessageBox((LPCTSTR)lpMsgBuf);
				LocalFree( lpMsgBuf );
			}//default
		}//switch
	}//else

	// Make a second call to GetIpAddrTable to get the
	// actual data we want
	if ( (dwRetVal = m_pGetIpNetTable( pIPNetTable, &dwSize, 0 )) == NO_ERROR ) {
		for (UINT i=0;i<pIPNetTable->dwNumEntries;i++) {
			if ((pIPNetTable->table[i].dwAddr) == inet_addr(IP)) {
				BYTE *pt = (BYTE*)&pIPNetTable->table[i].bPhysAddr;
				for (int j=0;j<6;j++) {
					strTmp.Format("%02x",*pt++);
					res+=strTmp;
					if (j<5) res+=" - ";
				}
				goto RET;
			}
		}
	} else {
		CString strErr;
		switch(dwRetVal) {
			case ERROR_INVALID_PARAMETER: AfxMessageBox(_T("unable to write to memory.")); break;
			case ERROR_NOT_SUPPORTED: AfxMessageBox(_T("This function is not supported on the operating system in use on the local system.")); break;
			default: {
				TRACE(_T("\nError:  %d\n"),GetLastError());
				goto RET;
			}
		}
	}
RET:;
	//Cleanup
	free( pIPNetTable );
	FreeLibrary(hIpHlpApi);
	pIPNetTable = NULL;
	return res;
}
