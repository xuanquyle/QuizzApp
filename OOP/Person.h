#pragma once
#include <iostream>
#include <string>
using namespace std;
class Person
{
protected:
	string id;
	string name;
public:
	Person(string id="",string name="");
	void setId(string);
	void setName(string);
	string getId() const;
	string getName() const;
	friend ostream& operator<<(ostream& out,const Person& p);
	friend istream& operator>>(istream& in,Person &p);
	~Person(void);
};

