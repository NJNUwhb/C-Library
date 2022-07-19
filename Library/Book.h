#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
using namespace std;
class Book
{
	string Code;
	string Name;
	string Author;
	int Sum; //该书所剩数量
public:
	Book(string code, string name, string au, int du);
	Book();
	~Book();
	int getsum() const;
	string getcode() const;
	string getname() const;
	string getauthor() const;
	void setcode(string code);
	void setname(string name);
	void setauthor(string author);
	void setsum(int sum);
	void lended();
	void returned();
	friend istream &operator>>(istream &in, Book &b);
	friend ostream &operator<<(ostream &out, Book &b); //输入输出函数重载
};
#endif
