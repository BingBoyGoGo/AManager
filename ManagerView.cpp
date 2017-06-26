
// ManagerView.cpp : CManagerView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Manager.h"
#endif

#include "ManagerSet.h"
#include "ManagerDoc.h"
#include "ManagerView.h"

#include "MainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CManagerView

IMPLEMENT_DYNCREATE(CManagerView, CRecordView)

BEGIN_MESSAGE_MAP(CManagerView, CRecordView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_STN_CLICKED(IDC_WELCOME, &CManagerView::OnClickedWelcome)
	ON_BN_CLICKED(IDC_WEL, &CManagerView::OnBnClickedWel)
END_MESSAGE_MAP()

// CManagerView 构造/析构

CManagerView::CManagerView()
	: CRecordView(IDD_MANAGER_FORM)
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CManagerView::~CManagerView()
{
}

void CManagerView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
}

BOOL CManagerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CManagerView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_ManagerSet;
	CRecordView::OnInitialUpdate();

}


// CManagerView 打印

BOOL CManagerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CManagerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CManagerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CManagerView 诊断

#ifdef _DEBUG
void CManagerView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CManagerView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CManagerDoc* CManagerView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CManagerDoc)));
	return (CManagerDoc*)m_pDocument;
}
#endif //_DEBUG


// CManagerView 数据库支持
CRecordset* CManagerView::OnGetRecordset()
{
	return m_pSet;
}



// CManagerView 消息处理程序


void CManagerView::OnClickedWelcome()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CManagerView::OnBnClickedWel()
{
	// TODO: 在此添加控件通知处理程序代码
	CMainDlg dlg;
	dlg.DoModal();
}
