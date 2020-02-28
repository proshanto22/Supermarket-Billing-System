#pragma once


// ViewIn dialog

class ViewIn : public CDialog
{
	DECLARE_DYNAMIC(ViewIn)

public:
	ViewIn(CWnd* pParent = NULL);   // standard constructor
	virtual ~ViewIn();

// Dialog Data
	enum { IDD = IDD_ViewMDlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
