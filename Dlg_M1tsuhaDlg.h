
// Dlg_M1tsuhaDlg.h: 头文件
//

#pragma once
#include<vector>
#include<string>
#include"Errorinfo.h"
#include"resource.h"

#include "opencv/cv.h"
#include "opencv/cvaux.h"
#include<opencv2\core\core.hpp>  
#include<opencv2\imgproc\imgproc.hpp>  
#include<opencv2\highgui\highgui.hpp> 
#ifdef _DEBUG
#pragma comment(lib, "opencv_world331d.lib")	
#else
#pragma comment(lib, "opencv_world331.lib")
#endif

// CDlgM1tsuhaDlg 对话框
class CDlgM1tsuhaDlg : public CDialogEx
{
// 构造
public:
	CDlgM1tsuhaDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_M1TSUHA_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

public:
	std::vector<Errorinfo>m_Errors;//调用一次子框
	std::vector<Errorinfo>m_Onceadd;//每一次Save
	std::vector<Errorinfo>m_Errorlib;//整个errorinfo库
	std::vector<Errorinfo>m_Befound;//检索出来的errorinfo
	int idx_Befound;//检索之后的idx

	std::string m_txtpath;
	std::string m_imgpath;
	std::string m_libpath;

	std::string m_strloca;//用来存储由cv鼠标响应时间得到的loca错误 展示在edit_select中
	CString m_cstrloca;

	std::string m_strtxt;//用来存储整个txt文件 展示在edit_show中
	CString m_cstrtxt;

	int m_imgX; int m_imgY;
	CPoint m_Ptxt;

	int nTxtindex_Start;//用来存储由edit控件鼠标响应得到的字符位数
	int nTxtindex_End;//用来存储由edit控件鼠标响应得到的字符位数
	int nTxtindex_Prev;//用来储存上次的值

	std::size_t tpos;//用来储存str对应的位置

	int nCharChinese=0;//统计汉字个数
	int nChinese = 0;

	int countRow = 0;//存放txt loca的行列（鼠标响应）
	int countCol = 0;

	int modetimg_state=-1;//0开启 非0为关闭 -1为默认
	int modettxt_state=-1;//0开启 非0为关闭 -1为默认

	CString cloca; std::string sloca;//用于updateerrorinfo线程
	CString ctype; std::string stype;

	CEdit* ploca;
	CEdit* ptype;
	CEdit* pdesc;

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
//	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnAddFaultinfo();
	afx_msg void OnFindFaultinfo();
	afx_msg void OnClickedButtonSelect();
//	afx_msg void OnEnChangeSelectEdit();
	afx_msg void OnFilePicopen();
	afx_msg void OnClickedButtonShow();
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButtonRefresh();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	afx_msg void OnBnClickedButtonModeimg();
	afx_msg void OnBnClickedButtonModetxt();
	CEdit m_EDIT_SELECT;
	afx_msg void OnBnClickedButtonLoad();
	CEdit m_EDIT_SHOW;
	afx_msg void OnBnClickedButtonLocaaddinfo();
};
