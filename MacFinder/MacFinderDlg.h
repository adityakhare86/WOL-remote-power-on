// MacFinderDlg.h : header file
//

#if !defined(AFX_MACFINDERDLG_H__E46973DD_3780_42CD_AB98_E9875C291365__INCLUDED_)
#define AFX_MACFINDERDLG_H__E46973DD_3780_42CD_AB98_E9875C291365__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMacFinderDlg dialog
//------------------------------------------------------
#define MAX_ADAPTER_DESCRIPTION_LENGTH  128 // arb.
#define MAX_ADAPTER_NAME_LENGTH         256 // arb.
#define MAX_ADAPTER_ADDRESS_LENGTH      8   // arb.
/*
#define DEFAULT_MINIMUM_ENTITIES        32  // arb.
#define MAX_HOSTNAME_LEN                128 // arb.
#define MAX_DOMAIN_NAME_LEN             128 // arb.
#define MAX_SCOPE_ID_LEN                256 // arb.*/
//------------------------------------------------------
class CMacFinderDlg : public CDialog
{
// Construction
public:
	CMacFinderDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMacFinderDlg)
	enum { IDD = IDD_MACFINDER_DIALOG };
	CListBox	m_macList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMacFinderDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMacFinderDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CString GetMacAddress();
//-------------------------------------------------
//Extracted from MSDN.
//-------------------------------------------------

//These declarations must be originally in Iptypes.h
//MSDN says that we must have Win XP to use them.
//I tested this on Win 98, Me, XP(sp1), 2000: It Works Fine.

	typedef struct {
		char String[4 * 4];
	} IP_ADDRESS_STRING, *PIP_ADDRESS_STRING, IP_MASK_STRING, *PIP_MASK_STRING;

	typedef struct _IP_ADDR_STRING {
		struct _IP_ADDR_STRING* Next;
		IP_ADDRESS_STRING IpAddress;
		IP_MASK_STRING IpMask;
		DWORD Context;
	} IP_ADDR_STRING, *PIP_ADDR_STRING;

	typedef struct _IP_ADAPTER_INFO {
		struct _IP_ADAPTER_INFO* Next;
		DWORD ComboIndex;
		char AdapterName[MAX_ADAPTER_NAME_LENGTH + 4];
		char Description[MAX_ADAPTER_DESCRIPTION_LENGTH + 4];
		UINT AddressLength;
		BYTE Address[MAX_ADAPTER_ADDRESS_LENGTH];
		DWORD Index;
		UINT Type;
		UINT DhcpEnabled;
		PIP_ADDR_STRING CurrentIpAddress;
		IP_ADDR_STRING IpAddressList;
		IP_ADDR_STRING GatewayList;
		IP_ADDR_STRING DhcpServer;
		BOOL HaveWins;
		IP_ADDR_STRING PrimaryWinsServer;
		IP_ADDR_STRING SecondaryWinsServer;
		time_t LeaseObtained;
		time_t LeaseExpires;
	} IP_ADAPTER_INFO, *PIP_ADAPTER_INFO;
//-------------------------------------------------
	//Try to access the function inside the dll
	typedef DWORD (WINAPI *lpfnGetAdaptersInfo)(
			PIP_ADAPTER_INFO pAdapterInfo,
			PULONG pOutBufLen
		);

	lpfnGetAdaptersInfo m_pGetAdaptersInfo;
	HMODULE hIpHlpApi;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MACFINDERDLG_H__E46973DD_3780_42CD_AB98_E9875C291365__INCLUDED_)
