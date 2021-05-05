#include"function.h"
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
		menu();
		break;
	}
	case 2: {
		input_student(K, n, filestudent);
		login_student(K, n);
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
		break;
	}

	}
	delete_student_enroll_course(T);
	delete_enroll_staff(S);
	return 0;
}

