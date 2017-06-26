#pragma once


// CSell 对话框

class CSell : public CDialogEx
{
	DECLARE_DYNAMIC(CSell)

public:
	CSell(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSell();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SELL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
