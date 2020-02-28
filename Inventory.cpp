// Inventory.cpp : implementation file
//

#include "stdafx.h"
#include "final.h"
#include "Inventory.h"
#include "afxdialogex.h"

#include "add_mDlg.h"
#include "rem_mDlg.h"
#include "Mod_MDlg.h"
#include "View_MDlg.h"
#include "View_MNew.h"

// Inventory dialog

IMPLEMENT_DYNAMIC(Inventory, CDialog)

Inventory::Inventory(CWnd* pParent /*=NULL*/)
	: CDialog(Inventory::IDD, pParent)
{

}

Inventory::~Inventory()
{
}

void Inventory::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Inventory, CDialog)
	ON_BN_CLICKED(IDC_BUTTON5, &Inventory::OnBnClickedButton5)
END_MESSAGE_MAP()


// Inventory message handlers


void Inventory::OnBnClickedButton5()
{
	int checkRadio = GetCheckedRadioButton(IDC_RADIO1,IDC_RADIO4);
	switch(checkRadio)
	{
	case IDC_RADIO1 : 
		{
			add_mDlg d;
			d.DoModal();
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
	}
	// TODO: Add your control notification handler code here
}
