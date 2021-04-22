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
	STUDENT* pnext;
};

struct STAFF {
	wstring userstaff;
	wstring passwordstaff;
	wstring no, coursename, teachername, credit, maxperson, daylt, dayth;
	STAFF* pnext;
};

void SetMode();
void Read_Courses_List(STUDENT*& T, wstring filename);
void View_Courses(STUDENT* T);
void Read_Student_List(STAFF*& S, string filename);







#endif 
