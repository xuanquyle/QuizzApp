#include "ListQT.h"


ListQT::ListQT(void)
{
	this->head=NULL;
	this->tail=NULL;
}
void ListQT::addTail(Question*a)
{
	if(this->head==NULL)
		this->head=this->tail=a;
	else 
	{
		this->tail->setNext(a);
		this->tail=a;
	}
}
Question* ListQT::getHead()
{
	return this->head;
}
void ListQT::SetList(string FileName)
{
	ifstream f(FileName);
	string a[5];
	int i=0,temp=0;
	while(getline(f,a[i])||temp<5)
	{
		if(i!=4)
			i++;
		else
		{
			Question*q=new Question(0,a[0],a[1],a[2], a[3],a[4]);
			addTail(q);
			i=0;
		}
		temp++;
	}
	f.close();
}
bool ListQT::Check()
{
	Question* p=this->head;
	while(p)
	{
		if(p->getSTT()==0) return false;
		p=p->getNext();
	}
	return true;
}
ostream& operator<<(ostream& out,const ListQT &l)
{
	Question* p;
	p=l.head;
	while(p!=NULL)
	{
		cout<<*p;
		p=p->getNext();
	}
	return out;
}
ListQT::~ListQT(void)
{
}
