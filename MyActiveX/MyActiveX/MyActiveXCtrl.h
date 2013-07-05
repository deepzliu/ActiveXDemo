#pragma once
#include "maindialog.h"

// MyActiveXCtrl.h : Declaration of the CMyActiveXCtrl ActiveX Control class.


// CMyActiveXCtrl : See MyActiveXCtrl.cpp for implementation.

class CMyActiveXCtrl : public COleControl
{
	DECLARE_DYNCREATE(CMyActiveXCtrl)

// Constructor
public:
	CMyActiveXCtrl();

// Overrides
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	virtual DWORD GetControlFlags();

// Implementation
protected:
	~CMyActiveXCtrl();

	DECLARE_OLECREATE_EX(CMyActiveXCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CMyActiveXCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CMyActiveXCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CMyActiveXCtrl)		// Type name and misc status

	// Subclassed control support
	BOOL IsSubclassedControl();
	LRESULT OnOcmCommand(WPARAM wParam, LPARAM lParam);

// Message maps
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	DECLARE_DISPATCH_MAP()

// Event maps
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
		eventidParameterLoaded = 1L,
		dispidLoadParameter = 3L,
		dispidOutputParameter = 2,
		dispidInputParameter = 1,
		dispidShowDlg = 4L
	};
public:
	CMainDialog m_MainDialog;
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
protected:
	void OnInputParameterChanged(void);
	CString m_InputParameter;
	void OnOutputParameterChanged(void);
	CString m_OutputParameter;
	void LoadParameter(void);
	void ShowDlg(void);

	void FireParameterLoaded(void)
	{
		FireEvent(eventidParameterLoaded, EVENT_PARAM(VTS_NONE));
	}
};

