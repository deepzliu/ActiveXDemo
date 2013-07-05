// MyActiveXPropPage.cpp : Implementation of the CMyActiveXPropPage property page class.

#include "stdafx.h"
#include "MyActiveX.h"
#include "MyActiveXPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CMyActiveXPropPage, COlePropertyPage)



// Message map

BEGIN_MESSAGE_MAP(CMyActiveXPropPage, COlePropertyPage)
END_MESSAGE_MAP()



// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CMyActiveXPropPage, "MYACTIVEX.MyActiveXPropPage.1",
	0x746cccbd, 0x3589, 0x4370, 0x8d, 0x61, 0xa3, 0xef, 0x1c, 0x7c, 0x12, 0x24)



// CMyActiveXPropPage::CMyActiveXPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CMyActiveXPropPage

BOOL CMyActiveXPropPage::CMyActiveXPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_MYACTIVEX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CMyActiveXPropPage::CMyActiveXPropPage - Constructor

CMyActiveXPropPage::CMyActiveXPropPage() :
	COlePropertyPage(IDD, IDS_MYACTIVEX_PPG_CAPTION)
{
}



// CMyActiveXPropPage::DoDataExchange - Moves data between page and properties

void CMyActiveXPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}



// CMyActiveXPropPage message handlers
