#include <iostream>
#include "console.h"
#include <conio.h>
#include "Course.h"
#define MAUNEN 176
#define MAUCHU 7
using namespace std;


typedef char str[31];
str thaotac[4] = { "1.Add new","2.Delete","3.List","0.Exit" };
enum TRANGTHAI { UP, DOWN, LEFT, RIGHT, ENTER, BACK };
TRANGTHAI key(int z) {
	if (z == 224) {
		char c;
		c = _getch();
		if (c == 72) return UP;
		if (c == 80) return DOWN;
		if (c == 77) return RIGHT;
		if (c == 75) return LEFT;
	}
	else if (z == 13) return ENTER;
}

int menu(str thaotac[4], int n) {
	clrscr();
	int k = 0;
	int tt = 0; //thao tacs thu nhat
	int* mau = new int[n];
	for (int i = 0; i < n; i++) mau[i] = MAUCHU;
	mau[0] = MAUNEN;
	while (1)
	{
		//in giao dien menu
		for (int i = 0; i < n; i++) {
			TextColor(mau[i]);
//			gotoXY(50, 10 + i);
			cout << thaotac[i] << endl;
		}

		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai)
		{
		case UP:
			if (tt == 0) tt = n - 1; else tt--;
			break;
		case DOWN:
			if (tt == n - 1) tt = 0; else tt++;
			break;
		case ENTER:
			k = 1;
			break;
			return tt;

		}
		for (int i = 0; i < n; i++) mau[i] = MAUCHU;
		mau[tt] = MAUNEN;
		clrscr();
		if (k == 1) {
			int tmp=1;
			clrscr();
			if (tt == 0){
				addnewcourse();
				wcout << "0. Back ";
				wcin >> tmp;
				if (tmp == 0) { menu(thaotac, 4); }
				break;
			}
			if (tt == 1) {
				/*  course* phead = nullptr;
				inputlistcourse(phead);
				xemlist(phead);
				wstring t;
				wcout << "Nhập ID môn học cần xóa: " << endl;
				wcin >> t;
				deletecourse(phead,t);
				fstream f;
				f.open("course.csv", ios::out||ios::trunc);
				outputlistcourse(phead);
				phead = nullptr;
				inputlistcourse(phead);
				clrscr();
				xemlist(phead);
				break;
				f.close();*/
				wcout << "Delete ID course: " << endl;

				break;
			}
			if (tt == 2) {
				course* phead = nullptr;
				inputlistcourse(phead);
				xemlist(phead);
				wcout << "0. Back ";
				wcin >> tmp;
				if (tmp == 0) { menu(thaotac, 4); }
				break;
			}
			if (tt == 3) {
				clrscr();
				wcout << "See you again";
				break;
			}
		}
	}
	return 0;
}

