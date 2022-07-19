#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "Book.h"
#include "Librarian.h"
#include "Log.h"
#include "Register.h"
#include "User.h"
#include "Menus.h"
using namespace std;

int main()
{
    SYSTEMTIME sys;
    GetLocalTime(&sys);
    fstream books("Bookmessage.txt");
    vector<Book> vec;
    for (Book b; books >> b;)
    {
        vec.push_back(b);
    }
    books.close();
    Register reg;
    Log log;
    int a;
    while (1)
    {
        a = menu();
        switch (a)
        {
        case 1:
        {
            cout << "用户注册中……" << endl;
            reg.User_register();
            if (reg.Is_success() == true)
                break;
        }
        case 2:
        {
            cout << "管理员注册中……" << endl;
            reg.Librarian_register();
            if (reg.Is_success() == true)
                break;
        }

        case 3:
        {
            log.User_log();
            if (log.Is_success() == true)
                cout << "登陆成功!" << endl;
            cout << "尊敬的用户" << log.U.Getname() << "你好！" << endl;
            cout << "请选择：" << endl;
            while (1)
            {
                int x;
                x = reader_menu();
                switch (x)
                {
                case 1:
                {
                    for (int i = 0; i < vec.size(); i++)
                    {
                        cout << vec[i] << endl;
                    }
                    break;
                }
                case 2:
                {
                    string str;
                    int flag = 0, i = 0;
                    while (1)
                    {
                        cout << "请输入想借的图书编号:" << endl;
                        cin >> str;
                        for (i = 0; i < vec.size(); i++)
                        {
                            if (vec[i].getcode() == str)
                            {
                                flag = 1;
                                break;
                            }
                        }
                        if (vec[i].getsum() == 0)
                        {
                            flag = 0;
                        }
                        if (flag == 0)
                        {
                            cout << "不存在此图书或已被借完，请重新输入！" << endl;
                            continue;
                        }
                        if (flag == 1)
                            cout << "借书成功！" << endl;
                        break;
                    }
                    fstream lend("Lendmessage.txt", ios::out | ios::app);
                    lend << vec[i].getname() << "于" << sys.wYear << "-" << sys.wMonth << "-" << sys.wDay << "-" << sys.wHour << ":" << sys.wMinute << "被" << log.U.Getname() << "借出." << endl;
                    vec[i].lended();
                    lend.close();
                    break;
                }
                case 3:
                {
                    string str1;
                    int flag1 = 0, i = 0;
                    while (1)
                    {
                        cout << "请输入要还的图书编号:" << endl;
                        cin >> str1;
                        for (i = 0; i < vec.size(); i++)
                        {
                            if (vec[i].getcode() == str1)
                            {
                                flag1 = 1;
                                break;
                            }
                        }
                        if (flag1 == 0)
                        {
                            cout << "不存在此图书，请重新输入！" << endl;
                            continue;
                        }
                        if (flag1 == 1)
                            cout << "还书成功！" << endl;
                        break;
                    }
                    fstream re("Returnmessage.txt", ios::out | ios::app);
                    re << vec[i].getname() << "于" << sys.wYear << "-" << sys.wMonth << "-" << sys.wDay << "-" << sys.wHour << ":" << sys.wMinute << "被" << log.U.Getname() << "交还." << endl;

                    vec[i].returned();
                    re.close();
                    break;
                }
                case 4:
                {
                    break;
                }
                }
                if (x == 4)
                    break;
                cin.get(); //吸收回车符
                cout << "按回车键返回原界面\n";
                cin.get();
            }
            break;
        }

        case 4:
        {
            log.Librarian_log();
            if (log.Is_success() == true)
                cout << "登陆成功!" << endl;
            cout << "尊敬的管理员" << log.L.GetID() << "你好！" << endl;
            cout << "请选择：" << endl;
            int y;

            while (1)
            {
                y = lib_menu();
                switch (y)
                {
                case 1:
                    log.L.Book_Add();
                    break;
                case 2:
                    log.L.Book_Del();
                    break;
                case 3:
                    log.L.Book_Alter();
                    break;
                case 4:
                    log.L.Book_Find();
                    break;
                case 5:
                    break;
                }
                if (y == 5)
                    break;
                cin.get(); //吸收回车符
                cout << "按回车键返回原界面\n";
                cin.get();
            }
            break;
        }
        case 5:
        {
            cout << "系统已退出" << endl;
            return 0;
            break;
        }
        default:
            break;
        }
        cin.get(); //吸收回车符
        cout << "按回车键返回主界面\n";
        cin.get();
    }

    return 0;
}