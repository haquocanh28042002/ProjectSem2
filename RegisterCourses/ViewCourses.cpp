#include "HeaderCourses.h"

void SetMode() {
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
	HANDLE hdlConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX consoleFont;
	consoleFont.cbSize = sizeof(consoleFont);
	GetCurrentConsoleFontEx(hdlConsole, FALSE, &consoleFont);
	memcpy(consoleFont.FaceName, L"Consolas", sizeof(consoleFont.FaceName));
}

void View_Courses_List(STUDENT*& T, wstring filename) {
	wifstream enroll(filename, ios_base::in);
	enroll.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	if (enroll.fail() == true) {
		cout << "error";
		system("pause");
	}
	T = new STUDENT;
	STUDENT* pcur = T;
	getline(enroll, pcur->no, L',');
	getline(enroll, pcur->coursename, L',');
	getline(enroll, pcur->teachername, L',');
	getline(enroll, pcur->credit, L',');
	getline(enroll, pcur->maxperson, L',');
	getline(enroll, pcur->daylt, L',');
	getline(enroll, pcur->dayth);
	while (!enroll.eof()) {
		pcur->pnext = new STUDENT;
		pcur = pcur->pnext;
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

void output_enroll_course(STUDENT* S) {
	if (S == nullptr) return;
	else {
		wcout << "NO" << setw(20) << "COURSENAME" << setw(20) << "TEACHERNAME" << setw(20) << "CREDIT" << setw(20) << "MAXPERSON" << setw(20) << "dayLT" << setw(20) << "DAYTH" << endl;
		while (S != nullptr) {
			wcout << S->no << setw(20) << S->coursename << setw(20) << S->teachername << setw(20) << S->credit << setw(20) << S->maxperson << setw(20) << S->daylt << setw(20) << S->dayth;
			wcout << endl;
			S = S->pnext;
		}
	}
}