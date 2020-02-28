// MainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "final.h"
#include "MainDlg.h"
#include "afxdialogex.h"


// MainDlg dialog

IMPLEMENT_DYNAMIC(MainDlg, CDialog)

MainDlg::MainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(MainDlg::IDD, pParent)
{

}

MainDlg::~MainDlg()
{
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MainDlg, CDialog)
END_MESSAGE_MAP()


// MainDlg message handlers
