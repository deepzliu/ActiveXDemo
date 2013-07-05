// ScreenCaptureX.cpp : CScreenCaptureXApp 和 DLL 注册的实现。

#include "stdafx.h"
#include "ScreenCaptureX.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CScreenCaptureXApp theApp;

const GUID CDECL _tlid = { 0xBE5A501, 0x1030, 0x48ED, { 0xA7, 0xCF, 0x67, 0x5D, 0xF8, 0xEC, 0xDE, 0x45 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CScreenCaptureXApp::InitInstance - DLL 初始化

BOOL CScreenCaptureXApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: 在此添加您自己的模块初始化代码。
	}

	return bInit;
}



// CScreenCaptureXApp::ExitInstance - DLL 终止

int CScreenCaptureXApp::ExitInstance()
{
	// TODO: 在此添加您自己的模块终止代码。

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - 将项添加到系统注册表

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - 将项从系统注册表中移除

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
