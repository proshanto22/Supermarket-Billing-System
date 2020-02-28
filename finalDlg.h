
// finalDlg.h : header file
//

#pragma once


// CfinalDlg dialog
class CfinalDlg : public CDialogEx
{
// Construction
public:
	CfinalDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_FINAL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
	int m_PIN;
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnEnChangeEdit1();
};
