// View_MNew.cpp : implementation file
//

#include "stdafx.h"
#include "final.h"
#include "View_MNew.h"
#include "afxdialogex.h"

#include "disp_M.h"
// View_MNew dialog

IMPLEMENT_DYNAMIC(View_MNew, CDialog)

View_MNew::View_MNew(CWnd* pParent /*=NULL*/)
	: CDialog(View_MNew::IDD, pParent)
{

}

View_MNew::~View_MNew()
{
}

void View_MNew::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(View_MNew, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &View_MNew::OnBnClickedButton1)
	ON_BN_CLICKED(IDCANCEL, &View_MNew::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON2, &View_MNew::OnBnClickedButton2)
END_MESSAGE_MAP()


// View_MNew message handlers


void View_MNew::OnBnClickedButton1()
{
	char* results = disp_M();
	CString c(results);
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(c);
	// TODO: Add your control notification handler code here
}


void View_MNew::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}


void View_MNew::OnBnClickedButton2()
{
	/*Bill
	int checkRadio = GetCheckedRadioButton(IDC_RADIO1,IDC_RADIO3);
	switch(checkRadio)
	{
	case IDC_RADIO1 : 
		{
			
			char* results = search_I(d)
	CString c(results);
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(c);
			break;
		}
	case IDC_RADIO2 :
		{
			rem_mDlg d;
			d.DoModal();
			break;
		}

		case IDC_RADIO3 :
			{
				Mod_MDlg m;
				m.DoModal();
				break;
			}

			case IDC_RADIO4 :
				{
					View_MNew v;
					v.DoModal();
					break;
				}
			default : MessageBox(_T("Select an option"));
	}*/
	// TODO: Add your control notification handler code here
}
