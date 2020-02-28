#pragma once
#include "afxwin.h"


// Mod_MDlg dialog

class Mod_MDlg : public CDialog
{
	DECLARE_DYNAMIC(Mod_MDlg)

public:
	Mod_MDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~Mod_MDlg();

// Dialog Data
	enum { IDD = IDD_ModDlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	CString m_Moditem;
	CEdit m_ModEitem;
	CString m_ModCnt;
	CEdit m_ModECnt;
};
