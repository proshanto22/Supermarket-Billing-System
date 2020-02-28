#pragma once
#include "afxwin.h"


// rem_mDlg dialog

class rem_mDlg : public CDialog
{
	DECLARE_DYNAMIC(rem_mDlg)

public:
	rem_mDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~rem_mDlg();

// Dialog Data
	enum { IDD = IDD_RemDlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString m_del;
	CEdit m_Edel;
};
