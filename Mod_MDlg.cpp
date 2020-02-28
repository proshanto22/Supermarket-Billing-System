// Mod_MDlg.cpp : implementation file
//

#include "stdafx.h"
#include "final.h"
#include "Mod_MDlg.h"
#include "afxdialogex.h"
#include "Add.h"

// Mod_MDlg dialog

IMPLEMENT_DYNAMIC(Mod_MDlg, CDialog)

Mod_MDlg::Mod_MDlg(CWnd* pParent /*=NULL*/)
	: CDialog(Mod_MDlg::IDD, pParent)
	, m_Moditem(_T(""))
	, m_ModCnt(_T(""))
{

}

Mod_MDlg::~Mod_MDlg()
{
}

void Mod_MDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Moditem);
	DDX_Control(pDX, IDC_EDIT1, m_ModEitem);
	DDX_Text(pDX, IDC_EDIT2, m_ModCnt);
	DDX_Control(pDX, IDC_EDIT2, m_ModECnt);
}


BEGIN_MESSAGE_MAP(Mod_MDlg, CDialog)
	ON_EN_CHANGE(IDC_EDIT1, &Mod_MDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &Mod_MDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Mod_MDlg message handlers


void Mod_MDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void Mod_MDlg::OnBnClickedButton1()
{
	Bill u;
	UpdateData();
	if(m_Moditem == "")
	{
		MessageBox(_T("Please enter Item No"));
		m_ModEitem.SetFocus();
		return;
	}
	if(m_ModCnt == "")
	{
		MessageBox(_T("Please enter Count"));
			m_ModECnt.SetFocus();
		return;
	}

	strcpy(u.ItemNo,(LPCSTR)(CStringA)m_Moditem);
	strcpy(u.cnt,(LPCSTR)(CStringA)m_ModCnt);
	int f = u.upd_M(u);
	if(f==1){
	MessageBox(_T("Item Updated Successfully"));
	}
	else{
		MessageBox(_T("Item Not Available"));
	}

		m_Moditem = "";
		m_ModCnt = "";
		m_ModEitem.SetFocus();
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
}
