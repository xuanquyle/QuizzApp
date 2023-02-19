#pragma once
#include "Person.h"
#include <cstdlib>
#include<iostream>
class Contestants : public Person
{
	const int key;
	int score;
public:
	Contestants(string ="", string ="", int =0);
	void setCon(string, string,int );
	int setKey();
	int getKey() const;
	int getScore();
	friend ostream& operator<<(ostream& out,const Contestants& p);
	friend istream& operator>>(istream& in,Contestants &p);
	void inText();
	~Contestants(void);
};

