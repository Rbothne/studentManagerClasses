#include "course.h"
#include <iostream>
#include <string>
using namespace std;

Course::Course(){
  prefix = "null";
  number = 0;
  name = "null";
}
Course::Course(const Course& current){
  number = current.number;
  prefix = current.prefix;
  name = current.name;
}
Course::Course(string pre , int n , string named){
  number = n;
  name = named;
  prefix = pre;
}
int Course::getNumber()const{
  return number;
}
void Course::setNumber(int n){
number = n;
}
string Course::getName()const{
  return name;
}
void Course::setName(string n){
  name = n;
}
string Course::getPrefix()const{
  return prefix;
}
void Course::setPrefix(string p){
  prefix = p;
}
void Course::print(){
  cout << prefix << number << ":" << "    " << name << endl;
}
ostream& operator<<(ostream& out, const Course& s){
  out << s.getPrefix() << s.getNumber() << ":" << s.getName();
  out << endl;
  return out;
}
istream& operator>>(istream& in , Course& s){
  string p,nam;
  int num;
  in >> p >> num >> nam;
  s.setPrefix(p);
  s.setNumber(num);
  s.setName(nam);
  return in;
}
