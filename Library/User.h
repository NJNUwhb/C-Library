#ifndef USER_H
#define USER_H
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class User{
	string ID;//用户名(学号)
    string Name;//用户姓名
    string Key;//用户密码
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
    friend ostream& operator << ( ostream &out,User &u);//输入输出函数重载
};
#endif