// rem_mDlg.cpp : implementation file
//

#include "stdafx.h"
#include "final.h"
#include "rem_mDlg.h"
#include "afxdialogex.h"

#include "Add.h"

// rem_mDlg dialog

IMPLEMENT_DYNAMIC(rem_mDlg, CDialog)

rem_mDlg::rem_mDlg(CWnd* pParent /*=NULL*/)
	: CDialog(rem_mDlg::IDD, pParent)
	, m_del(_T(""))
{

}

rem_mDlg::~rem_mDlg()
{
}

void rem_mDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_del);
	DDX_Control(pDX, IDC_EDIT1, m_Edel);
}


BEGIN_MESSAGE_MAP(rem_mDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &rem_mDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// rem_mDlg message handlers


void rem_mDlg::OnBnClickedButton1()
{
	Bill d;
	UpdateData(TRUE);
	if(m_del == "")
	{
		MessageBox(_T("Please enter Item No"));
		m_Edel.SetFocus();
		return;
	}
	strcpy(d.ItemNo,(LPCSTR)(CStringA)m_del);
	int f = d.del_M(d);
	if(f==1){
	MessageBox(_T("Item Removed Successfully"));
	}
	else{
		MessageBox(_T("Item Not Found"));
	}
	m_del = "";
	m_Edel.SetFocus();
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
}
