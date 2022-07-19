#ifndef USER_CPP
#define USER_CPP
#include <iostream>
#include "User.h"
using namespace std;
User::User()
{
    ID = 1;
    Name = 1;
    Key = 1;
}
User::User(string id, string name, string key)
{
    ID = id;
    Name = name;
    Key = key;
}
User::~User()
{
}
string User::GetID() const
{
    return ID;
}
string User::Getkey() const
{
    return Key;
}
string User::Getname() const
{
    return Name;
}
void User::SetID(string id)
{
    ID = id;
}
void User::SetKey(string key)
{
    Key = key;
}
void User::Setname(string name)
{
    Name = name;
}
User &User::operator=(User &u)
{
    ID = u.ID;
    Name = u.Name;
    Key = u.Key;
    return *this;
}
ostream &operator<<(ostream &out, User &u)
{
    out << "用户名:" << u.GetID() << " "
        << "姓名:" << u.Getname() << endl;
    return out;
}
istream &operator>>(istream &in, User &u)
{
    in >> u.ID >> u.Name >> u.Key;
    return in;
}

#endif