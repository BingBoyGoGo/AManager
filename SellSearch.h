#pragma once
#include "afxcmn.h"


// CSellSearch 对话框

class CSellSearch : public CDialogEx
{
	DECLARE_DYNAMIC(CSellSearch)

public:
	CSellSearch(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSellSearch();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEARCHBYSELL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_listCtrl;
};
