#ifndef REGISTER_CPP
#define REGISTER_CPP
#include <iostream>
#include "Register.h"
using namespace std;
Register::Register()
{
    User u;
    Librarian l;
}
Register::~Register()
{
}
void Register::User_register()
{
    User U;
    string a, name, b, bb;
    cout << "请输入用户名:";
    cin >> a;
    cout << "请输入用户姓名:" << endl;
    cin >> name;
    cout << "请输入用户密码:" << endl;
    cin >> b;
    cout << "请再次输入密码:" << endl;
    cin >> bb;
    if (bb != b)
    {
        cout << "两次密码不一致，请重新输入" << endl;
        is_success = false;
    }
    if (bb == b)
    {
        cout << "注册成功！" << endl;
        is_success = true;
    }
    if (is_success == true)
    {
        U.SetID(a);
        U.SetKey(b);
        U.Setname(name);
        fstream file("Usermessage.txt", ios::out | ios::app);
        file << " " << U.GetID() << " " << U.Getname() << " " << U.Getkey() << endl; //写入文件
        file.close();
    }
}
void Register::Librarian_register()
{
    Librarian Lib;
    string a, b, bb;
    cout << "请输入用户名:";
    cin >> a;
    cout << "请输入密码:" << endl;
    cin >> b;
    cout << "请再次输入密码:" << endl;
    cin >> bb;
    if (bb != b)
    {
        cout << "两次密码输入不一致！请重新输入！" << endl;
        is_success = false;
    }
    if (bb == b)
    {
        cout << "注册成功！" << endl;
        is_success = true;
    }
    if (is_success == true)
    {
        Lib.SetID(a);
        Lib.SetKey(b);
        fstream file("Libmessage.txt", ios::out | ios::binary | ios::app);
        file << " " << Lib.GetID() << " " << Lib.Getkey() << endl; //将注册成功的管理员信息写入文件
        file.close();
    }
}
bool Register::Is_success()
{
    return is_success;
}
#endif