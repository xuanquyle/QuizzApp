#pragma once
#include <string>
#include <iostream>
using namespace std;
class Question
{
private:
	string QT;	//Question
	string A;	//Answer A B C 
	string B;
	string C;
	string True_AS;
public:
	Question(string QT=NULL,string A=NULL,string B=NULL,string C=NULL,string True_AS=NULL);
	string getTrue_AS() const;
	friend ostream& operator<<(ostream& out,const Question& q);
	~Question(void);
};

