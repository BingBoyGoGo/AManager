#pragma once
#include "afxwin.h"


// CModify 对话框

class CModify : public CDialogEx
{
	DECLARE_DYNAMIC(CModify)

public:
	CModify(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CModify();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MODIFY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_ID;
	CEdit m_name;
	afx_msg void OnEnChangeEdit3();
	CEdit m_price;
	CEdit m_info;
	CEdit m_firm;
	afx_msg void OnBnClickedOk();
	CStringW sendMsg(CStringW str);
	CStringW ID;
	CStringW name;
	CStringW price;
	CStringW firm;
	CStringW info;
};
