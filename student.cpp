#include "student.h"
#include <iostream>
#include <string>
using namespace std;
int Student::getNumCourses(){return numCourses;}
float Student::getGPA(){return gpa;}
void Student::setGPA(float gradePointAverage){gpa = gradePointAverage;}

Student::Student(const Student& current){
  gpa = current.gpa;
}
Student::Student(){
gpa = 0.0000000;
}
Student::Student(string f, string l, int n, float g) : UniMember(f,l,n)
{
  gpa = g;
}
Student::Student(float g)
{
  gpa = g;
}
void Student::printSchedule(){
  for (int i=0;i<numCourses;i++){
    schedule[i].print();
  }
}
bool Student::addCourse(Course news){
	int holding = numCourses;
	if (holding<7){
		schedule[holding] = news;
		numCourses++;
		return(1);
	}
	return(0);
}
Student* Student::operator+=(const Course& x){
  int holding = numCourses;
  if (holding<7){
    schedule[holding] = x;
    numCourses++;
  return (this);
}
}
ostream& operator<<(ostream& out, const Student& s){
  out << s.getFirstName() << " " << s.getLastName();
  out << endl;
  return out;
}
istream& operator>>(istream& in ,Student& s){
  string f,l;
  in >> f >> l;
  s.setFirstName(f);
  s.setLastName(l);
  return in;
}
