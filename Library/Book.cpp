#ifndef BOOK_CPP
#define BOOK_CPP
#include <iostream>
#include <fstream>
#include <vector>
#include "Book.h"
using namespace std;

Book::Book(string code, string name, string au, int du)
{
    Code = code;
    Name = name;
    Author = au;
    Sum = 30;
}

Book::Book()
{
    Code = 1;
    Name = 1;
    Author = 1;
    Sum = 30;
}
Book::~Book()
{

}
int Book::getsum() const
{
    return Sum;
}
string Book::getcode()const
{
    return Code;
}
string Book::getname()const
{
    return Name;
}
string Book::getauthor()const
{
    return Author;
}
void Book::setcode(string code)
{
    Code = code;
}
void Book::setname(string name)
{
    Name = name;
}
void Book::setauthor(string author)
{
    Author = author;
}
void Book::setsum(int sum)
{
    Sum = sum;
}
void Book::lended()
{
    vector<Book> vec;
    fstream file("Bookmessage.txt", ios::in);
    for (Book b; file >> b;)
    {
        vec.push_back(b);
    }
    file.close();
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i].getcode() == Code)
        {
            vec[i].Sum--;
            break;
        }
    }
    fstream file1("Bookmessage.txt", ios::out | ios::trunc);
    for (int i = 0; i < vec.size(); i++)
    {
        file1 << vec[i].getcode() << " " << vec[i].getname() << " " << vec[i].getauthor() << " " << vec[i].getsum() << endl;
    }
    file1.close();
}
void Book::returned()
{
    vector<Book> vec;
    fstream file("Bookmessage.txt", ios::in);
    for (Book b; file >> b;)
    {
        vec.push_back(b);
    }
    file.close();
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i].getcode() == Code)
        {
            vec[i].Sum++;
            break;
        }
    }
    fstream file1("Bookmessage.txt", ios::out | ios::trunc);
    for (int i = 0; i < vec.size(); i++)
    {
        file1 << vec[i].getcode() << " " << vec[i].getname() << " " << vec[i].getauthor() << " " << vec[i].getsum() << endl;
    }
    file1.close();
}
ostream &operator<<(ostream &out, Book &b)
{
    out << "??:" << b.getcode() << " "
        << "??:"
        << b.getname() << " "
        << "??:" << b.getauthor() << " ????:" << b.getsum() << endl;
    return out;
}
istream &operator>>(istream &in, Book &b)
{
    in >> b.Code >> b.Name >> b.Author >> b.Sum;
    return in;
}
#endif