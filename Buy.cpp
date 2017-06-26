// Buy.cpp : 实现文件
//

#include "stdafx.h"
#include "Manager.h"
#include "Buy.h"
#include "afxdialogex.h"


// CBuy 对话框

IMPLEMENT_DYNAMIC(CBuy, CDialogEx)

CBuy::CBuy(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_BUY, pParent)
	, inprice(_T(""))
	, inamount(_T(""))
	, firm(_T(""))
	, info(_T(""))
{

}

CBuy::~CBuy()
{
}

void CBuy::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_inprice);
	DDX_Control(pDX, IDC_EDIT2, m_inamount);
	DDX_Control(pDX, IDC_EDIT3, m_firm);
	DDX_Control(pDX, IDC_EDIT4, m_info);
}


BEGIN_MESSAGE_MAP(CBuy, CDialogEx)
	ON_BN_CLICKED(IDOK, &CBuy::OnBnClickedOk)
END_MESSAGE_MAP()


// CBuy 消息处理程序


void CBuy::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDatabase m_db;
	CRecordset *m_pSet = new CRecordset();

	m_db.Open(NULL, FALSE, FALSE, _T("ODBC;FILEDSN=.\\Manager.dsn;UID=admin"), true);
	m_pSet->m_pDatabase = &m_db;

	m_inprice.GetWindowTextW(inprice);
	m_inamount.GetWindowTextW(inamount);
	m_firm.GetWindowTextW(firm);
	m_info.GetWindowTextW(info);

	CDialogEx::OnOK();
}
