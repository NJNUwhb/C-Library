#ifndef LIBRARIAN_H
#define LIBRARIAN_H
#include <iostream>
#include <string>
#include "Book.h"
#include "User.h"
using namespace std;
class Librarian
{
    string ID;  //�û���
    string Key; //����
public:
    Librarian();
    Librarian(string id, string key);
    ~Librarian();
    void SetID(string id);
    void SetKey(string key);
    string GetID() const;
    string Getkey() const;
    //����ͼ��
    void Book_Add();
    //ɾ��ͼ��
    void Book_Del();
    //�޸�ͼ��
    void Book_Alter();
    //����ͼ��
    void Book_Find();
    //�Ⱥ�����
    Librarian &operator=(Librarian &l);
    //>>����
    friend istream &operator>>(istream &in, Librarian &l);
};
#endif