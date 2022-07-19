#ifndef LIBRARIAN_H
#define LIBRARIAN_H
#include <iostream>
#include <string>
#include "Book.h"
#include "User.h"
using namespace std;
class Librarian
{
    string ID;  //用户名
    string Key; //密码
public:
    Librarian();
    Librarian(string id, string key);
    ~Librarian();
    void SetID(string id);
    void SetKey(string key);
    string GetID() const;
    string Getkey() const;
    //增加图书
    void Book_Add();
    //删除图书
    void Book_Del();
    //修改图书
    void Book_Alter();
    //查找图书
    void Book_Find();
    //等号重载
    Librarian &operator=(Librarian &l);
    //>>重载
    friend istream &operator>>(istream &in, Librarian &l);
};
#endif