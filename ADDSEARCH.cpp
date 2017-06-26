// ADDSEARCH.cpp : 实现文件
//

#include "stdafx.h"
#include "Manager.h"
#include "ADDSEARCH.h"
#include "afxdialogex.h"


// CADDSEARCH 对话框

IMPLEMENT_DYNAMIC(CADDSEARCH, CDialogEx)

CADDSEARCH::CADDSEARCH(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SEARCHADD, pParent)
{

}

CADDSEARCH::~CADDSEARCH()
{
}

void CADDSEARCH::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listCtrl);
}


BEGIN_MESSAGE_MAP(CADDSEARCH, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CADDSEARCH::OnLvnItemchangedList1)
END_MESSAGE_MAP()


// CADDSEARCH 消息处理程序


void CADDSEARCH::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


BOOL CADDSEARCH::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	m_listCtrl.SetExtendedStyle(LVS_EX_FLATSB | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);// | LVS_EX_CHECKBOXES);//选整行、网格、复选框

	m_listCtrl.InsertColumn(0, _T("编号"), LVCFMT_LEFT, 80, 0);
	m_listCtrl.InsertColumn(1, _T("药品名"), LVCFMT_LEFT, 80, 1);
	m_listCtrl.InsertColumn(2, _T("售价"), LVCFMT_LEFT, 80, 2);
	m_listCtrl.InsertColumn(3, _T("厂商"), LVCFMT_LEFT, 100, 3);
	
	CStringW ID;
	CStringW name;
	CStringW price;
	CStringW firm;
	CStringW sql;

	CDatabase m_db;
	CRecordset *m_pSet = NULL;
	m_db.Open(NULL, FALSE, FALSE, _T("ODBC;FILEDSN=.\\Manager.dsn;UID=admin"), true);
	m_pSet = new CRecordset();
	m_pSet->m_pDatabase = &m_db;
	sql.Format(_T("select * from 新增表 order by 编号"));
	m_pSet->Open(CRecordset::forwardOnly, sql);
	for (int index = 1; !m_pSet->IsEOF(); m_pSet->MoveNext(), index++)
	{
		m_pSet->GetFieldValue(_T("编号"), ID);
		m_pSet->GetFieldValue(_T("药品名"), name);
		m_pSet->GetFieldValue(_T("售价"), price);
		m_pSet->GetFieldValue(_T("厂商"), firm);

		m_listCtrl.InsertItem(index, ID);
		m_listCtrl.SetItemText(index - 1, 1, name);
		m_listCtrl.SetItemText(index - 1, 2, price);
		m_listCtrl.SetItemText(index - 1, 3, firm);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
