#ifndef LOG_H
#define LOG_H
#include <iostream>
#include <fstream>
#include <vector>
#include "Librarian.h"
using namespace std;
class Log
{
    bool is_success;

public:
    User U;
    Librarian L;
    Log();
    ~Log();
    void User_log();
    void Librarian_log();
    bool Is_success();
};
#endif