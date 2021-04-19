#ifndef HeaderCourses_h
#define HeaderCourses_h

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <Windows.h>
#include <fstream>
#include <locale>
#include <codecvt>
#include <cstring>
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

void ExportList(STUDENT*& S);

#endif 
