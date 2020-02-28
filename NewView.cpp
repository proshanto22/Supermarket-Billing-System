// NewView.cpp : implementation file
//

#include "stdafx.h"
#include "final.h"
#include "NewView.h"
#include "afxdialogex.h"

#include "disp_M.h"

// NewView dialog

IMPLEMENT_DYNAMIC(NewView, CDialog)

NewView::NewView(CWnd* pParent /*=NULL*/)
	: CDialog(NewView::IDD, pParent)
{

}

NewView::~NewView()
{
}

void NewView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(NewView, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &NewView::OnBnClickedButton1)
END_MESSAGE_MAP()


// NewView message handlers


void NewView::OnBnClickedButton1()
{	
	
	char* results = disp();
	CString c(results);
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(c);
	// TODO: Add your control notification handler code here
}
