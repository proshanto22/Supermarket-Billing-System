
// finalDlg.cpp : implementation file
//

#include "stdafx.h"
#include "final.h"
#include "finalDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "NewSes.h"
#include "Inventory.h"

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CfinalDlg dialog




CfinalDlg::CfinalDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CfinalDlg::IDD, pParent)
	, m_PIN()
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CfinalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_PIN);
}

BEGIN_MESSAGE_MAP(CfinalDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON3, &CfinalDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_RADIO2, &CfinalDlg::OnBnClickedRadio2)
	ON_EN_CHANGE(IDC_EDIT1, &CfinalDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CfinalDlg message handlers

BOOL CfinalDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CfinalDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfinalDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CfinalDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CfinalDlg::OnBnClickedButton3()
{
	int checkRadio = GetCheckedRadioButton(IDC_RADIO1,IDC_RADIO2);
	switch(checkRadio)
	{
	case IDC_RADIO1 : 
		{
			UpdateData();
			if(m_PIN == 2202)
			{
				//ShowWindow(SW_HIDE);
				NewSes ns;
				ns.DoModal();
				//ShowWindow(TRUE);
				//ShowWindow(SW_SHOW);
			}
			else 
				MessageBox(_T("Wrong PIN"));
				
			UpdateData(FALSE);
			break;
		}
	case IDC_RADIO2 :
		{
			UpdateData();
			if(m_PIN == 2204)
			{
				//ShowWindow(SW_HIDE);
				Inventory v;
				v.DoModal();
				//ShowWindow(TRUE);
				//ShowWindow(SW_SHOW);

			}
			else 
				MessageBox(_T("Wrong PIN"));
				
			UpdateData(FALSE);
			break;
		}
	}
	// TODO: Add your control notification handler code here
}


	void CfinalDlg::OnBnClickedRadio2()
	{
		// TODO: Add your control notification handler code here
	}


	void CfinalDlg::OnEnChangeEdit1()
	{
		// TODO:  If this is a RICHEDIT control, the control will not
		// send this notification unless you override the CDialogEx::OnInitDialog()
		// function and call CRichEditCtrl().SetEventMask()
		// with the ENM_CHANGE flag ORed into the mask.

		// TODO:  Add your control notification handler code here
	}
