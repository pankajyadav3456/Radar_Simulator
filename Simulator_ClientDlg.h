// Simulator_ClientDlg.h : header file
//

#if !defined(AFX_SIMULATOR_CLIENTDLG_H__16DB4324_C1A9_443F_90B6_8343247993C1__INCLUDED_)
#define AFX_SIMULATOR_CLIENTDLG_H__16DB4324_C1A9_443F_90B6_8343247993C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSimulator_ClientDlg dialog

class CSimulator_ClientDlg : public CDialog
{
// Construction
public:
	CSimulator_ClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSimulator_ClientDlg)
	enum { IDD = IDD_SIMULATOR_CLIENT_DIALOG };
	CListBox	m_msg2;
	CString	m_msg1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSimulator_ClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSimulator_ClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSend();
	afx_msg void OnRcv();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIMULATOR_CLIENTDLG_H__16DB4324_C1A9_443F_90B6_8343247993C1__INCLUDED_)
