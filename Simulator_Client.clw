; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSimulator_ClientDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Simulator_Client.h"

ClassCount=3
Class1=CSimulator_ClientApp
Class2=CSimulator_ClientDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SIMULATOR_CLIENT_DIALOG
Resource4=IDD_ABOUTBOX (English (U.S.))
Resource5=IDD_SIMULATOR_CLIENT_DIALOG (English (U.S.))

[CLS:CSimulator_ClientApp]
Type=0
HeaderFile=Simulator_Client.h
ImplementationFile=Simulator_Client.cpp
Filter=N

[CLS:CSimulator_ClientDlg]
Type=0
HeaderFile=Simulator_ClientDlg.h
ImplementationFile=Simulator_ClientDlg.cpp
Filter=D
LastObject=IDC_MSG2
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=Simulator_ClientDlg.h
ImplementationFile=Simulator_ClientDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg


[DLG:IDD_SIMULATOR_CLIENT_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CSimulator_ClientDlg

[DLG:IDD_SIMULATOR_CLIENT_DIALOG (English (U.S.))]
Type=1
Class=CSimulator_ClientDlg
ControlCount=5
Control1=IDC_MSG1,edit,1350631552
Control2=IDC_Send,button,1342242817
Control3=IDC_RCV,button,1342242816
Control4=IDC_MSG2,listbox,1352728835
Control5=IDC_EXIT,button,1342242816

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

