#ifndef LIBRARIAN_CPP
#define LIBRARIAN_CPP
#include <iostream>
#include <vector>
#include "Librarian.h"
using namespace std;

Librarian::Librarian()
{
}
Librarian::Librarian(string id, string key)
{
    ID = id;
    Key = key;
}
Librarian::~Librarian()
{
}
void Librarian::SetID(string id)
{
    ID = id;
}
void Librarian::SetKey(string key)
{
    Key = key;
}
string Librarian::GetID() const
{
    return ID;
}
string Librarian::Getkey() const
{
    return Key;
}
void Librarian::Book_Add()
{
    Book B;
    string a;
    string code, name, author;
    cout << "---------------����ͼ��--------------" << endl;
    while (1)
    {
        cout << "����������Ҫ���ӵ�ͼ���ţ����������ߺ�������" << endl;
        cin >> B;
        fstream bookmessage("Bookmessage.txt", ios::app);
        if (bookmessage.is_open())
        {
            bookmessage << B.getcode() << " " << B.getname() << " " << B.getauthor() << " " << B.getsum() << endl;
            bookmessage.close();
        }
        cout << "��ӳɹ���" << endl;
        break;
    }
}
void Librarian::Book_Del()
{
    cout << "---------------ɾ��ͼ��---------------" << endl;
    vector<Book> va;
    vector<Book>::iterator it;
    Book b;
    fstream file("Bookmessage.txt", ios::binary | ios::in); //���ļ�
    for (Book b; file >> b;)
    {
        va.push_back(b);
    }
    file.close();
    int flag = 0;
    string str;
    while (1)
    {
        cout << "������Ҫɾ����ͼ����" << endl;
        cin >> str;
        for (it = va.begin(); it != va.end(); it++)
        {
            if (str == it->getcode())
            {
                flag = 1;
                va.erase(it);
                break;
            }
        }
        if (flag != 1)
        {
            cout << "û�д�ͼ�飡" << endl;
            continue;
        }
        cout << "Ŀǰ��ʣ�鼮��" << endl;
        for (int i = 0; i < va.size(); i++)
        {
            cout << va[i].getcode() << " " << va[i].getname() << " " << va[i].getauthor() << endl;
        }
        if (flag == 1)
        {
            cout << "ɾ���ɹ���" << endl;
            break;
        }
    }
    fstream file1("Bookmessage.txt", ios::out | ios::trunc);
    for (int i = 0; i < va.size(); i++)
    {
        file1 << va[i].getcode() << " " << va[i].getname() << " " << va[i].getauthor() << " " << va[i].getsum() << endl;
        //��δɾ����ͼ��д���ļ�
    }
    file1.close();
}
void Librarian::Book_Alter()
{
    vector<Book> vec;
    string a; //���Ҫ�޸ĵ�����
    int flag = 0;
    int i;
    cout << "---------------�޸�ͼ��---------------" << endl;
    fstream file("Bookmessage.txt", ios::binary | ios::in);
    for (Book b; file >> b;)
    {
        vec.push_back(b);
    }
    file.close();
    while (1)
    {
        cout << "������Ҫ�޸ĵ��鱾���:" << endl;
        cin >> a;
        for (i = 0; i < vec.size(); i++)
        {
            if (a == vec[i].getcode())
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            continue;
        if (flag == 1)
            break;
    }
    while (1)
    {
        cout << "������Ҫ�޸ĵ�����:" << endl;
        cout << "1-�޸ı��" << endl;
        cout << "2-�޸�����" << endl;
        cout << "3-�޸�����" << endl;
        cout << "4-�޸�����" << endl;
        cout << "0-�˳�����" << endl;
        int c;
        cin >> c;
        switch (c)
        {
        case 1:
        {
            cout << "�������޸ĺ�ı��" << endl;
            cin >> a;
            vec[i].setcode(a);
            cout << "�޸ĳɹ�!" << endl;
            break;
        }
        case 2:
        {
            cout << "�������޸ĺ������:" << endl;
            cin >> a;
            vec[i].setname(a);
            cout << "�޸ĳɹ�!" << endl;
            break;
        }
        case 3:
        {
            cout << "�������޸ĺ��������:" << endl;
            cin >> a;
            vec[i].setauthor(a);
            cout << "�޸ĳɹ�!" << endl;
            break;
        }
        case 4:
        {
            int aa;
            cout << "�������޸ĺ������:" << endl;
            cin >> aa;
            vec[i].setsum(aa);
            cout << "�޸ĳɹ���" << endl;
        }
        case 0:
        {
            fstream file("Bookmessage.txt", ios::out | ios::trunc);
            cout << "�˳�����" << endl;
            for (int j = 0; j < vec.size(); j++)
            {
                file << vec[j].getcode() << " " << vec[j].getname() << " " << vec[j].getauthor() << " " << vec[j].getsum() << endl;
            }
            file.close();
            break;
        }
        default:
            cout << "��������ַ������������룡" << endl;
        }
        if (c == 0)
            break;
        cin.get(); //���ջس���
        cout << "���س�������ԭ����\n";
        cin.get();
    }
}
void Librarian::Book_Find()
{
    string str;
    int flag = 0;
    int i = 0;
    fstream books("Bookmessage.txt");
    vector<Book> vec;
    for (Book b; books >> b;)
    {
        vec.push_back(b);
    }
    books.close();
    while (1)
    {
        string a;
        cout << "������Ҫ�鿴���鱾���:" << endl;
        cin >> a;
        for (i = 0; i < vec.size(); i++)
        {
            if (a == vec[i].getcode())
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "�Ҳ������飡���������룡" << endl;
            continue;
        }
        if (flag == 1)
        {
            cout << "���ҵ�ͼ�飺" << endl;
            cout << vec[i];
            break;
        }
    }
}
Librarian &Librarian::operator=(Librarian &l)
{
    ID = l.ID;
    Key = l.Key;
    return *this;
}
istream &operator>>(istream &in, Librarian &l)
{
    in >> l.ID >> l.Key;
    return in;
}
#endif