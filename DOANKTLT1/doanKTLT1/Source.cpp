#include<iostream>
#include<string>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <windows.h>
#include<fstream>
#include<codecvt>
#include<locale>
#include<iomanip>
#define N 100
using namespace std;
struct STUDENT
{
	wstring userstudent;
	wstring passwordstudent;
	wstring passwordnewstudent;
	wstring no, coursename, teachername, credit, maxperson, daylt, dayth;
	wstring count;
	STUDENT* pnext;
};
struct STAFF
{
	wstring userstaff;
	wstring passwordstaff;
	wstring no, coursename, teachername, credit, maxperson, daylt, dayth;
	STAFF* pnext;
};
//đọc tài khoản cho sinh viên
void input_student(STUDENT a[N], int& n, wstring filestudent) {
	int i;
	wifstream filein;
	filein.open(filestudent, ios_base::in);
	filein.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	if (filein.fail() == true) {
		cout << "ERROR";
		system("pause");
	}
	filein >> n;
	for (i = 0; i < n; i++) {
		getline(filein, a[i + 1].userstudent, L',');
		getline(filein, a[i + 1].passwordstudent);
	}
}

//đăng nhập của sinh viên
void login_student(STUDENT a[N], int n) {
	wstring u, p;
	wcout << "log in " << endl;
	wcout << "username: ";
	getline(wcin, u);
	wcout << "password: ";
	getline(wcin, p);
	system("cls");
	for (int i = 0; i < n; i++) {
		if (a[i + 1].userstudent == u) {
			while (a[i + 1].userstudent != u || a[i + 1].passwordstudent != p) {
				wcout << "log in " << endl;
				wcout << "username: ";
				getline(wcin, u);
				wcout << "password: ";
				getline(wcin, p);
				system("cls");
			}
			if (a[i + 1].userstudent == u && a[i + 1].passwordstudent == p) {
				wcout << "change password";
				getline(wcin, a[i + 1].passwordnewstudent);
				system("cls");
				while (a[i + 1].passwordnewstudent == p) {
					wcout << "change password";
					getline(wcin, a[i + 1].passwordnewstudent);
					system("cls");
				}
				wcout << "Logged in successfully!!";
			}
		}
	}
}
//đăng nhập của staff
void login_staff(STAFF a) {
	const wstring u = L"ho tuan thanh";
	const wstring p = L"123456";
	wcout << "log in" << endl;
	wcout << "username: ";
	getline(wcin, a.userstaff);
	wcout << "password: ";
	getline(wcin, a.passwordstaff);
	system("cls");
	while (a.userstaff != u || a.passwordstaff != p) {
		wcout << "input user or password is fail!!!" << endl;
		wcout << "username: ";
		getline(wcin, a.userstaff);
		wcout << "password: ";
		getline(wcin, a.passwordstaff);
		system("cls");
	}
	system("cls");
	wcout << "Logged in successfully!!" << endl;
}

void read_file_course_staff(STAFF*& S, wstring readfile) {
	wifstream enroll;
	enroll.open(readfile, ios_base::in);
	enroll.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	if (enroll.fail() == true) {
		cout << "error";
		system("pause");
	}
	enroll.seekg(3);
	STAFF* pcur = nullptr;
	while (!enroll.eof()) {
		if (S == nullptr) {
			S = new STAFF;
			pcur = S;
		}
		else {
			pcur->pnext = new STAFF;
			pcur = pcur->pnext;
		}
		getline(enroll, pcur->no, L',');
		getline(enroll, pcur->coursename, L',');
		getline(enroll, pcur->teachername, L',');
		getline(enroll, pcur->credit, L',');
		getline(enroll, pcur->maxperson, L',');
		getline(enroll, pcur->daylt, L',');
		getline(enroll, pcur->dayth);
		pcur->pnext = nullptr;
	}
	enroll.close();
}

void output_enroll_course_staff(STAFF* S) {
	if (S == nullptr)return;
	else {
		wcout << "NO" << setw(20) << "COURSENAME" << setw(20) << "TEACHERNAME" << setw(20) << "CREDIT" << setw(20) << "MAXPERSON" << setw(20) << "dayLT" << setw(20) << "DAYTH" << endl;
		while (S != nullptr) {
			wcout << S->no << setw(20) << S->coursename << setw(20) << S->teachername << setw(20) << S->credit << setw(20) << S->maxperson << setw(20) << S->daylt << setw(20) << S->dayth;
			wcout << endl;
			S = S->pnext;
		}
	}
}


void delete_enroll_staff(STAFF*& S) {
	if (S == nullptr)return;
	else {
		STAFF* ptemp = nullptr;
		while (S != nullptr) {
			ptemp = S;
			S = S->pnext;
			delete ptemp;
			ptemp = nullptr;
		}
	}
}

void delete_student_enroll_course(STUDENT*& T) {
	if (T == nullptr)return;
	else {
		STUDENT* ptemp = nullptr;
		while (T != nullptr) {
			ptemp = T;
			T = T->pnext;
			delete ptemp;
			ptemp = nullptr;
		}
	}
}

bool check_enroll_same(STUDENT* T, wstring m, wstring n) {
	if (T == nullptr) return true;
	STUDENT* pcur = T;
	while (pcur != nullptr) {
		if (pcur->daylt == m || pcur->dayth == n) {
			return false;
		}
		else pcur = pcur->pnext;
	}
	return true;
}
void student_enroll_course(STUDENT*& T, STAFF* S) {
	if (S == nullptr)return;
	else {
		STAFF* pcur = S;
		STUDENT* pcur1 = nullptr;
		wstring t, y = L"0";
		wstring m, n;
		output_enroll_course_staff(S);
		wcout << "choose enroll course(exit if input 0): ";
		wcin >> t;
		int count = 0, count1 = 0, z;

		while (t != y) {

			while (pcur->no != t && pcur != nullptr)pcur = pcur->pnext;
			if (pcur->no == t && pcur != nullptr) {
				m = pcur->daylt;
				n = pcur->dayth;
				if (check_enroll_same(T, m, n) == false) {
					system("cls");
					wcout << "similar time" << endl;
					output_enroll_course_staff(S);
					wcout << "choose enroll course(exit if input 0): ";
					wcin >> t;
				}
				else {
					++count;
					if (T == nullptr) {
						T = new STUDENT;
						pcur1 = T;
					}
					else {
						pcur1->pnext = new STUDENT;
						pcur1 = pcur1->pnext;
					}
					pcur1->no = pcur->no;
					pcur1->coursename = pcur->coursename;
					pcur1->teachername = pcur->teachername;
					pcur1->credit = pcur->credit;
					pcur1->maxperson = pcur->maxperson;
					pcur1->daylt = pcur->daylt;
					pcur1->dayth = pcur->dayth;
					pcur1->count = count1 + 1;
					pcur1->pnext = nullptr;
					system("cls");
					output_enroll_course_staff(S);
					wcout << "choose enroll course(exit if input 0): ";
					wcin >> t;

				}
				if (pcur1->count >= pcur1->maxperson) {
					cout << "maxperson is full " << endl;
					output_enroll_course_staff(S);
					wcout << "choose enroll course(exit if input 0): ";
					wcin >> t;
				}
				if (count == 5)break;
				pcur = S;
				count1 = 0;
			}
		}
	}
}

void output_enroll_course_student(STUDENT* T) {
	STUDENT* pcur = T;
	wcout << "NO" << setw(20) << "COURSENAME" << setw(20) << "TEACHERNAME" << setw(20) << "CREDIT" << setw(20) << "MAXPERSON" << setw(20) << "dayLT" << setw(20) << "DAYTH" << endl;
	while (pcur != nullptr) {
		wcout << pcur->no << setw(20) << pcur->coursename << setw(20) << pcur->teachername << setw(20) << pcur->credit << setw(20) << pcur->maxperson << setw(20) << pcur->daylt << setw(20) << pcur->dayth;
		wcout << endl;
		pcur = pcur->pnext;
	}
}

void remove_course_student(STUDENT*& T, wstring x) {
	if (T == nullptr)return;
	else {
		STUDENT* ptemp = nullptr;
		if (T->no == x && T != nullptr) {
			ptemp = T;
			T = T->pnext;
			delete ptemp;
			ptemp = nullptr;
			return;
		}
		STUDENT* pcur = T;
		while (pcur->pnext->no != x && pcur->pnext != nullptr)pcur = pcur->pnext;
		if (pcur->pnext->no == x && pcur->pnext != nullptr) {
			ptemp = pcur->pnext;
			pcur->pnext = pcur->pnext->pnext;
			delete ptemp;
			ptemp = nullptr;
		}
	}
}



void write_student_enroll_course(STUDENT* T, wstring writefile) {
	if (T == nullptr) return;
	else {
		wofstream enroll;
		enroll.open(writefile, ios_base::out);
		enroll.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::generate_header>));
		STUDENT* pcur = T;
		while (pcur != nullptr) {
			enroll << pcur->no << "," << pcur->coursename << "," << pcur->teachername << "," << pcur->credit << "," << pcur->maxperson << "," << pcur->daylt << "," << pcur->dayth << endl;
			pcur = pcur->pnext;
		}
		enroll.close();
	}
}


int main() {
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
	HANDLE hdlConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX consoleFont;
	consoleFont.cbSize = sizeof(consoleFont);
	GetCurrentConsoleFontEx(hdlConsole, FALSE, &consoleFont);
	memcpy(consoleFont.FaceName, L"Consolas", sizeof(consoleFont.FaceName));
	STUDENT K[N], * T = nullptr;
	STAFF F, * S = nullptr;
	wstring filestudent = L"input.csv";
	wstring x;
	int n, t;
	/*wcout << "1)staff" << endl;
	wcout << "2)student" << endl;
	wcout << "choose student or staff:" << endl;
	wcin >> t;
	system("cls");
	wcin.ignore(1000, '\n');
	switch (t)
	{
	case 1: {
		login_staff(F);
		break;
	}
	case 2: {
		input_student(K, n, filestudent);
		login_student(K, n);
		break;
	}

	}*/
	wstring readfile = L"enrollstaff.csv", writefile = L"writestudentenrollcourse.csv";
	read_file_course_staff(S, readfile);
	//output_enroll_course_staff(S);
	student_enroll_course(T, S);
	output_enroll_course_student(T);
	wcout << "input course to remove(exit if input 0): ";
	wcin >> x;
	while (x != L"0") {
		remove_course_student(T, x);
		wcout << "input course to remove(exit if input 0): ";
		wcin >> x;
	}
	output_enroll_course_student(T);
	write_student_enroll_course(T, writefile);
	delete_student_enroll_course(T);
	delete_enroll_staff(S);
	return 0;
}

