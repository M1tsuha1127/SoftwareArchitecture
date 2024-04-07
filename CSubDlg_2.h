#pragma once
#include "afxdialogex.h"
#include "Errorinfo.h"
#include<vector>
#include "Resource.h"

// CSubDlg_2 对话框

class CSubDlg_2 : public CDialogEx
{
	DECLARE_DYNAMIC(CSubDlg_2)

public:
	CSubDlg_2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSubDlg_2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SUBDLG_2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CWnd* m_pParent;//用于调用父窗口变量的指针
	std::string m_skey;
	CString m_ckey;

	afx_msg void OnBnClickedButtonSearch();
	afx_msg void OnBnClickedButtonFirst();
	afx_msg void OnBnClickedButtonPrev();
	afx_msg void OnBnClickedButtonNext();
	afx_msg void OnBnClickedButtonLast();
};
