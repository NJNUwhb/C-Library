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
            cout << "�û�ע���С���" << endl;
            reg.User_register();
            if (reg.Is_success() == true)
                break;
        }
        case 2:
        {
            cout << "����Աע���С���" << endl;
            reg.Librarian_register();
            if (reg.Is_success() == true)
                break;
        }

        case 3:
        {
            log.User_log();
            if (log.Is_success() == true)
                cout << "��½�ɹ�!" << endl;
            cout << "�𾴵��û�" << log.U.Getname() << "��ã�" << endl;
            cout << "��ѡ��" << endl;
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
                        cout << "����������ͼ����:" << endl;
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
                            cout << "�����ڴ�ͼ����ѱ����꣬���������룡" << endl;
                            continue;
                        }
                        if (flag == 1)
                            cout << "����ɹ���" << endl;
                        break;
                    }
                    fstream lend("Lendmessage.txt", ios::out | ios::app);
                    lend << vec[i].getname() << "��" << sys.wYear << "-" << sys.wMonth << "-" << sys.wDay << "-" << sys.wHour << ":" << sys.wMinute << "��" << log.U.Getname() << "���." << endl;
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
                        cout << "������Ҫ����ͼ����:" << endl;
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
                            cout << "�����ڴ�ͼ�飬���������룡" << endl;
                            continue;
                        }
                        if (flag1 == 1)
                            cout << "����ɹ���" << endl;
                        break;
                    }
                    fstream re("Returnmessage.txt", ios::out | ios::app);
                    re << vec[i].getname() << "��" << sys.wYear << "-" << sys.wMonth << "-" << sys.wDay << "-" << sys.wHour << ":" << sys.wMinute << "��" << log.U.Getname() << "����." << endl;

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
                cin.get(); //���ջس���
                cout << "���س�������ԭ����\n";
                cin.get();
            }
            break;
        }

        case 4:
        {
            log.Librarian_log();
            if (log.Is_success() == true)
                cout << "��½�ɹ�!" << endl;
            cout << "�𾴵Ĺ���Ա" << log.L.GetID() << "��ã�" << endl;
            cout << "��ѡ��" << endl;
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
                cin.get(); //���ջس���
                cout << "���س�������ԭ����\n";
                cin.get();
            }
            break;
        }
        case 5:
        {
            cout << "ϵͳ���˳�" << endl;
            return 0;
            break;
        }
        default:
            break;
        }
        cin.get(); //���ջس���
        cout << "���س�������������\n";
        cin.get();
    }

    return 0;
}