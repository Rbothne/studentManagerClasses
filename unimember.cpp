#include <iostream>
#include <string>
#include "unimember.h"
using namespace std;
//int UniMember::getNumCourses(){return numCourses;}
//void UniMember::setNumCourses(int n){numCourses = n;}
int UniMember::getNumber(){return number;}
void UniMember::setNumber(int id){number=id;}
string UniMember::getFirstName()const{return firstName;}
void UniMember::setFirstName(string first){ firstName = first;}
string UniMember::getLastName()const{ return lastName;}
void UniMember::setLastName(string last){lastName = last;}
//float UniMember::getgpa(){return gpa;}
//void UniMember::setgpa(float gradePointAverage){gpa = gradePointAverage;}
UniMember::UniMember(const UniMember& current){
  number = current.number;
  firstName = current.firstName;
  lastName = current.lastName;
  //gpa = current.//gpa;
}
UniMember::UniMember(){
number = 0000000;
firstName = "null";
lastName = "null";
//gpa = 0.0000000;
}
UniMember::UniMember(string f, string l, int n)
{
  number = n;
  firstName = f;
  lastName = l;
  //gpa = g;
}
void UniMember::print(){
  cout.width(8); cout<< left << firstName << lastName << "   " <<number << "\n";
}
