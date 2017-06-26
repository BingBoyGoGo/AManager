#pragma once
#include "afxcmn.h"


// CADDSEARCH 对话框

class CADDSEARCH : public CDialogEx
{
	DECLARE_DYNAMIC(CADDSEARCH)

public:
	CADDSEARCH(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CADDSEARCH();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEARCHADD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listCtrl;
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL OnInitDialog();
};
