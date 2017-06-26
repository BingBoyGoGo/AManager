
// ManagerSet.h: CManagerSet 类的接口
//


#pragma once

// 代码生成在 2017年6月23日, 星期五, 17:16

class CManagerSet : public CRecordset
{
public:
	CManagerSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CManagerSet)

// 字段/参数数据

// 以下字符串类型(如果存在)反映数据库字段(ANSI 数据类型的 CStringA 和 Unicode
// 数据类型的 CStringW)的实际数据类型。
//  这是为防止 ODBC 驱动程序执行可能
// 不必要的转换。如果希望，可以将这些成员更改为
// CString 类型，ODBC 驱动程序将执行所有必要的转换。
// (注意: 必须使用 3.5 版或更高版本的 ODBC 驱动程序
// 以同时支持 Unicode 和这些转换)。

	CStringW	column1;
	CStringW	column2;
	double	column3;
	CStringW	column4;
	CStringW	column5;
	CStringW	column6;
	double	column7;
	long	column8;
	double	column9;
	long	column10;
	CTime	column11;
	CStringW	column12;
	CStringW	column13;
	CStringW	column14;
	CStringW	column15;
	double	column16;
	CStringW	column17;
	CStringW	column18;
	CStringW	column19;
	CStringW	column20;
	double	column21;
	long	column22;
	CStringW	column23;
	CTime	column24;

// 重写
	// 向导生成的虚函数重写
	public:
	virtual CString GetDefaultConnect();	// 默认连接字符串

	virtual CString GetDefaultSQL(); 	// 记录集的默认 SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX 支持

// 实现
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

