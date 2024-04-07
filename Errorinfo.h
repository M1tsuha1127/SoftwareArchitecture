#pragma once
#include <afx.h>
#include <fstream>
#include <stdio.h>
#include <string>
#include <iostream>

class Errorinfo
{
public:
    Errorinfo()
    {

    }

    Errorinfo(CString cstr1, CString cstr2, CString cstr3)
    {
        loca = CT2A(cstr1.GetString());
        type = CT2A(cstr2.GetString());
        desc = CT2A(cstr3.GetString());
        info = { loca + "\n" + type + "\n" + desc + "\n" };
    }

    ~Errorinfo()
    {
    }

public:
    std::string loca;
    std::string type;
    std::string desc;
    std::string info;
public:
    void readinfo(CString cstr1, CString cstr2, CString cstr3);
    void setinfo()
    {
        info = { loca + "\n" + type + "\n" + desc + "\n" };
    }
    void clear()
    {
        loca.clear();
        type.clear();
        desc.clear();
        info.clear();
    }
    std::string infoinsertr()
    {
        //替换info中所有的"\n"为"\r\n"
        std::string sub_str = "\n";
        std::string mod_str = "\r";
        std::size_t pos = info.find(sub_str);
        //遍历str 在"\n"之前插入"\r"
        while (pos != std::string::npos)
        {
            info.insert(pos, mod_str);
            pos++;
            pos = info.find(sub_str, pos + sub_str.size());
        }
        return info;
    }
    void getcstr(CString cstr);
    bool isfound(CString cstr);
    void writetxt(const char* path)
    {
        std::ofstream os;     //创建一个文件输出流对象
        os.open(path, std::ios::app);//将对象与文件关联
        os<<info.c_str();   //将输入的内容放入txt文件中
        os.close();
    }
    const char* outall()
    {
        std::string out;
        out = { loca + "\n" + type + "\n" + desc + "\n"  };
        return out.c_str();
    }
};
