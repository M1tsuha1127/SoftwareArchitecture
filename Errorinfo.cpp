#define _CRT_SECURE_NO_WARNINGS 1
#include "pch.h"
#include "Errorinfo.h"

void Errorinfo::readinfo(CString cstr1, CString cstr2, CString cstr3)
{
    loca = CT2A(cstr1.GetString());
    type = CT2A(cstr2.GetString());
    desc = CT2A(cstr3.GetString());
    info = { loca + "\n" + type + "\n" + desc + "\n" };
}
void Errorinfo::getcstr(CString cstr)
{
    cstr = CA2T(info.c_str());
}
bool Errorinfo::isfound(CString cstr)
{
    std::string keywords = CT2A(cstr.GetString());
    int index = info.find(keywords, 0);
    if (index > 0 && index < info.length() - keywords.length()) return TRUE;
    else return FALSE;
}