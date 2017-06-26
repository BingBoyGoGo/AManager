#pragma once
#include "afxwin.h"


// CAdd 对话框

class CAdd : public CDialogEx
{
	DECLARE_DYNAMIC(CAdd)

public:
	CAdd(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAdd();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
//	CString m_ID;
//	CString m_name;
//	double m_price;
//	CString m_firm;
	afx_msg void OnEnChangeEdit4();
	CEdit m_ID;
	CEdit m_name;
	CEdit m_price;
	CEdit m_firm;
};
