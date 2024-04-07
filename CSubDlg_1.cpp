// CSubDlg_1.cpp: 实现文件
//

#include "pch.h"
#include "Dlg_M1tsuha.h"
#include "Dlg_M1tsuhaDlg.h"
#include "afxdialogex.h"
#include "CSubDlg_1.h"


// CSubDlg_1 对话框

IMPLEMENT_DYNAMIC(CSubDlg_1, CDialogEx)

CSubDlg_1::CSubDlg_1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SUBDLG_1, pParent)
{
	m_pParent = pParent;
}

CSubDlg_1::~CSubDlg_1()
{
}

void CSubDlg_1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_FAULTINFO_1, m_edit_loca);
	DDX_Control(pDX, IDC_EDIT_FAULTINFO_2, m_edit_type);
	DDX_Control(pDX, IDC_EDIT_FAULTINFO_3, m_edit_desc);
}


BEGIN_MESSAGE_MAP(CSubDlg_1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CSubDlg_1::OnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_SAVEINFO, &CSubDlg_1::OnBnClickedButtonSaveinfo)
END_MESSAGE_MAP()


// CSubDlg_1 消息处理程序


void CSubDlg_1::OnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	//MessageBox(_T("这是一个最简单的消息框！"));

	//读取edit控件内容至obj——errorinfo中
	CString cloca; CString ctype; CString cdesc;
	GetDlgItemText(IDC_EDIT_FAULTINFO_1, cloca);
	GetDlgItemText(IDC_EDIT_FAULTINFO_2, ctype);
	GetDlgItemText(IDC_EDIT_FAULTINFO_3, cdesc);
	m_addinfo.readinfo(cloca, ctype, cdesc);
	
	//添加成功并重新置空
	MessageBox(CA2T(m_addinfo.info.c_str()), _T("添加成功！"));
	SetDlgItemText(IDC_EDIT_FAULTINFO_1, _T(""));
	SetDlgItemText(IDC_EDIT_FAULTINFO_2, _T(""));
	SetDlgItemText(IDC_EDIT_FAULTINFO_3, _T(""));

	//通过调用父对话框指针 将errorinfo存入容器中
	
	((CDlgM1tsuhaDlg*)m_pParent)->m_Errorlib.push_back(m_addinfo);
	((CDlgM1tsuhaDlg*)m_pParent)->m_Errors.push_back(m_addinfo);
	((CDlgM1tsuhaDlg*)m_pParent)->m_Onceadd.push_back(m_addinfo);

	//m_adderrors.push_back(m_addinfo);
	//Addinfo.writetxt(m_txtpath.c_str());
}


void CSubDlg_1::OnBnClickedButtonSaveinfo()
{
	// TODO: 在此添加控件通知处理程序代码

	//记录当前本次用于Save的errorinfo数目
	int count = 0;
	for (auto it = ((CDlgM1tsuhaDlg*)m_pParent)->m_Onceadd.begin(); it != ((CDlgM1tsuhaDlg*)m_pParent)->m_Onceadd.end(); it++)
	{
		it->writetxt(((CDlgM1tsuhaDlg*)m_pParent)->m_libpath.c_str());
		count++;
	}

	//弹框记录
	std::string temp_str = { "成功保存" + std::to_string(count) + "条信息！" };
	std::string error_str = { "没有可以用来保存的信息！" };
	const char* temp_char = temp_str.c_str();
	const char* error_char = error_str.c_str();
	if (count == 0) MessageBox(CA2T(error_char));
	else MessageBox(CA2T(temp_char));

	//调用父窗口指针清空本次Save的errorinfo容器
	((CDlgM1tsuhaDlg*)m_pParent)->m_Onceadd.clear();
}


BOOL CSubDlg_1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//如果字符串第一位是数字 则为图像坐标信息
	CString cloca; std::string sloca;//用于updateerrorinfo线程
	CString ctype; std::string stype;
	cloca = ((CDlgM1tsuhaDlg*)m_pParent)->cloca; sloca = ((CDlgM1tsuhaDlg*)m_pParent)->sloca;
	ctype = ((CDlgM1tsuhaDlg*)m_pParent)->ctype; stype = ((CDlgM1tsuhaDlg*)m_pParent)->stype;
	if (sloca[0] >= '0' && sloca[0] <= '9')
	{
		cloca = CA2T(sloca.c_str());
		SetDlgItemText(IDC_EDIT_FAULTINFO_1, cloca);
		stype = "图像坐标信息";
		ctype = CA2T(stype.c_str());
		SetDlgItemText(IDC_EDIT_FAULTINFO_2, ctype);
	}
	//若不是 则为文本字符信息
	else if(sloca[0]<0)
	{
		cloca = CA2T(sloca.c_str());
		SetDlgItemText(IDC_EDIT_FAULTINFO_1, cloca);
		stype = "文本字符信息";
		ctype = CA2T(stype.c_str());
		SetDlgItemText(IDC_EDIT_FAULTINFO_2, ctype);
	}
	else
	{
		SetDlgItemText(IDC_EDIT_FAULTINFO_1, _T(""));
		SetDlgItemText(IDC_EDIT_FAULTINFO_2, _T(""));

	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
