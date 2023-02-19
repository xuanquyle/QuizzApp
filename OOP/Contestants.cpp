#include "Contestants.h"
#include<ctime>
#include<fstream>

Contestants::Contestants(string a, string b, int e):key(setKey()) ,Person(a,b)
{
	score=e;
}
void Contestants:: setCon(string a, string b,int e)
{
	name=b;
	id=a;
	score=e;
}
int Contestants::setKey()
{
	srand(time(NULL));
	int a = rand() % (9 - 1 + 1) + 1;
	return a; 
}
int Contestants::getKey() const
{
	return key;
}
int Contestants::getScore()
{
	return score;
}
ostream& operator<<(ostream& out,const Contestants& p)
{
	out<<(Person)p;
	out<<"Exam paper code "<<p.key<<endl;
	out<<"Correct answers: "<<p.score<<"/5"<<endl;
	out<<"Total point of quiz: "<<p.score*2<<endl;
	return out;
}
istream& operator>>(istream& in,Contestants &p)
{
	cout<<"Your ID: ";getline(in,p.id);
	cout<<"Your Name: ";getline(in,p.name);
	return in;
}
void Contestants:: inText()
{
	string a="KQ_De";
	a=a+(char)(this->getKey()+48)+".txt";
	
	int i=1, j=1;
	char* temp=new char();
	ifstream f(a);
	while(f>>temp)
	{
		
		if(j%4==0)
			if(this->getScore()<=atoi(temp))
				i++;
		j++;
	}
	f.close();
	ofstream f1(a,ios::app);
	f1<<this->getId();
	f1<<endl;
	f1<<this->getName();
	f1<<endl;
	f1<<this->getKey();
	f1<<endl;
	f1<<this->getScore();
	f1<<endl;
	f1.close();
	cout<< "Hang "<<i<<"/"<<(((j/4)+1)>=1?((j/4)+1):1)<<endl;
}
Contestants::~Contestants(void)
{
}
