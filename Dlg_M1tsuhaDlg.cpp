
// Dlg_M1tsuhaDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Dlg_M1tsuha.h"
#include "Dlg_M1tsuhaDlg.h"
#include "CSubDlg_1.h"
#include "CSubDlg_2.h"
#include "afxdialogex.h"
#include "onMouse.h"

#include<algorithm>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


const int TIMER_UPDATE_IMGLOCA = 17;
const int TIMER_UPDATE_TXTLOCA = 18;
const int TIMER_UPDATE_ERRORINFO = 19;
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnButtonSelect();
//	afx_msg void OnButtonAdd();
	afx_msg void OnButtonTest();
//	afx_msg void OnBnClickedButtonModetxt();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//	ON_BN_CLICKED(IDC_BUTTON_MODETXT, &CAboutDlg::OnBnClickedButtonModetxt)
END_MESSAGE_MAP()


// CDlgM1tsuhaDlg 对话框



CDlgM1tsuhaDlg::CDlgM1tsuhaDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_M1TSUHA_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDlgM1tsuhaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_SELECT, m_EDIT_SELECT);
	DDX_Control(pDX, IDC_EDIT_SHOW, m_EDIT_SHOW);
}

BEGIN_MESSAGE_MAP(CDlgM1tsuhaDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
//	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_ADD_FAULTINFO, &CDlgM1tsuhaDlg::OnAddFaultinfo)
	ON_COMMAND(ID_FIND_FAULTINFO, &CDlgM1tsuhaDlg::OnFindFaultinfo)
//	ON_COMMAND(IDC_BUTTON_ADD, &CDlgM1tsuhaDlg::OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_SELECT, &CDlgM1tsuhaDlg::OnClickedButtonSelect)
//	ON_EN_CHANGE(IDC_SELECT_EDIT, &CDlgM1tsuhaDlg::OnEnChangeSelectEdit)
ON_COMMAND(ID_FILE_PICOPEN, &CDlgM1tsuhaDlg::OnFilePicopen)
ON_BN_CLICKED(IDC_BUTTON_SHOW, &CDlgM1tsuhaDlg::OnClickedButtonShow)
ON_WM_PAINT()
ON_WM_TIMER()
ON_BN_CLICKED(IDC_BUTTON_MODEIMG, &CDlgM1tsuhaDlg::OnBnClickedButtonModeimg)
ON_BN_CLICKED(IDC_BUTTON_MODETXT, &CDlgM1tsuhaDlg::OnBnClickedButtonModetxt)
ON_BN_CLICKED(IDC_BUTTON_LOAD, &CDlgM1tsuhaDlg::OnBnClickedButtonLoad)
ON_BN_CLICKED(IDC_BUTTON_LOCAADDINFO, &CDlgM1tsuhaDlg::OnBnClickedButtonLocaaddinfo)
END_MESSAGE_MAP()


// CDlgM1tsuhaDlg 消息处理程序

BOOL CDlgM1tsuhaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。
	SetWindowText(_T("地图数据检查工具"));
	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CDlgM1tsuhaDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。


//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDlgM1tsuhaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDlgM1tsuhaDlg::OnAddFaultinfo()
{
	
	INT_PTR nRes;// <用于保存DoModal函数的返回值> 
	CSubDlg_1 tmpSubDlg1(this);
	m_Errors.clear();
	nRes = tmpSubDlg1.DoModal();
	if (IDOK == nRes)// <判断对话框退出后返回值是否为IDOK，则继续向下执行，否则继续向下执行>   
	{
		//此处添加点击子对话框确认按钮之后要执行的代码
		//每次调用添加子对话框添加的所有信息存入m_Errors中
		int count = 0;
		for (auto it = m_Errors.begin(); it !=m_Errors.end(); it++)
		{
			count++;
		}
		std::string temp_str = { "本次操作您共添加了" + std::to_string(count) + "条信息" };
		const char* temp_char = temp_str.c_str();
		MessageBox(CA2T(temp_char));
	}

	// TODO: 在此添加命令处理程序代码
}


void CDlgM1tsuhaDlg::OnFindFaultinfo()
{
	//MessageBox(_T("这是一个最简单的消息框！"));
	INT_PTR nRes;// <用于保存DoModal函数的返回值> 
	CSubDlg_2 tmpSubDlg2(this);

	nRes = tmpSubDlg2.DoModal();
	if (IDOK == nRes)// <判断对话框退出后返回值是否为IDOK，则继续向下执行，否则继续向下执行>   
	{
		//此处添加点击子对话框确认按钮之后要执行的代码
	}
	// TODO: 在此添加命令处理程序代码
}


void CDlgM1tsuhaDlg::OnClickedButtonSelect()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	// 构造打开文件对话框   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	CString strFilePath;
	// 显示打开文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
		strFilePath = fileDlg.GetPathName();
		m_txtpath = CT2A(strFilePath.GetString());
		SetDlgItemText(IDC_STATIC_TXTPATH, strFilePath);
	}
	//读取txt文件至m_strtxt中
	ifstream in(m_txtpath, ios::in);
	istreambuf_iterator<char> beg(in), end;
	string strdata(beg, end);
	m_strtxt = strdata;
	in.close();

	//std::ifstream in(m_txtpath);
	//std::string line;
	//Errorinfo tmp_in;
	//int index = 1;
	//if (in) // 有该文件
	//{
	//	while (std::getline(in, line)) // line中不包括每行的换行符
	//	{
	//		if (index % 3 == 1)tmp_in.loca = line;
	//		if (index % 3 == 2)tmp_in.type = line;
	//		if (index % 3 == 0)
	//		{
	//			tmp_in.desc = line;
	//			tmp_in.setinfo();
	//			m_Errorlib.push_back(tmp_in);
	//			tmp_in.clear();
	//		}
	//		index++;
	//	}
	//}
	//else // 没有该文件
	//{
	//	exit(1);
	//}

}


void CDlgM1tsuhaDlg::OnFilePicopen()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR szFilter[] = _T("图像文件(*.png)|*.png|所有文件(*.*)|*.*||");
	// 构造打开文件对话框   
	CFileDialog fileDlg(TRUE, _T("png"), NULL, 0, szFilter, this);
	CString strFilePath;
	// 显示打开文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
		 strFilePath = fileDlg.GetPathName();
		 m_imgpath = CT2A(strFilePath.GetString());//将图片路径保存便于展示
		 SetDlgItemText(IDC_STATIC_PICINFO, strFilePath);

		 //使用cv嵌套窗口并读取文件
		 cv::Mat mat = cv::imread(m_imgpath);//opencv读取图片

		 cv::namedWindow("ImageShow", CV_WINDOW_NORMAL);//创建OpenCV窗口

		 cv::setMouseCallback("ImageShow", onMouse, &mat);//调用鼠标响应函数 关联cv窗口 

		 HWND hWnd = (HWND)cvGetWindowHandle("ImageShow");//嵌套opencv窗口

		 HWND hParent = ::GetParent(hWnd);

		 ::SetParent(hWnd, GetDlgItem(IDC_IMGWINDOW)->m_hWnd);

		 ::ShowWindow(hParent, SW_SHOW);

		 cv::imshow("ImageShow", mat);//opencv显示图片



		 cv::waitKey(1);
	}
}


void CDlgM1tsuhaDlg::OnClickedButtonShow()
{
	// TODO: 在此添加控件通知处理程序代码
	//MessageBox(_T("这是一个最简单的消息框！"));
	//如果选择的是存储errorlib的文件
	if (m_txtpath == m_libpath)
	{
		std::string strdata; std::string tmpinfo; int count = 1;
		for (auto it = m_Errorlib.begin(); it != m_Errorlib.end(); it++)
		{
			tmpinfo = { "第" + std::to_string(count) + "条错误信息" + "\r\n" + it->loca + "\r\n" + it->type + "\r\n" + it->desc + "\r\n" };
			strdata += tmpinfo;
			count++;
		}
		CString Showdata = CA2T(strdata.c_str());
		SetDlgItemText(IDC_EDIT_SHOW, Showdata);
	}
	else
	{
		//替换m_strtxt中所有的"\n"为"\r\n"
		std::string sub_str = "\n";
		std::string mod_str = "\r";
		std::size_t pos = m_strtxt.find(sub_str);
		//遍历str 在"\n"之前插入"\r"
		while (pos != std::string::npos)
		{
			m_strtxt.insert(pos, mod_str);
			pos++;
			pos = m_strtxt.find(sub_str, pos + sub_str.size());
		}
		//编辑框输入
		m_cstrtxt = CA2T(m_strtxt.c_str());
		SetDlgItemText(IDC_EDIT_SHOW, m_cstrtxt);

		//汉字的acii码值小于0
		/*for (int i = 0; i < m_strtxt.length(); i++)if (m_strtxt[i] < 0)nCharChinese++;	
		nChinese = nCharChinese / 2;*/
	}
}


void CDlgM1tsuhaDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		//使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		//绘制图标
			dc.DrawIcon(x, y, m_hIcon);


	}
	else
	{
		CDialogEx::OnPaint();
	}
}


void CDlgM1tsuhaDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nIDEvent)
	{
	case TIMER_UPDATE_IMGLOCA:
		if (cur_pt == prev_pt) break;
		else {
			cur_pt == prev_pt;
			m_strloca = { std::to_string(cur_pt.x) + "," + std::to_string(cur_pt.y) };
			m_cstrloca = CA2T(m_strloca.c_str());
			SetDlgItemText(IDC_EDIT_SELECT, m_cstrloca);
			break;
		}
	case TIMER_UPDATE_TXTLOCA:
		//m_Ptxt = m_EDIT_SHOW.GetCaretPos();
		//nTxtindex_End = m_EDIT_SHOW.CharFromPos(m_Ptxt);

		//获取光标前字符数（中文按1算） 但string中中文占两个字符
		m_EDIT_SHOW.GetSel(nTxtindex_Start, nTxtindex_End);

		//确定光标前有多少中文
		for (int i = 0; i < nTxtindex_End*2; i++)
		{
			if (m_strtxt[i] < 0)
			{
				nCharChinese++;
				nChinese = nCharChinese / 2;
			}
				
			if (i + 1 - nChinese == nTxtindex_End&&nCharChinese%2==0)
			{
				nTxtindex_End += nChinese;
				break;
			}

		}

		//光标未改变 重置中文数
		if (nTxtindex_Prev == nTxtindex_End)
		{
			nCharChinese = 0;
			nChinese = 0;
			break;
		}
		//光标改变
		else{
			//if (nTxtindex_End==0)break;
			nTxtindex_Prev = nTxtindex_End;//赋值
			
			//找第一次 如果第一行直接处理
			tpos = m_strtxt.find("\n");
			if(nTxtindex_End <= tpos)countCol = nTxtindex_End;
			countRow++; 

			//循环找出对应行列
			while (tpos != std::string::npos && nTxtindex_End >= tpos)
			{
				countCol = nTxtindex_End - tpos - 1;
				tpos = m_strtxt.find("\n", tpos + sizeof("\n"));
				countRow++;
			}

			//编辑框输入
			m_strloca = { "第" + std::to_string(countRow) + "行" + "," + "第" + std::to_string(countCol) + "个字符" };
			m_cstrloca = CA2T(m_strloca.c_str());
			SetDlgItemText(IDC_EDIT_SELECT, m_cstrloca);

			//重置变量
			countRow = 0;
			countCol = 0;
			nCharChinese = 0;
			nChinese = 0;
			
			break;
		}
		
	default:
		break;
	}
	CDialogEx::OnTimer(nIDEvent);
}


void CDlgM1tsuhaDlg::OnBnClickedButtonModeimg()
{
	// TODO: 在此添加控件通知处理程序代码	
	//关闭modetxt 打开modeimg
	if (modettxt_state == 0)KillTimer(TIMER_UPDATE_TXTLOCA);
	modettxt_state = 1;
	modetimg_state = 0;
	SetTimer(TIMER_UPDATE_IMGLOCA, 100, NULL);//WM_TIMER
}


void CDlgM1tsuhaDlg::OnBnClickedButtonModetxt()
{
	// TODO: 在此添加控件通知处理程序代码
	//关闭modeimg 打开modetxt
	if (modetimg_state == 0)KillTimer(TIMER_UPDATE_IMGLOCA);
	modettxt_state = 0;
	modetimg_state = 1;
	SetTimer(TIMER_UPDATE_TXTLOCA, 100, NULL);
}


void CDlgM1tsuhaDlg::OnBnClickedButtonLoad()
{

	// TODO: 在此添加控件通知处理程序代码
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	// 构造打开文件对话框   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	CString strFilePath;
	// 显示打开文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
		strFilePath = fileDlg.GetPathName();
		m_libpath = CT2A(strFilePath.GetString());
	}
	//读取txt文件中的info到errorlib容器中
	m_Errorlib.clear();
	std::ifstream in(m_libpath);
	std::string line;
	Errorinfo tmp_in;
	int index = 1;
	if (in) // 有该文件
	{
		while (std::getline(in, line)) // line中不包括每行的换行符
		{
			if (index % 3 == 1)tmp_in.loca = line;
			if (index % 3 == 2)tmp_in.type = line;
			if (index % 3 == 0)
			{
				tmp_in.desc = line;
				tmp_in.setinfo();
				m_Errorlib.push_back(tmp_in);
				tmp_in.clear();
			}
			index++;
		}
	}
	else // 没有该文件
	{
		exit(1);
	}
}


void CDlgM1tsuhaDlg::OnBnClickedButtonLocaaddinfo()
{
	// TODO: 在此添加控件通知处理程序代码

	//读取edit控件里的内容（鼠标响应得到的）
	GetDlgItemText(IDC_EDIT_SELECT, cloca);
	sloca = CT2A(cloca.GetString());

	//打开子框
	INT_PTR nRes;// <用于保存DoModal函数的返回值> 
	CSubDlg_1 tmpSubDlg1(this);
	m_Errors.clear();
	nRes = tmpSubDlg1.DoModal();

	if (IDOK == nRes)// <判断对话框退出后返回值是否为IDOK，则继续向下执行，否则继续向下执行>   
	{
		//此处添加点击子对话框确认按钮之后要执行的代码
		//每次调用添加子对话框添加的所有信息存入m_Errors中
		int count = 0;
		for (auto it = m_Errors.begin(); it != m_Errors.end(); it++)
		{
			count++;
		}
		std::string temp_str = { "本次操作您共添加了" + std::to_string(count) + "条信息" };
		const char* temp_char = temp_str.c_str();
		MessageBox(CA2T(temp_char));
	}
}
