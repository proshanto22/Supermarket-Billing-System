#pragma once
#include "afxwin.h"


// add_mDlg dialog

class add_mDlg : public CDialog
{
	DECLARE_DYNAMIC(add_mDlg)

public:
	add_mDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~add_mDlg();

// Dialog Data
	enum { IDD = IDD_ADD_MDlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString m_Mitem;
	CEdit m_MEitem;
	CString m_Mname;
	CEdit m_MEname;
	CString m_Mprice;
	CString m_Mcount;
	CEdit m_MEcount;
	CEdit m_MEprice;
};
