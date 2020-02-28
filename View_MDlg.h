#pragma once


// View_MDlg dialog

class View_MDlg : public CDialog
{
	DECLARE_DYNAMIC(View_MDlg)

public:
	View_MDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~View_MDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
