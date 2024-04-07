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
        //�滻info�����е�"\n"Ϊ"\r\n"
        std::string sub_str = "\n";
        std::string mod_str = "\r";
        std::size_t pos = info.find(sub_str);
        //����str ��"\n"֮ǰ����"\r"
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
        std::ofstream os;     //����һ���ļ����������
        os.open(path, std::ios::app);//���������ļ�����
        os<<info.c_str();   //����������ݷ���txt�ļ���
        os.close();
    }
    const char* outall()
    {
        std::string out;
        out = { loca + "\n" + type + "\n" + desc + "\n"  };
        return out.c_str();
    }
};
