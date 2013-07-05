#pragma once

// ScreenCaptureXPropPage.h : CScreenCaptureXPropPage 属性页类的声明。


// CScreenCaptureXPropPage : 有关实现的信息，请参阅 ScreenCaptureXPropPage.cpp。

class CScreenCaptureXPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CScreenCaptureXPropPage)
	DECLARE_OLECREATE_EX(CScreenCaptureXPropPage)

// 构造函数
public:
	CScreenCaptureXPropPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_SCREENCAPTUREX };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
};

