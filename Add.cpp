// Add.cpp : 实现文件
//

#include "stdafx.h"
#include "Manager.h"
#include "Add.h"
#include "afxdialogex.h"
#include "MainDlg.h"

// CAdd 对话框

IMPLEMENT_DYNAMIC(CAdd, CDialogEx)

CAdd::CAdd(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ADD, pParent)
{

}

CAdd::~CAdd()
{
}

void CAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_ID);
	DDX_Control(pDX, IDC_EDIT2, m_name);
	DDX_Control(pDX, IDC_EDIT3, m_price);
	DDX_Control(pDX, IDC_EDIT4, m_firm);
}


BEGIN_MESSAGE_MAP(CAdd, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAdd::OnBnClickedOk)
END_MESSAGE_MAP()


// CAdd 消息处理程序


void CAdd::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDatabase m_db;
	m_db.Open(NULL, FALSE, FALSE, _T("ODBC;FILEDSN=.\\Manager.dsn;UID=admin"),true);
	CRecordset *m_pSet = new CRecordset();
	m_pSet->m_pDatabase = &m_db;

	CStringW ID, name, strPrice, firm;
	CStringW sql;
	m_ID.GetWindowTextW(ID);
	m_name.GetWindowTextW(name);
	m_price.GetWindowTextW(strPrice);
	m_firm.GetWindowTextW(firm);

	//判断是否有输入为空
	if ("" == ID)
	{
		MessageBox(_T("编号为空，不能添加"));
		EndDialog(0);
	}
	if ("" == name)
	{
		MessageBox(_T("药品名为空，不能添加"));
		EndDialog(0);
	}
	if ("" == strPrice)
	{
		strPrice.Format(_T("0"));
	}
	if ("" == firm)
	{
		firm.Format(_T("未填写"));
	}

	if ("" != ID || "" != name)
	{
		sql.Format(_T("select 编号 from 药品信息表 where 编号='%s'"), ID);
		m_pSet->Open(CRecordset::dynaset, sql);

		double price;
		swscanf_s(strPrice, _T("%lf"), &price);
		if (price < 0)
		{
			MessageBox(_T("价格有误"));
		}
		else if (0 == m_pSet->GetRecordCount())
		{
			//时间
			SYSTEMTIME st;
			CStringW date;
			GetLocalTime(&st);
			date.Format(_T("%02d - %02d - %02d %02d: %02d : %02d"), st.wYear, st.wMonth, st.wDay,
				st.wHour, st.wMinute, st.wSecond);

			sql.Format(_T("insert into 新增表 values('%s','%s','%lf','%s')"), ID, name, price, firm);
			m_db.ExecuteSQL(sql);
			sql.Format(_T("insert into 药品信息表 values('%s','%s','%lf',0,0,0,'%s','%s',0)"), ID, name, price, date, firm);
			m_db.ExecuteSQL(sql);
			MessageBox(_T("成功添加"));
		}
		else
		{
			MessageBox(_T("已有该药品信息"));
		}
	}
	CDialogEx::OnOK();
}
