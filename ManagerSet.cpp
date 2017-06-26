
// ManagerSet.cpp : CManagerSet 类的实现
//

#include "stdafx.h"
#include "Manager.h"
#include "ManagerSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CManagerSet 实现

// 代码生成在 2017年6月23日, 星期五, 17:16

IMPLEMENT_DYNAMIC(CManagerSet, CRecordset)

CManagerSet::CManagerSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	column1 = L"";
	column2 = L"";
	column3 = 0.0;
	column4 = L"";
	column5 = L"";
	column6 = L"";
	column7 = 0.0;
	column8 = 0;
	column9 = 0.0;
	column10 = 0;
	column11;
	column12 = L"";
	column13 = L"";
	column14 = L"";
	column15 = L"";
	column16 = 0.0;
	column17 = L"";
	column18 = L"";
	column19 = L"";
	column20 = L"";
	column21 = 0.0;
	column22 = 0;
	column23 = L"";
	column24;
	m_nFields = 24;
	m_nDefaultType = dynaset;
}
// #error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CManagerSet::GetDefaultConnect()
{
	return _T("DBQ=Manager.mdb;Driver={Microsoft Access Driver (*.mdb)};DriverId=25;FIL=MS Access;FILEDSN=.\\Manager.dsn;MaxBufferSize=2048;MaxScanRows=8;PageTimeout=5;SafeTransactions=0;Threads=3;UID=admin;UserCommitSync=Yes;");
}

CString CManagerSet::GetDefaultSQL()
{
	return _T("[新增表],[药品信息表],[进货表],[销售表]");
}

void CManagerSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[新增表].[编号]"), column1);
	RFX_Text(pFX, _T("[新增表].[药品名]"), column2);
	RFX_Double(pFX, _T("[新增表].[售价]"), column3);
	RFX_Text(pFX, _T("[新增表].[厂商]"), column4);
	RFX_Text(pFX, _T("[药品信息表].[编号]"), column5);
	RFX_Text(pFX, _T("[药品信息表].[药品名]"), column6);
	RFX_Double(pFX, _T("[药品信息表].[售价]"), column7);
	RFX_Long(pFX, _T("[药品信息表].[库存]"), column8);
	RFX_Double(pFX, _T("[药品信息表].[进价]"), column9);
	RFX_Long(pFX, _T("[药品信息表].[进货量]"), column10);
	RFX_Date(pFX, _T("[药品信息表].[进货日期]"), column11);
	RFX_Text(pFX, _T("[药品信息表].[厂商]"), column12);
	RFX_Text(pFX, _T("[药品信息表].[其他信息]"), column13);
	RFX_Text(pFX, _T("[进货表].[编号]"), column14);
	RFX_Text(pFX, _T("[进货表].[药品名]"), column15);
	RFX_Double(pFX, _T("[进货表].[进价]"), column16);
	RFX_Text(pFX, _T("[进货表].[进货量]"), column17);
	RFX_Text(pFX, _T("[进货表].[厂商]"), column18);
	RFX_Text(pFX, _T("[销售表].[编号]"), column19);
	RFX_Text(pFX, _T("[销售表].[药品名]"), column20);
	RFX_Double(pFX, _T("[销售表].[售价]"), column21);
	RFX_Long(pFX, _T("[销售表].[销售量]"), column22);
	RFX_Text(pFX, _T("[销售表].[买家]"), column23);
	RFX_Date(pFX, _T("[销售表].[销售时间]"), column24);

}
/////////////////////////////////////////////////////////////////////////////
// CManagerSet 诊断

#ifdef _DEBUG
void CManagerSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CManagerSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

