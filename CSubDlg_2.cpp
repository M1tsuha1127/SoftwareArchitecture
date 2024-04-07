// CSubDlg_2.cpp: 实现文件
//

#include "pch.h"
#include "Dlg_M1tsuha.h"
#include "Dlg_M1tsuhaDlg.h"
#include "afxdialogex.h"
#include "CSubDlg_2.h"


// CSubDlg_2 对话框

IMPLEMENT_DYNAMIC(CSubDlg_2, CDialogEx)

CSubDlg_2::CSubDlg_2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SUBDLG_2, pParent)
{
	m_pParent = pParent;
}

CSubDlg_2::~CSubDlg_2()
{
}

void CSubDlg_2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSubDlg_2, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, &CSubDlg_2::OnBnClickedButtonSearch)
	ON_BN_CLICKED(IDC_BUTTON_FIRST, &CSubDlg_2::OnBnClickedButtonFirst)
	ON_BN_CLICKED(IDC_BUTTON_PREV, &CSubDlg_2::OnBnClickedButtonPrev)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, &CSubDlg_2::OnBnClickedButtonNext)
	ON_BN_CLICKED(IDC_BUTTON_LAST, &CSubDlg_2::OnBnClickedButtonLast)
END_MESSAGE_MAP()


// CSubDlg_2 消息处理程序


void CSubDlg_2::OnBnClickedButtonSearch()
{
	// TODO: 在此添加控件通知处理程序代码
	((CDlgM1tsuhaDlg*)m_pParent)->m_Befound.clear();
	GetDlgItemText(IDC_EDIT_KEYWORDS, m_ckey);
	m_skey = CT2A(m_ckey.GetString());
	for (auto it = ((CDlgM1tsuhaDlg*)m_pParent)->m_Errorlib.begin(); it != ((CDlgM1tsuhaDlg*)m_pParent)->m_Errorlib.end(); it++)
	{
		int idx = it->info.find(m_skey);//遍历lib 查找对象的info中是否含有keyword
		if (idx != std::string::npos) //存在。
		{
			((CDlgM1tsuhaDlg*)m_pParent)->m_Befound.push_back(*it);
		}
	}
	//将检索库第一个展示出来
	if (((CDlgM1tsuhaDlg*)m_pParent)->m_Befound.empty())
	{
		MessageBox(_T("未找到含有该有该关键词的相关信息！\r\n请重新输入。"));
		SetDlgItemText(IDC_STATIC_INDEX, _T(""));
		SetDlgItemText(IDC_EDIT_OUTINFO,_T(""));
		return;
	}
	if (m_skey.empty())
	{
		MessageBox(_T("关键词为空！\r\n请重新输入。"));
		SetDlgItemText(IDC_STATIC_INDEX, _T(""));
		SetDlgItemText(IDC_EDIT_OUTINFO, _T(""));
		return;
	}
	CString cinibefound;
	std::string sinibefound = ((CDlgM1tsuhaDlg*)m_pParent)->m_Befound[0].infoinsertr();
	cinibefound = CA2T(sinibefound.c_str());
	((CDlgM1tsuhaDlg*)m_pParent)->idx_Befound = 0;
	SetDlgItemText(IDC_STATIC_INDEX, CA2T(std::to_string(((CDlgM1tsuhaDlg*)m_pParent)->idx_Befound+1).c_str()));
	SetDlgItemText(IDC_EDIT_OUTINFO, cinibefound);
}


void CSubDlg_2::OnBnClickedButtonFirst()
{
	// TODO: 在此添加控件通知处理程序代码
	((CDlgM1tsuhaDlg*)m_pParent)->idx_Befound = 0;
	CString cfirstbefound;
	std::string sfirstbefound = ((CDlgM1tsuhaDlg*)m_pParent)->m_Befound[((CDlgM1tsuhaDlg*)m_pParent)->idx_Befound].infoinsertr();
	cfirstbefound = CA2T(sfirstbefound.c_str());
	SetDlgItemText(IDC_STATIC_INDEX, CA2T(std::to_string(((CDlgM1tsuhaDlg*)m_pParent)->idx_Befound + 1).c_str()));
	SetDlgItemText(IDC_EDIT_OUTINFO, cfirstbefound);
}



void CSubDlg_2::OnBnClickedButtonPrev()
{
	// TODO: 在此添加控件通知处理程序代码
	((CDlgM1tsuhaDlg*)m_pParent)->idx_Befound--;
	if (((CDlgM1tsuhaDlg*)m_pParent)->idx_Befound < 0)
	{
		MessageBox(_T("已经是第一条检索到的相关信息！"));
		((CDlgM1tsuhaDlg*)m_pParent)->idx_Befound = 0;
		SetDlgItemText(IDC_STATIC_INDEX, CA2T(std::to_string(((CDlgM1tsuhaDlg*)m_pParent)->idx_Befound + 1).c_str()));
		return;
	}
	CString cprevbefound;
	std::string sprevbefound = ((CDlgM1tsuhaDlg*)m_pParent)->m_Befound[((CDlgM1tsuhaDlg*)m_pParent)->idx_Befound].infoinsertr();
	cprevbefound = CA2T(sprevbefound.c_str());
	SetDlgItemText(IDC_STATIC_INDEX, CA2T(std::to_string(((CDlgM1tsuhaDlg*)m_pParent)->idx_Befound + 1).c_str()));
	SetDlgItemText(IDC_EDIT_OUTINFO, cprevbefound);
}



void CSubDlg_2::OnBnClickedButtonNext()
{
	// TODO: 在此添加控件通知处理程序代码
	((CDlgM1tsuhaDlg*)m_pParent)->idx_Befound++;
	if (((CDlgM1tsuhaDlg*)m_pParent)->idx_Befound >= ((CDlgM1tsuhaDlg*)m_pParent)->m_Befound.size())
	{
		MessageBox(_T("已经是最后一条检索到的相关信息！"));
		((CDlgM1tsuhaDlg*)m_pParent)->idx_Befound = ((CDlgM1tsuhaDlg*)m_pParent)->m_Befound.size() - 1;
		SetDlgItemText(IDC_STATIC_INDEX, CA2T(std::to_string(((CDlgM1tsuhaDlg*)m_pParent)->idx_Befound + 1).c_str()));
		return;
	}
	CString cnextbefound;
	std::string snextbefound = ((CDlgM1tsuhaDlg*)m_pParent)->m_Befound[((CDlgM1tsuhaDlg*)m_pParent)->idx_Befound].infoinsertr();
	cnextbefound = CA2T(snextbefound.c_str());
	SetDlgItemText(IDC_STATIC_INDEX, CA2T(std::to_string(((CDlgM1tsuhaDlg*)m_pParent)->idx_Befound + 1).c_str()));
	SetDlgItemText(IDC_EDIT_OUTINFO, cnextbefound);
}



void CSubDlg_2::OnBnClickedButtonLast()
{
	// TODO: 在此添加控件通知处理程序代码
	((CDlgM1tsuhaDlg*)m_pParent)->idx_Befound = ((CDlgM1tsuhaDlg*)m_pParent)->m_Befound.size()-1;
	CString clastbefound;
	std::string slastbefound = ((CDlgM1tsuhaDlg*)m_pParent)->m_Befound[((CDlgM1tsuhaDlg*)m_pParent)->idx_Befound].infoinsertr();
	clastbefound = CA2T(slastbefound.c_str());
	SetDlgItemText(IDC_STATIC_INDEX, CA2T(std::to_string(((CDlgM1tsuhaDlg*)m_pParent)->idx_Befound + 1).c_str()));
	SetDlgItemText(IDC_EDIT_OUTINFO, clastbefound);
}
