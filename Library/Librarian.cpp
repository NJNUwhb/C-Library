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
    cout << "---------------增加图书--------------" << endl;
    while (1)
    {
        cout << "请依次输入要增加的图书编号，书名，作者和数量：" << endl;
        cin >> B;
        fstream bookmessage("Bookmessage.txt", ios::app);
        if (bookmessage.is_open())
        {
            bookmessage << B.getcode() << " " << B.getname() << " " << B.getauthor() << " " << B.getsum() << endl;
            bookmessage.close();
        }
        cout << "添加成功！" << endl;
        break;
    }
}
void Librarian::Book_Del()
{
    cout << "---------------删除图书---------------" << endl;
    vector<Book> va;
    vector<Book>::iterator it;
    Book b;
    fstream file("Bookmessage.txt", ios::binary | ios::in); //打开文件
    for (Book b; file >> b;)
    {
        va.push_back(b);
    }
    file.close();
    int flag = 0;
    string str;
    while (1)
    {
        cout << "请输入要删除的图书编号" << endl;
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
            cout << "没有此图书！" << endl;
            continue;
        }
        cout << "目前所剩书籍：" << endl;
        for (int i = 0; i < va.size(); i++)
        {
            cout << va[i].getcode() << " " << va[i].getname() << " " << va[i].getauthor() << endl;
        }
        if (flag == 1)
        {
            cout << "删除成功！" << endl;
            break;
        }
    }
    fstream file1("Bookmessage.txt", ios::out | ios::trunc);
    for (int i = 0; i < va.size(); i++)
    {
        file1 << va[i].getcode() << " " << va[i].getname() << " " << va[i].getauthor() << " " << va[i].getsum() << endl;
        //将未删除的图书写入文件
    }
    file1.close();
}
void Librarian::Book_Alter()
{
    vector<Book> vec;
    string a; //存放要修改的内容
    int flag = 0;
    int i;
    cout << "---------------修改图书---------------" << endl;
    fstream file("Bookmessage.txt", ios::binary | ios::in);
    for (Book b; file >> b;)
    {
        vec.push_back(b);
    }
    file.close();
    while (1)
    {
        cout << "请输入要修改的书本编号:" << endl;
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
        cout << "请输入要修改的内容:" << endl;
        cout << "1-修改编号" << endl;
        cout << "2-修改书名" << endl;
        cout << "3-修改作者" << endl;
        cout << "4-修改数量" << endl;
        cout << "0-退出界面" << endl;
        int c;
        cin >> c;
        switch (c)
        {
        case 1:
        {
            cout << "请输入修改后的编号" << endl;
            cin >> a;
            vec[i].setcode(a);
            cout << "修改成功!" << endl;
            break;
        }
        case 2:
        {
            cout << "请输入修改后的书名:" << endl;
            cin >> a;
            vec[i].setname(a);
            cout << "修改成功!" << endl;
            break;
        }
        case 3:
        {
            cout << "请输入修改后的作者名:" << endl;
            cin >> a;
            vec[i].setauthor(a);
            cout << "修改成功!" << endl;
            break;
        }
        case 4:
        {
            int aa;
            cout << "请输入修改后的数量:" << endl;
            cin >> aa;
            vec[i].setsum(aa);
            cout << "修改成功！" << endl;
        }
        case 0:
        {
            fstream file("Bookmessage.txt", ios::out | ios::trunc);
            cout << "退出界面" << endl;
            for (int j = 0; j < vec.size(); j++)
            {
                file << vec[j].getcode() << " " << vec[j].getname() << " " << vec[j].getauthor() << " " << vec[j].getsum() << endl;
            }
            file.close();
            break;
        }
        default:
            cout << "输入错误字符！请重新输入！" << endl;
        }
        if (c == 0)
            break;
        cin.get(); //吸收回车符
        cout << "按回车键返回原界面\n";
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
        cout << "请输入要查看的书本编号:" << endl;
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
            cout << "找不到该书！请重新输入！" << endl;
            continue;
        }
        if (flag == 1)
        {
            cout << "已找到图书：" << endl;
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