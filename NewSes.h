#pragma once
#include "afxwin.h"


// NewSes dialog

class NewSes : public CDialog
{
	DECLARE_DYNAMIC(NewSes)

public:
	NewSes(CWnd* pParent = NULL);   // standard constructor
	virtual ~NewSes();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_Bitem;
	CString m_BQty;
	CEdit m_B1;
	CEdit m_B2;
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton5();
	CString m_Btax;
	CString m_Bdis;
	afx_msg void OnBnClickedButton4();
	CEdit m_B3;
	CEdit m_B4;
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton1();
};
