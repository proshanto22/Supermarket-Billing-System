#pragma once


// View_MNew dialog

class View_MNew : public CDialog
{
	DECLARE_DYNAMIC(View_MNew)

public:
	View_MNew(CWnd* pParent = NULL);   // standard constructor
	virtual ~View_MNew();

// Dialog Data
	enum { IDD = IDD_VIEW_MDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton2();
};
