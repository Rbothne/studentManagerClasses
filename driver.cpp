//Robert Bothne
//student_mgmt
//Student Display and Top GPA displayer

#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include "student.h"
#include "course.h"

#define MAX_NUM 125
using namespace std;
int getMenuChoice();
void addCourses(Student&);
int getStudentOption(int ,Student[]);
int getStudents(int , Student[], string);
Student findMaxStudent(int,Student[]);
void printStudentTable(int,Student[]);
int main (int argc, char* argv[])
{
	if (argc!=2){
	cout << "Correct usage:"<< "./text_analyzer filename\n";
	return(0);
}
	Student students[MAX_NUM];
	string iFile = argv[1];
	int size;
	int totalStudents = getStudents(size,students,iFile);
	if (totalStudents == -1){//close program
			return(0);
		}
while(1){
		int ui =getMenuChoice();
		if(ui==1){
		printStudentTable(totalStudents, students);
	}else if(ui==2){
					int sur=0;
					cout.width(8); cout<<"Option   " << "First    " << "Last" << "\n";
					cout.width(8); cout<< left << "======================" << "\n";
		while(sur<=0 || sur>totalStudents){
			for(int cur = 0; cur <totalStudents; cur++){
				cout<< cur << ".        " << students[cur].getFirstName() << "  " << students[cur].getLastName() << endl;
				}
				cout << "Choose the student option number: ";
				cin >> sur;
			 if(sur>=0 || sur<=totalStudents){
			addCourses(students[sur]);
			 }
		}
}else if(ui==3){
	int xur=0;
	cout.width(8); cout<<"Option   " << "First    " << "Last" << "\n";
	cout.width(8); cout<< left << "======================" << "\n";
	while(xur<=0 || xur>totalStudents){
	for(int bur = 0; bur <totalStudents; bur++){
		cout<< bur << ".        " << students[bur].getFirstName() << students[bur].getLastName() << endl;
	}
	cout << "Choose the student option number: ";
	cin >> xur;
	if(xur>=0 || xur<=totalStudents){
	students[xur].printSchedule();
		}
	}
}else if (ui==4){
	Student best = findMaxStudent(totalStudents, students);
	cout << "The student with the highest gpa is: "<< best.getFirstName() << " "<< best.getLastName() <<"\n";
}else if (ui==5){
	return (0);
}
}}



int getStudents(int size, Student students[],string fileName){
	ifstream fin(fileName);
if (fin.fail()){
			cout << "Sorry, could not open "<< fileName << " for reading\n";
			return(-1);
	}else{
		string firstName;
		string lastName;
		int number;
		float gpa;
		while (fin >> number >> lastName >> firstName >> gpa){
			Student current(firstName, lastName, number, gpa);
			students[size]=current;
			size++;
		}
		fin.close();
		return (size);
	}
}

void printStudentTable(int size,Student students[]){
	cout.width(8); cout<<"First   " << "Last    " << "Number" << "\n";
	cout.width(8); cout<< left << "======================" << "\n";

	for (int i = 0; i<size; i++){
		students[i].print();
	}
}

Student findMaxStudent(int size, Student students[]){
	int top=0;
	for(int i = 0; i<size; i++){
		if (students[top].getGPA()<students[i].getGPA()){
			top=i;
		}
	}
	return students[top];
}

int getMenuChoice(){
	int i;
	cout << "STUDENT MANAGEMENT SYSTEM" << endl;
	cout << "===============================" << endl;
	cout << "1.     Display Students" << endl;
	cout << "2.     Add Courses" << endl;
	cout << "3.     Display Student Schedule" << endl;
	cout << "4.     Find Highest GPA Student" << endl;
	cout << "5.     EXIT" << endl;
	cin >> i;
	return (i);
}

int getStudentOption(int size,Student students[]){
	printStudentTable(size,students);
	int number;
	cout << "Choose the student option number: ";
	cin >> number;
	return (number);
}

void addCourses(Student& stud ){
	string a, c;
	int b, adding, added=0;
	int courses = stud.getNumCourses();
	if(courses >=7){
		cout << stud.getNumCourses();
		cout << stud.getFirstName() << " " << stud.getLastName()<< " has a full schedule" << endl;
	}else{
		while (courses< 7 && added<adding){
			cout << stud.getFirstName() << " "<< stud.getLastName()<< "already has "<< stud.getNumCourses() << " " << "courses." << endl;
			cout << "How many class would you like to add?";
			cin >> adding;
			for(int i=0; i<adding; i++){
				cout << 	"Enter the course prefix, number, and name: ";
				cin >> a >> b >> c;
				Course news(a,b,c);
				stud.addCourse(news);
				added++;
			}
 courses +=adding;
		}
	}
}
