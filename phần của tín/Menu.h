#include <iostream>
#include "console.h"
#include <conio.h>
#include "Course.h"
#define MAUNEN 176
#define MAUCHU 2
using namespace std;


//menu moi

typedef char str[31];
str thaotac[4] = { "1.Add new","2.Delete","3.List","0.Exit" };
int menu(str thaotac[4], int n) {
	system("cls");
	int k = 0;
	int tt = 0;
	int* mau = new int[n];
	for (int i = 0; i < n; i++) mau[i] = MAUCHU;
	//mau[0] = MAUNEN;
	while (1)
	{
		//in menu
		for (int i = 0; i < n; i++) {
			wcout << thaotac[i] << endl;
		}
		wcin >> tt;
		wcin.ignore();
		k = 1;

		if (k == 1) {
			int tmp = 1;
			clrscr();
			//chọn 1
			if (tt == 1) {
				system("cls");
				addnewcourse();
				wcout << "0. Back ";
				wcin >> tmp;
				if (tmp == 0) { menu(thaotac, 4); }
				break;
			}
			//chọn 2
			if (tt == 2) {
				system("cls");
				course* phead = nullptr;
				inputlistcourse(phead);
				xemlist(phead);
				wcout << "Delete ID course: " << endl;
				wstring t;
				wcin >> t;
				deletecourse(phead, t);
				xemlist(phead);
				outputlistcourse(phead);
				wcout << "0. Back ";
				wcin >> tmp;
				wcin.ignore();
				if (tmp == 0) { menu(thaotac, 4); }
				break;
			}
			if (tt == 3) {
				system("cls");
				course* phead = nullptr;
				inputlistcourse(phead);
				xemlist(phead);
				wcout << "0. Back ";
				wcin >> tmp;
				wcin.ignore();
				if (tmp == 0) { menu(thaotac, 4); }
				break;
			}
			if (tt == 0) {
				system("cls");
				break;
			}
		}
	}
	return 0;
}
