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
#include <stdlib.h>
#include<stdio.h>

using namespace std;


struct date {
	int d, m, y;
};
enum dayofweek {
	MON = 2,
	TUE, WED, THU, FRI, SAT, SUN
};
enum  session {
	S1 = 1, S2, S3, S4
};
struct course {
	wstring IDcourse, namecourse, teacher, credit, dow1, dow2, s1, s2;
	course* pNext;
};
void addnewcourse();
void inputlistcourse(course*& phead);
void xemlist(course* phead);
void deletecourse(course*& phead, wstring t);
void outputlistcourse(course* phead);

//====đọc dữ liệu từ file=====
void inputlistcourse(course*& phead) {
	wfstream f;
	f.open(L"course.csv", ios_base::in);
	f.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	if (f.fail() == true)
	{
		cout << "can't open file ";
		return;
		system("pause");
	}
	//f.seekg(3);
	course* pcur = nullptr;
	wstring IDcourse, namecourse, teacher;
	wstring credit, dow1, dow2, s1, s2;
	phead = new course;
	pcur = phead;
	getline(f, pcur->IDcourse, L',');
	getline(f, pcur->namecourse, L',');
	getline(f, pcur->teacher, L',');
	getline(f, pcur->credit, L',');
	getline(f, pcur->dow1, L',');
	getline(f, pcur->s1, L',');
	getline(f, pcur->dow2, L',');
	getline(f, pcur->s2);
	phead->pNext = nullptr;
	while (!f.eof()) {
		pcur->pNext = new course;
		pcur = pcur->pNext;
		getline(f, pcur->IDcourse, L',');
		getline(f, pcur->namecourse, L',');
		getline(f, pcur->teacher, L',');
		getline(f, pcur->credit, L',');
		getline(f, pcur->dow1, L',');
		getline(f, pcur->s1, L',');
		getline(f, pcur->dow2, L',');
		getline(f, pcur->s2);
		pcur->pNext = nullptr;
	}
	f.close();
}

//====in dữ liệu ra màn hình=====
void xemlist(course* phead) {
	//system("cls");
	//int x = 1, y = 1;
	//course* pcur = phead;
	//while (pcur != nullptr) {
	//	//gotoXY(x, y);
	//	wcout << pcur->IDcourse << " ";
	//	wcout << pcur->namecourse << " ";
	//	wcout << pcur->teacher << " ";
	//	wcout << pcur->credit << " ";
	//	wcout << pcur->dow1 << " ";
	//	wcout << pcur->s1 << " ";
	//	wcout << pcur->dow2 << " ";
	//	wcout << pcur->s2 << endl;
	//	pcur = pcur->pNext;
	//}
	system("cls");
	course* pcur = phead;
	wcout << endl;
	wcout << "IDcourse" << setw(20) << "Namecourse" << setw(20) << "Teacher" << setw(20) << "Credit" << setw(20) << "Session1" << setw(20) << "Period1" << setw(20) << "Session2" << setw(20) <<"Period2" << endl;
	while (pcur != nullptr)
	{
		wcout << pcur->IDcourse << setw(20) << pcur->namecourse << setw(20) << pcur->teacher << setw(20) << pcur->credit << setw(20) << pcur->dow1 << setw(20) << pcur->s1 << setw(20) << pcur->dow2 << setw(20) << pcur->s2;
		wcout << endl;
		pcur = pcur->pNext;
	}
	return;
}

//====xóa một môn học========
void deletecourse(course*& phead, wstring t) {
	course* pcur = phead;
	if (pcur->IDcourse == t) {
		course* tmp = phead;
		phead = phead->pNext;
		delete tmp;
		tmp = nullptr;
		return;
	}
	while (pcur->pNext != nullptr) {
		if (pcur->pNext->IDcourse == t) {
			course* tmp = pcur->pNext;
			pcur->pNext = pcur->pNext->pNext;
			delete tmp;
			tmp = nullptr;
		}
		if (pcur->pNext == nullptr) {
			course* tmp = pcur->pNext;
			delete tmp;
			tmp = nullptr;
		}
		else
			pcur = pcur->pNext;
	}
}

//====ghi dữ liệu vào file====
void outputlistcourse(course* phead) {
	wfstream f;
	f.open("course.csv", ios::out);
	std::locale loc(std::locale(), new std::codecvt_utf8<wchar_t>);
	f.imbue(loc);
	course* pcur = phead;
	while (pcur != nullptr) {
		f << pcur->IDcourse << L",";
		f << pcur->namecourse << L",";
		f << pcur->teacher << L",";
		f << pcur->credit << L",";
		f << pcur->dow1 << L",";
		f << pcur->s1 << L",";
		f << pcur->dow2 << L",";
		f << pcur->s2 << endl;
		pcur = pcur->pNext;
	}
	f.close();
}

void addnewcourse() {
	std::locale loc(std::locale(), new std::codecvt_utf8<wchar_t>);
	wfstream f;
	f.imbue(loc);
	course* a = nullptr;
	a = new course;
	a->pNext = nullptr;
	f.open("course.csv", ios::app);

	wcout << "ID course: ";
	getline(std::wcin, a->IDcourse);
	f << a->IDcourse << ",";

	wcout << "Name course: ";
	getline(std::wcin, a->namecourse);
	f << a->namecourse << ",";

	wcout << "Teach: ";
	getline(std::wcin, a->teacher);
	f << a->teacher << ",";

	wcout << "Number of credits: ";
	getline(std::wcin, a->credit);
	f << a->credit << ",";

	wcout << "Time of session 1(MON/TUES/...): ";
	getline(std::wcin, a->dow1);
	f << a->dow1 << ",";

	wcout << "S1/S2/S3/S4: ";
	getline(std::wcin, a->s1);
	f << a->s1 << ",";

	wcout << "Time of session 2(MON/TUES/...): ";
	getline(std::wcin, a->dow2);
	f << a->dow2 << ",";

	wcout << "S1/S2/S3/S4: ";
	getline(std::wcin, a->s2);
	f << a->s2 << endl;

	delete a;
}
