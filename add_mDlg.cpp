// add_mDlg.cpp : implementation file
//

#include "stdafx.h"
#include "final.h"
#include "add_mDlg.h"
#include "afxdialogex.h"
#include "Add.h"

// add_mDlg dialog

IMPLEMENT_DYNAMIC(add_mDlg, CDialog)

add_mDlg::add_mDlg(CWnd* pParent /*=NULL*/)
	: CDialog(add_mDlg::IDD, pParent)
	, m_Mitem(_T(""))
	, m_Mname(_T(""))
	, m_Mprice(_T(""))
	, m_Mcount(_T(""))
{

}

add_mDlg::~add_mDlg()
{
}

void add_mDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Mitem);
	DDX_Control(pDX, IDC_EDIT1, m_MEitem);
	DDX_Text(pDX, IDC_EDIT2, m_Mname);
	DDX_Control(pDX, IDC_EDIT2, m_MEname);
	DDX_Text(pDX, IDC_EDIT3, m_Mprice);
	DDX_Text(pDX, IDC_EDIT4, m_Mcount);
	DDX_Control(pDX, IDC_EDIT4, m_MEcount);
	DDX_Control(pDX, IDC_EDIT3, m_MEprice);
}


BEGIN_MESSAGE_MAP(add_mDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &add_mDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// add_mDlg message handlers


void add_mDlg::OnBnClickedButton1()
{
	
	Bill i;
	UpdateData();
	if(m_Mitem == "")
	{
		MessageBox(_T("Please enter Item No"));
		m_MEitem.SetFocus();
		return;
	}
	if(m_Mname == "")
	{
		MessageBox(_T("Please enter Quantity"));
			m_MEname.SetFocus();
		return;
	}
	if(m_Mprice == "")
	{
		MessageBox(_T("Please enter the TAX"));
		m_MEprice.SetFocus();
		return;
	}
	if(m_Mcount == "")
	{
		MessageBox(_T("Please enter discout value"));
		m_MEcount.SetFocus();
		return;
	}
	strcpy(i.ItemNo,(LPCSTR)(CStringA)m_Mitem);
	strcpy(i.name,(LPCSTR)(CStringA)m_Mname);
	strcpy(i.price,(LPCSTR)(CStringA)m_Mprice);
	strcpy(i.cnt,(LPCSTR)(CStringA)m_Mcount);
	int f = i.add_M(i);
	if(f==1){
	MessageBox(_T("Item Added Successfully"));
	}
	else{
		MessageBox(_T("Item Already Exists"));
	}

		m_Mitem = "";
		m_Mname = "";
		m_Mprice = "";
		m_Mcount = "";

	/*m_MEitem.Clear();
	m_MEname.Clear();
	m_MEprice.Clear();
	m_MEcount.Clear();*/
	m_MEitem.SetFocus();
	UpdateData(FALSE);

	// TODO: Add your control notification handler code here
}
