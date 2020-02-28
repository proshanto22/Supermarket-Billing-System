#pragma once


// NewView dialog

class NewView : public CDialog
{
	DECLARE_DYNAMIC(NewView)

public:
	NewView(CWnd* pParent = NULL);   // standard constructor
	virtual ~NewView();

// Dialog Data
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
