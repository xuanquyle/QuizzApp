#include "Question.h"


Question::Question(string QT,string A,string B,string C,string True_AS)
{
	this->QT=QT;
	this->A=A;
	this->B=B;
	this->C=C;
	this->True_AS=True_AS;
}
ostream& operator<<(ostream& out,const Question& q)
{
	out<<q.QT<<endl;
	out<<q.A<<endl;
	out<<q.B<<endl;
	out<<q.C<<endl;
	return out;
}
string Question::getTrue_AS() const
{
	return this->True_AS;
}
Question::~Question(void)
{
}
