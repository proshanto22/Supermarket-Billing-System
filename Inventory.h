#pragma once


// Inventory dialog

class Inventory : public CDialog
{
	DECLARE_DYNAMIC(Inventory)

public:
	Inventory(CWnd* pParent = NULL);   // standard constructor
	virtual ~Inventory();

// Dialog Data
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton5();
};
