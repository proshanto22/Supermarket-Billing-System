// NewSes.cpp : implementation file
//

#include "stdafx.h"
#include "final.h"
#include "NewSes.h"
#include "afxdialogex.h"

#include "Add.h"
#include "NewView.h"
// NewSes dialog

IMPLEMENT_DYNAMIC(NewSes, CDialog)

NewSes::NewSes(CWnd* pParent /*=NULL*/)
	: CDialog(NewSes::IDD, pParent)
	, m_Bitem(_T(""))
	, m_BQty(_T(""))
	, m_Btax(_T(""))
	, m_Bdis(_T(""))
{

}

NewSes::~NewSes()
{
}

void NewSes::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_Bitem);
	DDX_Text(pDX, IDC_EDIT3, m_BQty);
	DDX_Control(pDX, IDC_EDIT2, m_B1);
	DDX_Control(pDX, IDC_EDIT3, m_B2);
	DDX_Text(pDX, IDC_EDIT6, m_Btax);
	DDX_Text(pDX, IDC_EDIT7, m_Bdis);
	DDX_Control(pDX, IDC_EDIT6, m_B3);
	DDX_Control(pDX, IDC_EDIT7, m_B4);
}


BEGIN_MESSAGE_MAP(NewSes, CDialog)
	ON_EN_CHANGE(IDC_EDIT2, &NewSes::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON5, &NewSes::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON4, &NewSes::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &NewSes::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON1, &NewSes::OnBnClickedButton1)
END_MESSAGE_MAP()


// NewSes message handlers


void NewSes::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void NewSes::OnBnClickedButton5()
{
	Bill d;
	UpdateData(TRUE);
	if(m_Bitem == "")
	{
		MessageBox(_T("Please enter Item No"));
		m_B1.SetFocus();
		return;
	}
	strcpy(d.ItemNo,(LPCSTR)(CStringA)m_Bitem);
	int f = d.del(d);
	if(f==1)
		MessageBox(_T("Item Removed"));
	else
		MessageBox(_T("No such item"));

	m_Bitem = "";
	m_B1.SetFocus();
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
}


void NewSes::OnBnClickedButton4()
{

	Bill a;
	UpdateData(TRUE);
	if(m_Bitem == "")
	{
		MessageBox(_T("Please enter Item No"));
		m_B1.SetFocus();
		return;
	}
	if(m_BQty == "")
	{
		MessageBox(_T("Please enter Quantity"));
		m_B2.SetFocus();
		return;
	}
	if(m_Btax == "")
	{
		MessageBox(_T("Please enter the TAX"));
		m_B3.SetFocus();
		return;
	}
	if(m_Bdis == "")
	{
		MessageBox(_T("Please enter discout value"));
		m_B1.SetFocus();
		return;
	}
	strcpy(a.ItemNo,(LPCSTR)(CStringA)m_Bitem);
	strcpy(a.quantity,(LPCSTR)(CStringA)m_BQty);
	strcpy(a.tax,(LPCSTR)(CStringA)m_Btax);
	strcpy(a.discount,(LPCSTR)(CStringA)m_Bdis);
	int f = a.add(a);
	if(f==1){
	MessageBox(_T("Item Added Successfully"));
	}
	else if (f==2){
		MessageBox(_T("Item Out of Stock"));
	}
	
	else
		MessageBox(_T("Invalid Item No"));
		m_Bitem = "";
		m_BQty = "";
		m_Btax = "";
		m_Bdis = "";
	m_B1.SetFocus();
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
}


void NewSes::OnBnClickedButton6()
{
	NewView nv;
	nv.DoModal();

	// TODO: Add your control notification handler code here
}


void NewSes::OnBnClickedButton1()
{
	remove("bill.txt");
	remove("index.txt");
	remove("trace_b.txt");
	CDialog::OnCancel();

	// TODO: Add your control notification handler code here
}
