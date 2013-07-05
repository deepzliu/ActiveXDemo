#pragma once


// CMidClass 对话框

class CMidClass : public CDialogEx
{
	DECLARE_DYNAMIC(CMidClass)

public:
	CMidClass(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMidClass();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
