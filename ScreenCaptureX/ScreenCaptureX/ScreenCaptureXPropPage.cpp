// ScreenCaptureXPropPage.cpp : CScreenCaptureXPropPage 属性页类的实现。

#include "stdafx.h"
#include "ScreenCaptureX.h"
#include "ScreenCaptureXPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CScreenCaptureXPropPage, COlePropertyPage)



// 消息映射

BEGIN_MESSAGE_MAP(CScreenCaptureXPropPage, COlePropertyPage)
END_MESSAGE_MAP()



// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CScreenCaptureXPropPage, "SCREENCAPTUREX.ScreenCaptureXPropPage.1",
	0x51d1744b, 0x756e, 0x45b2, 0x8d, 0x74, 0x51, 0x4a, 0x8a, 0x90, 0x3d, 0xdc)



// CScreenCaptureXPropPage::CScreenCaptureXPropPageFactory::UpdateRegistry -
// 添加或移除 CScreenCaptureXPropPage 的系统注册表项

BOOL CScreenCaptureXPropPage::CScreenCaptureXPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_SCREENCAPTUREX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CScreenCaptureXPropPage::CScreenCaptureXPropPage - 构造函数

CScreenCaptureXPropPage::CScreenCaptureXPropPage() :
	COlePropertyPage(IDD, IDS_SCREENCAPTUREX_PPG_CAPTION)
{
}



// CScreenCaptureXPropPage::DoDataExchange - 在页和属性间移动数据

void CScreenCaptureXPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}



// CScreenCaptureXPropPage 消息处理程序
