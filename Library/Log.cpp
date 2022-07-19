#ifndef LOG_CPP
#define LOG_CPP
#include <iostream>
#include "Log.h"
using namespace std;
Log::Log()
{
    User u;
    Librarian l;
}
Log::~Log()
{
}
void Log::User_log()
{
    is_success = false;
    string id, key;
    int i;
    vector<User> vec;
    fstream file("Usermessage.txt", ios::binary | ios::in);
    for (User u; file >> u;)
    {
        vec.push_back(u);
    }
    file.close();
    cout << "��ע���û���" << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i].GetID() << endl;
    }
    while (1)
    {
        cout << "�������û�����" << endl;
        cin >> id;
        cout << "���������룺" << endl;
        cin >> key;
        for (i = 0; i < vec.size(); i++)
        {
            if (vec[i].GetID() == id && vec[i].Getkey() == key)
            {
                is_success = true;
                break;
            }
        }
        if (is_success == false)
        {
            cout << "�û�����������������µ�¼��" << endl;
            continue;
        }
        if (is_success == true)
        {
            break;
        }
    }
    U = vec[i];
}
void Log::Librarian_log()
{
    is_success = false;
    string id, key;
    int i;
    vector<Librarian> va;
    fstream file("Libmessage.txt", ios::binary | ios::in);
    for (Librarian l; file >> l;)
    {
        va.push_back(l);
    }
    file.close();
    cout << "��ע�����Ա��" << endl;
    for (int i = 0; i < va.size(); i++)
    {
        cout << va[i].GetID() << endl;
    }
    while (1)
    {
        cout << "�������û�����" << endl;
        cin >> id;
        cout << "���������룺" << endl;
        cin >> key;
        for (int i = 0; i < va.size(); i++)
        {
            if (va[i].GetID() == id && va[i].Getkey() == key)
            {
                is_success = true;
                break;
            }
        }
        if (is_success == false)
        {
            cout << "�û�����������������µ�½��" << endl;
            continue;
        }
        if (is_success == true)
        {
            L.SetID(id);
            L.SetKey(key);
            break;
        }
    }
}
bool Log::Is_success()
{
    return is_success;
}

#endif