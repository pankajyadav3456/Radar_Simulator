// Simulator_Client.h : main header file for the SIMULATOR_CLIENT application
//

#if !defined(AFX_SIMULATOR_CLIENT_H__BC95C0FF_27F6_49C8_AE9D_3456E1FBBA96__INCLUDED_)
#define AFX_SIMULATOR_CLIENT_H__BC95C0FF_27F6_49C8_AE9D_3456E1FBBA96__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSimulator_ClientApp:
// See Simulator_Client.cpp for the implementation of this class
//

class CSimulator_ClientApp : public CWinApp
{
public:
	CSimulator_ClientApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSimulator_ClientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSimulator_ClientApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIMULATOR_CLIENT_H__BC95C0FF_27F6_49C8_AE9D_3456E1FBBA96__INCLUDED_)
