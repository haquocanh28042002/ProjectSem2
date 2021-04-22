#ifndef HeaderCourses_h
#define HeaderCourses_h

#include <iostream>
#include <cstring>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <windows.h>
#include <fstream>
#include <codecvt>
#include <locale>
#include <iomanip>
#include <sstream>
#define N 100
using namespace std;

struct STUDENT {
	wstring userstudent;
	wstring passwordstudent;
	wstring passwordnewstudent;
	wstring no, coursename, teachername, credit, maxperson, daylt, dayth;
	wstring No, ID, socialID;
	wstring firstname, lastname, gender, dateofbirth;
	wstring totalmark, midtermmark, finalmark, orthermark,
	STUDENT* pnext;
};

struct STAFF {
	wstring userstaff;
	wstring passwordstaff;
	wstring no, coursename, teachername, credit, maxperson, daylt, dayth;
	STAFF* pnext;
};

struct node
{
	wstring No; wstring ID; wstring socialID;
	wstring firstname; wstring lastname; wstring gender; wstring dateofbirth;
	wstring totalmark; wstring midtermmark;
	wstring finalmark; wstring orthermark;
	node* pnext;
};

void SetMode();
void Read_Student_List(STAFF*& S, wstring filename);
void View_List(STAFF*& S);
void Read_File_Courses(STAFF*& S, wstring filecoursesname);
void View_Courses(STUDENT* T);
void Delete_Student_List(STAFF*& S);
void Delete_Courses_List(STUDENT*& T);
void Write_Student_To_FileCourses(STUDENT*& T, wstring filename);




#endif 
