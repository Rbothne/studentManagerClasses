#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include "unimember.h"
using namespace std;

class Student: public UniMember{
	int numCourses;
	float gpa;
	Course schedule[7];

	public:
		Student();
		Student(const Student&);
		Student(float);
		Student(string, string , int, float);
		int getNumCourses();
		float getGPA();
		void setGPA(float);
		bool addCourse(Course);
		void printSchedule();
		Student* operator+=(const Course&);
		friend ostream& operator<<(ostream& out, const Student& s);
	 	friend istream& operator>>(istream& in,Student& s);
	};
#endif
