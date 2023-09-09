#ifndef UNIMEMBER_H
#define UNIMEMBER_H
#include <iostream>
#include <string>
#include "course.h"
using namespace std;
class UniMember{
	int number;
	string firstName;
	string lastName;
	public:
		UniMember();
		UniMember(const UniMember&);
		UniMember(string, string , int);
		int getNumber();
		void setNumber(int);
    void print();
		string getFirstName()const;
		void setFirstName(string);
		string getLastName()const;
		void setLastName(string);
	};
#endif
