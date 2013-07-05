// ScreenCaptureXCtrl.cpp : CScreenCaptureXCtrl ActiveX 控件类的实现。

#include "stdafx.h"
#include "ScreenCaptureX.h"
#include "ScreenCaptureXCtrl.h"
#include "ScreenCaptureXPropPage.h"
#include "afxdialogex.h"
#include "MidClass.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CScreenCaptureXCtrl, COleControl)



// 消息映射

BEGIN_MESSAGE_MAP(CScreenCaptureXCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()



// 调度映射

BEGIN_DISPATCH_MAP(CScreenCaptureXCtrl, COleControl)
	DISP_PROPERTY_NOTIFY_ID(CScreenCaptureXCtrl, "InputParameter", dispidInputParameter, m_InputParameter, OnInputParameterChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY_ID(CScreenCaptureXCtrl, "UploadURL", dispidUploadURL, m_UploadURL, OnUploadURLChanged, VT_BSTR)
	DISP_FUNCTION_ID(CScreenCaptureXCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CScreenCaptureXCtrl, "ShowDlg", dispidShowDlg, ShowDlg, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CScreenCaptureXCtrl, "CaptureFunc", dispidCaptureFunc, CaptureFunc, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()



// 事件映射

BEGIN_EVENT_MAP(CScreenCaptureXCtrl, COleControl)
END_EVENT_MAP()



// 属性页

// TODO: 按需要添加更多属性页。请记住增加计数!
BEGIN_PROPPAGEIDS(CScreenCaptureXCtrl, 1)
	PROPPAGEID(CScreenCaptureXPropPage::guid)
END_PROPPAGEIDS(CScreenCaptureXCtrl)



// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CScreenCaptureXCtrl, "SCREENCAPTUREX.ScreenCaptureXCtrl.1",
	0x4e491dbb, 0xa221, 0x4b86, 0xa7, 0x40, 0x74, 0xcd, 0xc5, 0xaf, 0x53, 0xa5)



// 键入库 ID 和版本

IMPLEMENT_OLETYPELIB(CScreenCaptureXCtrl, _tlid, _wVerMajor, _wVerMinor)



// 接口 ID

const IID IID_DScreenCaptureX = { 0x23FA8459, 0x94D0, 0x43C1, { 0x81, 0x22, 0x9, 0xBD, 0xBF, 0x25, 0x21, 0x83 } };
const IID IID_DScreenCaptureXEvents = { 0xF0D0F0D8, 0xD8A2, 0x45D4, { 0x96, 0xB1, 0xA3, 0xAE, 0x62, 0xD9, 0xB7, 0xCC } };


// 控件类型信息

static const DWORD _dwScreenCaptureXOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CScreenCaptureXCtrl, IDS_SCREENCAPTUREX, _dwScreenCaptureXOleMisc)



// CScreenCaptureXCtrl::CScreenCaptureXCtrlFactory::UpdateRegistry -
// 添加或移除 CScreenCaptureXCtrl 的系统注册表项

BOOL CScreenCaptureXCtrl::CScreenCaptureXCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: 验证您的控件是否符合单元模型线程处理规则。
	// 有关更多信息，请参考 MFC 技术说明 64。
	// 如果您的控件不符合单元模型规则，则
	// 必须修改如下代码，将第六个参数从
	// afxRegApartmentThreading 改为 0。

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_SCREENCAPTUREX,
			IDB_SCREENCAPTUREX,
			afxRegApartmentThreading,
			_dwScreenCaptureXOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}



// CScreenCaptureXCtrl::CScreenCaptureXCtrl - 构造函数

CScreenCaptureXCtrl::CScreenCaptureXCtrl()
{
	InitializeIIDs(&IID_DScreenCaptureX, &IID_DScreenCaptureXEvents);
	// TODO: 在此初始化控件的实例数据。
}



// CScreenCaptureXCtrl::~CScreenCaptureXCtrl - 析构函数

CScreenCaptureXCtrl::~CScreenCaptureXCtrl()
{
	// TODO: 在此清理控件的实例数据。
}



// CScreenCaptureXCtrl::OnDraw - 绘图函数

void CScreenCaptureXCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;

	// TODO: 用您自己的绘图代码替换下面的代码。
	//pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	//pdc->Ellipse(rcBounds);
}



// CScreenCaptureXCtrl::DoPropExchange - 持久性支持

void CScreenCaptureXCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: 为每个持久的自定义属性调用 PX_ 函数。
}



// CScreenCaptureXCtrl::OnResetState - 将控件重置为默认状态

void CScreenCaptureXCtrl::OnResetState()
{
	COleControl::OnResetState();  // 重置 DoPropExchange 中找到的默认值

	// TODO: 在此重置任意其他控件状态。
}



// CScreenCaptureXCtrl::AboutBox - 向用户显示“关于”框

void CScreenCaptureXCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_SCREENCAPTUREX);
	dlgAbout.DoModal();
}



// CScreenCaptureXCtrl 消息处理程序


void CScreenCaptureXCtrl::ShowDlg()
{
	//MessageBox(m_InputParameter, L"ABC");
	CMidClass dlg;
	dlg.DoModal();
}

void CScreenCaptureXCtrl::OnInputParameterChanged(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your property handler code here

	SetModifiedFlag();
}

void CScreenCaptureXCtrl::OnUploadURLChanged(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your property handler code here

	SetModifiedFlag();
}

void CScreenCaptureXCtrl::CaptureFunc()
{
	if(m_UploadURL.IsEmpty()){
		MessageBox(L"Upload URL is NULL", L"提示");
		return ;
	}

	CCatchScreenDlg m_CatchScreenDlg;
	m_CatchScreenDlg.SetUploadURL(m_UploadURL);
	int nResponse = m_CatchScreenDlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}
	
}