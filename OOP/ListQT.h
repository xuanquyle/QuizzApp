#pragma once
#include "Question.h"
#include <fstream>
class ListQT
{
private:
	Question* head;
	Question* tail;
public:
	ListQT(void);
	void addTail(Question*);
	Question* getHead();
	void SetList(string FileName);
	bool Check();
	friend ostream& operator<<(ostream& out,const ListQT &l);
	~ListQT(void);
};

