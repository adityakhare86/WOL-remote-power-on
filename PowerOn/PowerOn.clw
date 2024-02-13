; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPowerOnDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PowerOn.h"

ClassCount=3
Class1=CPowerOnApp
Class2=CPowerOnDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_POWERON_DIALOG
Resource4=IDD_ABOUTBOX (English (U.S.))
Resource5=IDD_POWERON_DIALOG (English (U.S.))

[CLS:CPowerOnApp]
Type=0
HeaderFile=PowerOn.h
ImplementationFile=PowerOn.cpp
Filter=N

[CLS:CPowerOnDlg]
Type=0
HeaderFile=PowerOnDlg.h
ImplementationFile=PowerOnDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_PORT

[CLS:CAboutDlg]
Type=0
HeaderFile=PowerOnDlg.h
ImplementationFile=PowerOnDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg


[DLG:IDD_POWERON_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CPowerOnDlg

[DLG:IDD_POWERON_DIALOG (English (U.S.))]
Type=1
Class=CPowerOnDlg
ControlCount=12
Control1=IDC_STATIC,static,1342308352
Control2=IDC_MAC_1,edit,1350631552
Control3=IDC_MAC_2,edit,1350631552
Control4=IDC_MAC_3,edit,1350631552
Control5=IDC_MAC_4,edit,1350631552
Control6=IDC_MAC_5,edit,1350631552
Control7=IDC_MAC_6,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_PORT,edit,1350631552
Control10=IDC_STATIC,static,1342308353
Control11=IDC_POWER_ON,button,1342242817
Control12=IDCANCEL,button,1342242816

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

