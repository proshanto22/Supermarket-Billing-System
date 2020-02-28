// ViewIn.cpp : implementation file
//

#include "stdafx.h"
#include "final.h"
#include "ViewIn.h"
#include "afxdialogex.h"
#include "resource.h"
#include "disp_M.h"
// ViewIn dialog

IMPLEMENT_DYNAMIC(ViewIn, CDialog)

ViewIn::ViewIn(CWnd* pParent /*=NULL*/)
	: CDialog(ViewIn::IDD, pParent)
{

}

ViewIn::~ViewIn()
{
}

void ViewIn::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ViewIn, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &ViewIn::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &ViewIn::OnBnClickedButton2)
END_MESSAGE_MAP()


// ViewIn message handlers


void ViewIn::OnBnClickedButton1()
{
	char* results = disp();
	CString c(results);
	GetDlgItem(txtView)->SetWindowTextW(c);
	// TODO: Add your control notification handler code here
}


void ViewIn::OnBnClickedButton2()
{
	char* results = disp();
	CString c(results);
	GetDlgItem(txtView)->SetWindowTextW(c);
	// TODO: Add your control notification handler code here
}
