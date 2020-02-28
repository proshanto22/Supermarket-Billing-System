#pragma once


// MainDlg dialog

class MainDlg : public CDialog
{
	DECLARE_DYNAMIC(MainDlg)

public:
	MainDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~MainDlg();

// Dialog Data
	enum { IDD = IDD_FINAL_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
