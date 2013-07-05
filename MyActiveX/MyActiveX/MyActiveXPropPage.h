#pragma once

// MyActiveXPropPage.h : Declaration of the CMyActiveXPropPage property page class.


// CMyActiveXPropPage : See MyActiveXPropPage.cpp for implementation.

class CMyActiveXPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CMyActiveXPropPage)
	DECLARE_OLECREATE_EX(CMyActiveXPropPage)

// Constructor
public:
	CMyActiveXPropPage();

// Dialog Data
	enum { IDD = IDD_PROPPAGE_MYACTIVEX };

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	DECLARE_MESSAGE_MAP()
};

