#include "Person.h"


Person::Person(string id,string name)
{
	this->id=id;
	this->name=name;
}
void Person::setId(string id)
{
	if(id!="")
		this->id=id;
}
void Person::setName(string name)
{
	if(name!="")
		this->name=name;
}
string Person::getId() const
{
	return this->id;
}
string Person::getName() const
{
	return this->name;
}
ostream& operator<<(ostream& out,const Person& p)
{
	out<<"Your ID: "<<p.id<<endl;
	out<<"Your Name: "<<p.name<<endl;
	return out;
}
istream& operator>>(istream& in,Person &p)
{
	cout<<"Your ID: ";
		in>>p.id;
	cout<<"Your Name: ";
		in>>p.name;
	return in;
}
Person::~Person(void)
{
}
