#pragma once
#include "Resource.h"
#include "afxdialogex.h"
#include "Errorinfo.h"
#include<vector>
// CSubDlg_1 对话框

class CSubDlg_1 : public CDialogEx
{
	DECLARE_DYNAMIC(CSubDlg_1)

public:
	CSubDlg_1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSubDlg_1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SUBDLG_1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CWnd* m_pParent;//用于调用父窗口变量的指针
	Errorinfo m_addinfo;
	std::vector<Errorinfo>m_adderrors;
	CEdit m_edit_loca;
	CEdit m_edit_type;
	CEdit m_edit_desc;
	afx_msg void OnClickedButtonAdd();

	afx_msg void OnBnClickedButtonSaveinfo();

	virtual BOOL OnInitDialog();
};
