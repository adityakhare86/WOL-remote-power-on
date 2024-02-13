; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMacFinderDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MacFinder.h"

ClassCount=3
Class1=CMacFinderApp
Class2=CMacFinderDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MACFINDER_DIALOG
Resource4=IDD_ABOUTBOX (English (U.S.))
Resource5=IDD_MACFINDER_DIALOG (English (U.S.))

[CLS:CMacFinderApp]
Type=0
HeaderFile=MacFinder.h
ImplementationFile=MacFinder.cpp
Filter=N

[CLS:CMacFinderDlg]
Type=0
HeaderFile=MacFinderDlg.h
ImplementationFile=MacFinderDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=MacFinderDlg.h
ImplementationFile=MacFinderDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg


[DLG:IDD_MACFINDER_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CMacFinderDlg

[DLG:IDD_MACFINDER_DIALOG (English (U.S.))]
Type=1
Class=CMacFinderDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308865
Control5=IDC_NIC_MAC_LIST,listbox,1353781505

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

