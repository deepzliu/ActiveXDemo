// MidClass.cpp : 实现文件
//

#include "stdafx.h"
#include "ScreenCaptureX.h"
#include "MidClass.h"
#include "afxdialogex.h"


// CMidClass 对话框

IMPLEMENT_DYNAMIC(CMidClass, CDialogEx)

CMidClass::CMidClass(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMidClass::IDD, pParent)
{

}

CMidClass::~CMidClass()
{
}

void CMidClass::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMidClass, CDialogEx)
END_MESSAGE_MAP()


// CMidClass 消息处理程序
