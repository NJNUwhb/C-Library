#ifndef USER_H
#define USER_H
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class User{
	string ID;//�û���(ѧ��)
    string Name;//�û�����
    string Key;//�û�����
public:
	User();
	User(string id,string name,string key);
	~User();
	string GetID()const;
    string Getname()const;
    string Getkey()const;
    void SetID(string id);
    void Setname(string name);
    void SetKey(string key);
	User& operator =(User& u);
    friend istream& operator >> (istream &in, User &u);
    friend ostream& operator << ( ostream &out,User &u);//���������������
};
#endif