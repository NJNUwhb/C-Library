#ifndef REGISTER_H
#define REGISTER_H
#include<iostream>
#include<fstream>
#include"Librarian.h"
using namespace std;
class Register{
    bool is_success;
public:
    Register();
    ~Register();
	void User_register();
	void Librarian_register();
	bool Is_success();
};
#endif