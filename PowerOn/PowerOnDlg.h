// PowerOnDlg.h : header file
//

#if !defined(AFX_POWERONDLG_H__A4490FD7_E320_4EDE_998F_6106A94643C5__INCLUDED_)
#define AFX_POWERONDLG_H__A4490FD7_E320_4EDE_998F_6106A94643C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPowerOnDlg dialog

class CPowerOnDlg : public CDialog
{
// Construction
public:
	CPowerOnDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPowerOnDlg)
	enum { IDD = IDD_POWERON_DIALOG };
	CString	m_mac1;
	CString	m_mac2;
	CString	m_mac3;
	CString	m_mac4;
	CString	m_mac5;
	CString	m_mac6;
	CString	m_port;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPowerOnDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPowerOnDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnPowerOn();
	afx_msg void OnChangeMac1();
	afx_msg void OnChangeMac2();
	afx_msg void OnChangeMac3();
	afx_msg void OnChangeMac4();
	afx_msg void OnChangeMac5();
	afx_msg void OnChangeMac6();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ManageFocus();
	UINT HexStrToInt(CString hexStr);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POWERONDLG_H__A4490FD7_E320_4EDE_998F_6106A94643C5__INCLUDED_)
