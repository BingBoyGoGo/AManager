// Modify.cpp : 实现文件
//

#include "stdafx.h"
#include "Manager.h"
#include "Modify.h"
#include "afxdialogex.h"


// CModify 对话框

IMPLEMENT_DYNAMIC(CModify, CDialogEx)

CModify::CModify(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MODIFY, pParent)
{

}

CModify::~CModify()
{
}

void CModify::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_ID);
	DDX_Control(pDX, IDC_EDIT2, m_name);
	DDX_Control(pDX, IDC_EDIT3, m_price);
	DDX_Control(pDX, IDC_EDIT5, m_info);
	DDX_Control(pDX, IDC_EDIT4, m_firm);
}


BEGIN_MESSAGE_MAP(CModify, CDialogEx)
	ON_BN_CLICKED(IDOK, &CModify::OnBnClickedOk)
END_MESSAGE_MAP()


// CModify 消息处理程序

//CStringW ID;
//CStringW name;
//CStringW price;
//CStringW firm;
//CStringW info;
//CStringW sql;

void CModify::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	CDatabase m_db;
	CRecordset *m_pSet = new CRecordset();

	m_db.Open(NULL, FALSE, FALSE, _T("ODBC;FILEDSN=.\\Manager.dsn;UID=admin"), true);
	m_pSet->m_pDatabase = &m_db;

	m_ID.GetWindowTextW(ID);
	m_name.GetWindowTextW(name);
	m_price.GetWindowTextW(price);
	m_firm.GetWindowTextW(firm);
	m_info.GetWindowTextW(info);

	CDialogEx::OnOK();
}

CStringW CModify::sendMsg(CStringW str)
{
	return str;
}

