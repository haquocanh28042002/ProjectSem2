#include<iostream>
#include<string>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <windows.h>
#include<fstream>
#include<codecvt>
#include<locale>
#define N 100
using namespace std;
struct STUDENT
{
	wstring userstudent;
	wstring passwordstudent;
	wstring passwordnewstudent;
	
};
struct STAFF
{
	wstring userstaff;
	wstring passwordstaff;
};
//đọc tài khoản cho sinh viên
void input_student(STUDENT a[N], int& n) {
	int i;
	wifstream filein;
	filein.open("input.txt", ios_base::in);
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
		if (a[i + 1].userstudent == u ) {
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
void login_staff( STAFF a) {
	const wstring u =L"ho tuan thanh" ;
	const wstring p =L"123456";
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

int main() {
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
	HANDLE hdlConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX consoleFont;
	consoleFont.cbSize = sizeof(consoleFont);
	GetCurrentConsoleFontEx(hdlConsole, FALSE, &consoleFont);
	memcpy(consoleFont.FaceName, L"Consolas", sizeof(consoleFont.FaceName));
	STUDENT K[N];
	STAFF F;
	int n,t;
	wcout << "1)staff" << endl;
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
		input_student(K, n);
		login_student(K, n);
		break;
	}
	
	}

	return 0;
}