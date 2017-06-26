#pragma once
#include "afxwin.h"


// CBuy 对话框

class CBuy : public CDialogEx
{
	DECLARE_DYNAMIC(CBuy)

public:
	CBuy(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CBuy();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BUY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_inprice;
	CEdit m_inamount;
	CEdit m_firm;
	CEdit m_info;
	afx_msg void OnBnClickedOk();
	CString inprice;
	CString inamount;
	CString firm;
	CString info;
};
