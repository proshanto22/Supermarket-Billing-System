#pragma once


// ViewBill dialog

class ViewBill : public CDialogEx
{
	DECLARE_DYNAMIC(ViewBill)

public:
	ViewBill(CWnd* pParent = NULL);   // standard constructor
	virtual ~ViewBill();

// Dialog Data
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
};
