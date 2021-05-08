#include <iostream>
#include <io.h>
#include<sstream>
#include <fcntl.h>
#include <string>
#include<fstream>
#include<iomanip>
#include <windows.h>
#include<codecvt>
#include<locale>
#define N 50
using namespace std;

struct STAFF
{
	wstring No; wstring ID; wstring socialID;
	wstring firstname; wstring lastname; wstring gender; wstring dateofbirth;
	wstring totalmark; wstring midtermmark;
	wstring finalmark; wstring orthermark;
	wstring averagemark;
	wstring gpa;
	wstring course;
	STAFF* pnext;
};

void scorecourse(STAFF* phead1);
void read_course(wstring classx, STAFF*& phead1);
void addnewstudent(wstring classx, STAFF* phead);
void inputstudentscore(wstring classx, STAFF*& phead);
void liststudent(STAFF* phead);
void liststudentwithscore(STAFF* phead);
//void importscoreboard(wstring classx, STAFF*& phead);
void deletelist(STAFF*& phead);
//void addscoreofnewstudet(wstring classx, STAFF* phead);
