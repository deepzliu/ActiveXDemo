#pragma once

// ScreenCaptureXCtrl.h : CScreenCaptureXCtrl ActiveX 控件类的声明。
#include "CatchScreenDlg.h"

// CScreenCaptureXCtrl : 有关实现的信息，请参阅 ScreenCaptureXCtrl.cpp。

class CScreenCaptureXCtrl : public COleControl
{
	DECLARE_DYNCREATE(CScreenCaptureXCtrl)

// 构造函数
public:
	CScreenCaptureXCtrl();

// 重写
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// 实现
protected:
	~CScreenCaptureXCtrl();

	DECLARE_OLECREATE_EX(CScreenCaptureXCtrl)    // 类工厂和 guid
	DECLARE_OLETYPELIB(CScreenCaptureXCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CScreenCaptureXCtrl)     // 属性页 ID
	DECLARE_OLECTLTYPE(CScreenCaptureXCtrl)		// 类型名称和杂项状态

// 消息映射
	DECLARE_MESSAGE_MAP()

// 调度映射
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();
	afx_msg void ShowDlg();
	afx_msg void CaptureFunc();

// 事件映射
	DECLARE_EVENT_MAP()

// 调度和事件 ID
public:
	enum {
		dispidShowDlg = 1L,
		dispidInputParameter = 2L,
		dispidCaptureFunc = 3L,
		dispidUploadURL = 4L
	};
		
private:
	//CCatchScreenDlg m_CatchScreenDlg;
protected:

	CString m_InputParameter;
	void OnInputParameterChanged(void);
	CString m_UploadURL;
	void OnUploadURLChanged(void);
	//void ShowDlg(CString msg);
	//void ShowDlg();
};

// CHttpConnection 可用于上传