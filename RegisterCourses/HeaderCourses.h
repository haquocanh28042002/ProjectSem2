#ifndef HeaderCourses_h
#define HeaderCourses_h

#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <windows.h>
#include <fstream>
#include <codecvt>
#include <locale>
#include <iomanip>
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
void View_Courses_List(STUDENT*& S, wstring filename);
void output_enroll_course(STUDENT* T);

#endif 
