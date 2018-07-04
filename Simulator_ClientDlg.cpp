// Simulator_ClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Simulator_Client.h"
#include "Simulator_ClientDlg.h"
#include "windows.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
CString G;
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
// CSimulator_ClientDlg dialog

CSimulator_ClientDlg::CSimulator_ClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSimulator_ClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSimulator_ClientDlg)
	m_msg1 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSimulator_ClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSimulator_ClientDlg)
	DDX_Control(pDX, IDC_MSG2, m_msg2);
	DDX_Text(pDX, IDC_MSG1, m_msg1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSimulator_ClientDlg, CDialog)
	//{{AFX_MSG_MAP(CSimulator_ClientDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Send, OnSend)
	ON_BN_CLICKED(IDC_RCV, OnRcv)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSimulator_ClientDlg message handlers

BOOL CSimulator_ClientDlg::OnInitDialog()
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
	
	// TODO: Add extra initialization here
	m_msg1 = "Ënter the data to be send";

	UpdateData(FALSE);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSimulator_ClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSimulator_ClientDlg::OnPaint() 
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
HCURSOR CSimulator_ClientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSimulator_ClientDlg::OnSend() 
{
	// TODO: Add your control notification handler code here
HANDLE hSerial;

	hSerial = CreateFile("COM1",GENERIC_WRITE,0,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);

	if(hSerial == INVALID_HANDLE_VALUE)
	{
		if(GetLastError() == ERROR_FILE_NOT_FOUND)
		{
			MessageBox("Serial port doesn't exists");
		}
		else
		{
			G.Format("Send error %d",GetLastError());
			AfxMessageBox(G);
		}
	}

	
	DCB dcbSerialParams = {0};
	dcbSerialParams.DCBlength=sizeof(dcbSerialParams);

	if (!GetCommState(hSerial, &dcbSerialParams))
	{	
		MessageBox("error getting state");
	}

	dcbSerialParams.BaudRate=CBR_19200;
	dcbSerialParams.ByteSize=8;
	dcbSerialParams.StopBits=ONESTOPBIT;
	dcbSerialParams.Parity=NOPARITY;

	if(!SetCommState(hSerial, &dcbSerialParams))
	{
		MessageBox("error setting serial port state");
	}

	COMMTIMEOUTS timeouts={0};
	timeouts.WriteTotalTimeoutConstant=50;
	timeouts.WriteTotalTimeoutMultiplier=10;
	
	if(!SetCommTimeouts(hSerial, &timeouts))
	{
		MessageBox("1st error occureed");
	}

	
	//char szBuff[4] = {0};
	DWORD dwBytesRead = 0;
	if(!WriteFile(hSerial, m_msg1, 4, &dwBytesRead, NULL))
	{
		CString g;
		g.Format("%d",GetLastError());
		AfxMessageBox(g);
		MessageBox("2nd error occurred");
	}
	
	UpdateData(TRUE);
	CloseHandle(hSerial);
}

void CSimulator_ClientDlg::OnRcv() 
{
	// TODO: Add your control notification handler code here
	HANDLE hSerial;

	hSerial = CreateFile("COM1",GENERIC_READ,0,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);

	if(hSerial == INVALID_HANDLE_VALUE)
	{
		if(GetLastError() == ERROR_FILE_NOT_FOUND)
		{
			MessageBox("Serial port doesn't exists");
		}
		MessageBox("Some Other Error has Occured");
	}

	
	DCB dcbSerialParams = {0};
	dcbSerialParams.DCBlength=sizeof(dcbSerialParams);

	if (!GetCommState(hSerial, &dcbSerialParams))
	{	
		MessageBox("error getting state");
	}

	dcbSerialParams.BaudRate=CBR_19200;
	dcbSerialParams.ByteSize=8;
	dcbSerialParams.StopBits=ONESTOPBIT;
	dcbSerialParams.Parity=NOPARITY;

	if(!SetCommState(hSerial, &dcbSerialParams))
	{
		MessageBox("error setting serial port state");
	}

	COMMTIMEOUTS timeouts={0};
	timeouts.ReadIntervalTimeout=50;
	timeouts.ReadTotalTimeoutConstant=50;
	timeouts.ReadTotalTimeoutMultiplier=10;
	
	if(!SetCommTimeouts(hSerial, &timeouts))
	{
		MessageBox("error occureed");
	}

	
	
	char szBuff[4] = {0};
	DWORD dwBytesRead = 0;
	if(!ReadFile(hSerial, szBuff,4, &dwBytesRead, NULL))
	{
		MessageBox("error occurred");
	}
	//m_msg1 = szBuff;
	UpdateData(TRUE);
	CloseHandle(hSerial);
}

void CSimulator_ClientDlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	OnCancel();
	
}
