#pragma once
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
struct node
{
	wstring No; wstring ID; wstring socialID;
	wstring firstname; wstring lastname; wstring gender; wstring dateofbirth;
	node* pnext;
};
/*struct input
{
	wstring No; wstring ID; wstring socialID;
	wstring firstname; wstring lastname; wstring gender; wstring dateofbirth;
};*/
using namespace std;
void schoolyear(int a, int b);
void inputstudent(wstring inputstd);


