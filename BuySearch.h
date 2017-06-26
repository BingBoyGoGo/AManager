#pragma once
#include "afxcmn.h"


// CBuySearch 对话框

class CBuySearch : public CDialogEx
{
	DECLARE_DYNAMIC(CBuySearch)

public:
	CBuySearch(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CBuySearch();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BUYSEARCH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listCtrl;
	virtual BOOL OnInitDialog();
};
