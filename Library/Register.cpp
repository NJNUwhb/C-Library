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
    cout << "�������û���:";
    cin >> a;
    cout << "�������û�����:" << endl;
    cin >> name;
    cout << "�������û�����:" << endl;
    cin >> b;
    cout << "���ٴ���������:" << endl;
    cin >> bb;
    if (bb != b)
    {
        cout << "�������벻һ�£�����������" << endl;
        is_success = false;
    }
    if (bb == b)
    {
        cout << "ע��ɹ���" << endl;
        is_success = true;
    }
    if (is_success == true)
    {
        U.SetID(a);
        U.SetKey(b);
        U.Setname(name);
        fstream file("Usermessage.txt", ios::out | ios::app);
        file << " " << U.GetID() << " " << U.Getname() << " " << U.Getkey() << endl; //д���ļ�
        file.close();
    }
}
void Register::Librarian_register()
{
    Librarian Lib;
    string a, b, bb;
    cout << "�������û���:";
    cin >> a;
    cout << "����������:" << endl;
    cin >> b;
    cout << "���ٴ���������:" << endl;
    cin >> bb;
    if (bb != b)
    {
        cout << "�����������벻һ�£����������룡" << endl;
        is_success = false;
    }
    if (bb == b)
    {
        cout << "ע��ɹ���" << endl;
        is_success = true;
    }
    if (is_success == true)
    {
        Lib.SetID(a);
        Lib.SetKey(b);
        fstream file("Libmessage.txt", ios::out | ios::binary | ios::app);
        file << " " << Lib.GetID() << " " << Lib.Getkey() << endl; //��ע��ɹ��Ĺ���Ա��Ϣд���ļ�
        file.close();
    }
}
bool Register::Is_success()
{
    return is_success;
}
#endif