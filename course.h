#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <string>
using namespace std;

class Course{
	string prefix;
  int number;
  string name;

	public:
		Course();
		Course(const Course&);
		Course(string, int , string);
		int getNumber()const;
		void setNumber(int);
		string getName()const;
		void setName(string);
		string getPrefix()const;
		void setPrefix(string);
		void print();
		friend ostream& operator<<(ostream&, const Course&);
	 	friend istream& operator>>(istream&,Course&);
	};
#endif
