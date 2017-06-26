// MainDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Manager.h"
#include "MainDlg.h"
#include "afxdialogex.h"

#include "Add.h"
#include "Modify.h"
#include "Buy.h"
#include "Sell.h"
#include "SellSearch.h"
#include "ADDSEARCH.h"
#include "stdlib.h"
#include "BuySearch.h"

// CMainDlg 对话框

IMPLEMENT_DYNAMIC(CMainDlg, CDialogEx)

CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MAINDIALOG, pParent)
	, m_ID(0)
	, m_name(0)
	, m_firm(0)
{

}

CMainDlg::~CMainDlg()
{
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listCtrl);
	DDX_Control(pDX, IDC_ADD, m_add);
	DDX_Control(pDX, IDC_EDIT1, m_EditContral);
	DDX_Control(pDX, IDC_EDIT3, m_amount);
}


BEGIN_MESSAGE_MAP(CMainDlg, CDialogEx)
	ON_BN_CLICKED(IDC_SEARCH, &CMainDlg::OnBnClickedSearch)
	ON_BN_CLICKED(IDC_ADD, &CMainDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_MODIFY, &CMainDlg::OnBnClickedModify)
	ON_BN_CLICKED(IDC_BUY, &CMainDlg::OnBnClickedBuy)
	ON_BN_CLICKED(IDC_DELETE, &CMainDlg::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_SELL, &CMainDlg::OnBnClickedSell)
	ON_BN_CLICKED(IDC_BUTTON5, &CMainDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON4, &CMainDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &CMainDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON2, &CMainDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMainDlg 消息处理程序

BOOL CMainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_listCtrl.SetExtendedStyle(LVS_EX_FLATSB | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);// | LVS_EX_CHECKBOXES);//选整行、网格、复选框

	m_listCtrl.InsertColumn(0, _T("编号"), LVCFMT_LEFT,80,0);
	m_listCtrl.InsertColumn(1, _T("药品名"), LVCFMT_LEFT,80,1);
	m_listCtrl.InsertColumn(2, _T("售价"), LVCFMT_LEFT,80,2);
	m_listCtrl.InsertColumn(3, _T("库存"), LVCFMT_LEFT,50,3);
	m_listCtrl.InsertColumn(4, _T("进价"), LVCFMT_LEFT,80,4);
	m_listCtrl.InsertColumn(5, _T("进货量"), LVCFMT_LEFT,80,5);
	m_listCtrl.InsertColumn(6, _T("进货时间"), LVCFMT_LEFT,90,6);
	m_listCtrl.InsertColumn(7, _T("厂商"), LVCFMT_LEFT,80,7);
	m_listCtrl.InsertColumn(8, _T("其他信息"), LVCFMT_LEFT,80,8);
	m_listCtrl.SetColumnWidth(0, LVSCW_AUTOSIZE_USEHEADER);
	
	((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE);
	ShowInfo();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CMainDlg::OnBnClickedSearch()
{
	// TODO: 在此添加控件通知处理程序代码
	CDatabase m_db;
	CRecordset *m_pSet = new CRecordset();
	CStringW sql;
	CStringW keyword;
	CStringW str;

	CStringW ID;
	CStringW name;
	CStringW price;
	CStringW amount;
	CStringW inprice;
	CStringW inamount;
	CStringW indate;
	CStringW firm;
	CStringW info;

	if (!m_db.IsOpen())
		m_db.Open(NULL, FALSE, FALSE, _T("ODBC;FILEDSN=.\\Manager.dsn;UID=admin"), true);

	m_pSet->m_pDatabase = &m_db;
	m_EditContral.GetWindowTextW(keyword);

	int row;
	int itemCount = m_listCtrl.GetItemCount();

	//按编号查询
	if (((CButton *)GetDlgItem(IDC_RADIO1))->GetCheck())
	{
		sql.Format(_T("select * from 药品信息表 where 编号='%s'"),keyword);
	}
	//按名称查询
	else if (((CButton *)GetDlgItem(IDC_RADIO2))->GetCheck())
	{
		sql.Format(_T("select * from 药品信息表 where 药品名='%s'"), keyword);
	}
	//按厂商查询
	else if (((CButton *)GetDlgItem(IDC_RADIO3))->GetCheck())
	{
		sql.Format(_T("select * from 药品信息表 where 厂商='%s'"), keyword);
	}

	m_pSet->Open(CRecordset::dynaset, sql);
	m_pSet->MoveFirst();
	while (!m_pSet->IsEOF())
	{
		m_pSet->MoveNext();
	}
	m_pSet->MoveFirst();
	int a = m_pSet->GetRecordCount();
	m_listCtrl.DeleteAllItems();
	for (int i = 0; i < a; i++)
	{
		m_pSet->GetFieldValue(_T("编号"), ID);
		m_pSet->GetFieldValue(_T("药品名"), name);
		m_pSet->GetFieldValue(_T("售价"), price);
		m_pSet->GetFieldValue(_T("库存"), amount);
		m_pSet->GetFieldValue(_T("进价"), inprice);
		m_pSet->GetFieldValue(_T("进货量"), inamount);
		m_pSet->GetFieldValue(_T("进货日期"), indate);
		m_pSet->GetFieldValue(_T("厂商"), firm);
		m_pSet->GetFieldValue(_T("其他信息"), info);
		m_pSet->MoveNext();

		m_listCtrl.InsertItem(0, ID);
		m_listCtrl.SetItemText(0, 1, name);
		m_listCtrl.SetItemText(0, 2, price);
		m_listCtrl.SetItemText(0, 3, amount);
		m_listCtrl.SetItemText(0, 4, inprice);
		m_listCtrl.SetItemText(0, 5, inamount);
		m_listCtrl.SetItemText(0, 6, indate);
		m_listCtrl.SetItemText(0, 7, firm);
		m_listCtrl.SetItemText(0, 8, info);
	}
}


void CMainDlg::ShowInfo()
{
	CStringW ID;
	CStringW name;
	CStringW price;
	CStringW amount;
	CStringW inprice;
	CStringW inamount;
	CStringW indate;
	CStringW firm;
	CStringW info;
	CStringW sql;

	CDatabase m_db;
	CRecordset *m_pSet = NULL;
	m_db.Open(NULL, FALSE, FALSE, _T("ODBC;FILEDSN=.\\Manager.dsn;UID=admin"), true);
	m_pSet = new CRecordset();
	m_pSet->m_pDatabase = &m_db;
	//sql.Format(_T("select 药品信息表.编号,药品名,售价,库存,进价,进货量,进货日期,厂商,其他信息 from 药品信息表"));
	sql.Format(_T("select * from 药品信息表 order by 编号"));
	m_pSet->Open(CRecordset::forwardOnly, sql);
	for (int index = 1; !m_pSet->IsEOF(); m_pSet->MoveNext(),index++)
	//for (int index = 0; index < m_pSet->GetRecordCount(); index++)
	{
			m_pSet->GetFieldValue(_T("编号"), ID);
			m_pSet->GetFieldValue(_T("药品名"), name);
			m_pSet->GetFieldValue(_T("售价"), price);
			m_pSet->GetFieldValue(_T("库存"), amount);
			m_pSet->GetFieldValue(_T("进价"), inprice);
			m_pSet->GetFieldValue(_T("进货量"), inamount);
			m_pSet->GetFieldValue(_T("进货日期"), indate);
			m_pSet->GetFieldValue(_T("厂商"), firm);
			m_pSet->GetFieldValue(_T("其他信息"), info);
			
			m_listCtrl.InsertItem(index, ID);
			m_listCtrl.SetItemText(index - 1, 1, name);
			m_listCtrl.SetItemText(index-1, 2, price);
			m_listCtrl.SetItemText(index-1, 3, amount);
			m_listCtrl.SetItemText(index - 1, 4, inprice);
			m_listCtrl.SetItemText(index - 1, 5, inamount);
			m_listCtrl.SetItemText(index - 1, 6, indate);
			m_listCtrl.SetItemText(index - 1, 7, firm);
			m_listCtrl.SetItemText(index - 1, 8, info);
	}
}


void CMainDlg::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	CAdd dlg;
	dlg.DoModal();

	m_listCtrl.DeleteAllItems();
	ShowInfo();
}


void CMainDlg::OnBnClickedModify()
{
	// TODO: 在此添加控件通知处理程序代码
	int row = m_listCtrl.GetSelectionMark ();

	if (-1 == row)
	{
		MessageBox(_T("未选取任何数据"));
	}
	else
	{
		CModify ModDlg;
		ModDlg.DoModal();

		CDatabase m_db;
		CRecordset *m_pSet = new CRecordset();

		CStringW ID;
		CStringW name;
		CStringW price;
		CStringW firm;
		CStringW info;
		CStringW sql;

		CStringW itemID = m_listCtrl.GetItemText(row, 0);
		CStringW itemName = m_listCtrl.GetItemText(row, 1);
		CStringW itemPrice = m_listCtrl.GetItemText(row, 2);
		CStringW itemFirm = m_listCtrl.GetItemText(row, 7);
		CStringW itemInfo = m_listCtrl.GetItemText(row, 8);

		if(!m_db.IsOpen())
			m_db.Open(NULL, FALSE, FALSE, _T("ODBC;FILEDSN=.\\Manager.dsn;UID=admin"), true);
		m_pSet->m_pDatabase = &m_db;

		
		ID = ModDlg.ID;
		name = ModDlg.name;
		price = ModDlg.price;
		firm = ModDlg.firm;
		info = ModDlg.info;

		if ("" == ID && "" == name && "" == price && "" == firm && "" == info)
		{
			MessageBox(_T("未进行任何操作"));

		}
		else
		{
			if ("" == ID)
				ID = itemID;
			if ("" == name)
				name = itemName;
			if ("" == price)
				price = itemPrice;
			if ("" == firm)
				firm = itemFirm;
			if ("" == info)
				info = itemInfo;

			double dprice;
			swscanf_s(price, _T("%lf"), &dprice);
			if (dprice < 0)
				MessageBox(_T("价格有误"));
			else
			{
				sql.Format(_T("update 药品信息表 set 编号='%s' where 编号='%s'"), ID, itemID);
				m_db.ExecuteSQL(sql);
				sql.Format(_T("update 药品信息表 set 药品名='%s' where 编号='%s'"), name, itemID);
				m_db.ExecuteSQL(sql);
				sql.Format(_T("update 药品信息表 set 售价='%lf' where 编号='%s'"), dprice, itemID);
				m_db.ExecuteSQL(sql);
				sql.Format(_T("update 药品信息表 set 厂商='%s' where 编号='%s'"), firm, itemID);
				m_db.ExecuteSQL(sql);
				sql.Format(_T("update 药品信息表 set 其他信息='%s' where 编号='%s'"), info, itemID);
				m_db.ExecuteSQL(sql);

				m_listCtrl.DeleteAllItems();
				ShowInfo();
				MessageBox(_T("成功更新信息"));
			}
		}
	}

}


void CMainDlg::OnBnClickedBuy()
{
	// TODO: 在此添加控件通知处理程序代码
	int row = m_listCtrl.GetSelectionMark();

	if (-1 == row)
	{
		MessageBox(_T("未选取任何数据"));
	}
	else
	{
		CBuy buyDlg;
		buyDlg.DoModal();
	
		CDatabase m_db;
		CRecordset *m_pSet = new CRecordset();

		CStringW inprice;
		CStringW inamount;
		CStringW firm;
		CStringW info;
		CStringW sql;

		CStringW itemID = m_listCtrl.GetItemText(row, 0);
		CStringW itemName = m_listCtrl.GetItemText(row, 1);
		CStringW itemPrice = m_listCtrl.GetItemText(row, 2);
		CStringW itemAmount = m_listCtrl.GetItemText(row, 3);
		CStringW itemInPrice = m_listCtrl.GetItemText(row, 4);
		CStringW itemInAmount = m_listCtrl.GetItemText(row, 5);
		CStringW itemDate = m_listCtrl.GetItemText(row, 6);
		CStringW itemFirm = m_listCtrl.GetItemText(row, 7);
		CStringW itemInfo = m_listCtrl.GetItemText(row, 8);
		
		if(!m_db.IsOpen())
			m_db.Open(NULL, FALSE, FALSE, _T("ODBC;FILEDSN=.\\Manager.dsn;UID=admin"), true);
		m_pSet->m_pDatabase = &m_db;

		inprice = buyDlg.inprice;
		inamount = buyDlg.inamount;
		firm = buyDlg.firm;
		info = buyDlg.info;

		if ("" == inprice && "" == inamount && "" == firm && "" == info)
		{
			MessageBox(_T("未进行任何操作"));
		}
		else
		{
			if ("" == inprice)
			{
				MessageBox(_T("进价为0，请重新填写"));
			}
			if ("" == inamount)
			{
				MessageBox(_T("进货量为0，请重新填写"));
			}
			if ("" == firm)
				firm = itemFirm;
			if ("" == info)
				info = itemInfo;

			SYSTEMTIME st;
			CStringW date;
			GetLocalTime(&st);
			date.Format(_T("%02d - %02d - %02d %02d: %02d : %02d"), st.wYear, st.wMonth, st.wDay,
				st.wHour, st.wMinute, st.wSecond);

			long count;
			swscanf_s(itemAmount, _T("%ld"), &count);
			long incount;
			swscanf_s(inamount, _T("%ld"), &incount);
			long inItemAmount;
			swscanf_s(itemInAmount, _T("%ld"), &inItemAmount);
			double price;
			swscanf_s(inprice, _T("%lf"), &price);

			if (count < 0 || price < 0)
				MessageBox(_T("数量或价格有错"));
			else if("" != inprice && "" != inamount)
			{
				long a = count + incount;
				long b = inItemAmount + incount;

				//更新药品信息表
				sql.Format(_T("update 药品信息表 set 进价='%s' where 编号='%s'"), inprice, itemID);
				m_db.ExecuteSQL(sql);
				sql.Format(_T("update 药品信息表 set 进货量='%ld' where 编号='%s'"), b, itemID);
				m_db.ExecuteSQL(sql);
				sql.Format(_T("update 药品信息表 set 库存='%ld' where 编号='%s'"), a, itemID);
				m_db.ExecuteSQL(sql);
				sql.Format(_T("update 药品信息表 set 进货日期='%s' where 编号='%s'"), date, itemID);
				m_db.ExecuteSQL(sql);
				sql.Format(_T("update 药品信息表 set 其他信息='%s' where 编号='%s'"), info, itemID);
				m_db.ExecuteSQL(sql);

				//更新进货表
				sql.Format(_T("insert into 进货表 values('%s','%s','%s','%s','%s')"), itemID, itemName, itemPrice, inamount, firm);
				m_db.ExecuteSQL(sql);
				//更新列表
				m_listCtrl.DeleteAllItems();
				ShowInfo();
				MessageBox(_T("成功购进药品"));
			}
		}
	}
}


void CMainDlg::OnBnClickedDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	int row = m_listCtrl.GetSelectionMark();

	if (-1 == row)
	{
		MessageBox(_T("未选取任何数据"));
	}
	else
	{
		CDatabase m_db;
		if(!m_db.IsOpen ())
			m_db.Open(NULL, FALSE, FALSE, _T("ODBC;FILEDSN=.\\Manager.dsn;UID=admin"), true);

		CStringW sql,itemID;
		itemID = m_listCtrl.GetItemText(row, 0);
		sql.Format(_T("delete from 药品信息表 where 编号='%s'"), itemID);
		m_db.ExecuteSQL(sql);
		sql.Format(_T("delete from 药品信息表 where 编号='%s'"), itemID);
		m_db.ExecuteSQL(sql);

		m_listCtrl.DeleteAllItems();
		ShowInfo();
		MessageBox(_T("成功删除"));
	}
}


void CMainDlg::OnBnClickedSell()
{
	// TODO: 在此添加控件通知处理程序代码
	int row = m_listCtrl.GetSelectionMark();

	if (-1 == row)
	{
		MessageBox(_T("未选取任何数据"));
	}
	else
	{
		CStringW sql;
		CStringW amount;
		m_amount.GetWindowTextW(amount);

		if ("" == amount)
		{
			MessageBox(_T("数量为空"));
		}
		else
		{
			CStringW itemID = m_listCtrl.GetItemText(row, 0);
			CStringW itemName = m_listCtrl.GetItemText(row, 1);
			CStringW itemPrice = m_listCtrl.GetItemText(row, 2);
			CStringW itemAmount = m_listCtrl.GetItemText(row, 3);
			CStringW cus = _T("个体");

			long count, itemcount;
			//转换成long
			swscanf_s(amount, _T("%ld"), &count);
			swscanf_s(itemAmount, _T("%ld"), &itemcount);

			if (0 < count - itemcount)
			{
				MessageBox(_T("存货不足"));
			}
			else
			{
				CDatabase m_db;
				CRecordset *m_pSet = new CRecordset();

				m_db.Open(NULL, FALSE, FALSE, _T("ODBC;FILEDSN=.\\Manager.dsn;UID=admin"), true);
				m_pSet->m_pDatabase = &m_db;

				long a = itemcount - count;
				//获取当前时间
				SYSTEMTIME st;
				CStringW date;
				GetLocalTime(&st);
				date.Format(_T("%02d - %02d - %02d %02d: %02d : %02d"), st.wYear, st.wMonth, st.wDay,
					st.wHour, st.wMinute, st.wSecond);
				//更新记录
				sql.Format(_T("select * from 药品信息表"));
				m_db.ExecuteSQL(sql);
				sql.Format(_T("insert into 销售表 values('%s','%s','%s','%s','%s','%s')"), itemID, itemName, itemPrice, amount, cus, date);
				m_db.ExecuteSQL(sql);
				sql.Format(_T("update 药品信息表 set 库存='%ld' where 编号='%s'"), a, itemID);
				m_db.ExecuteSQL(sql);
				sql.Format(_T("update 药品信息表 set 库存='%ld' where 编号='%s'"), a, itemID);
				m_db.ExecuteSQL(sql);

				MessageBox(_T("成功销售"));
				m_listCtrl.DeleteAllItems();
				ShowInfo();
			}
		}
	}
}


void CMainDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	CSellSearch dlg;
	dlg.DoModal();
}


void CMainDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CADDSEARCH dlg;
	dlg.DoModal();
}


void CMainDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	CBuySearch dlg;
	dlg.DoModal();
}


void CMainDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_listCtrl.DeleteAllItems();
	ShowInfo();
}
