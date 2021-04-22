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

void Read_Student_List(STAFF*& S, wstring filename) {
	wifstream filelist;
	filelist.open(filename, ios_base::in);
	filelist.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	if (filelist.fail() == true) {
		cout << "File does not exist." << endl;
		system("pause");
	}
	else {
		S = new STAFF;
		STAFF* pcur = S;
		wstring No; wstring ID;
		wstring firstname; wstring lastname; wstring gender; wstring dateofbirth;
		while (!filelist.eof()) {
			if (phead == nullptr) {
				phead = new node;
				pcur = phead;
			}
			else {
				pcur->pnext = new node;
				pcur = pcur->pnext;
				pcur->pnext = nullptr;
			}
			getline(filelist, No, L',');
			getline(filelist, ID, L',');
			getline(filelist, firstname, L',');
			getline(filelist, lastname, L',');
			getline(student, gender, L',');
			
			pcur->No = No;
			pcur->firstname = firstname;
			pcur->lastname = lastname;
			pcur->ID = ID;
			pcur->gender = gender;
			pcur->dateofbirth = dateofbirth;
			pcur->pnext = nullptr;
		}
	}
	filelist.close();
}

void View_List(STAFF*& S) {
	if (S == nullptr) return;
	STAFF* pcur = S;
	else {
		wcout << "No" << setw(20) << "StudentID" << setw(20) << "Firstname" << setw(20) << "Lastname" << setw(20) << "Gender" << setw(20) << "DayofBirth" << endl;
		while (S != nullptr) {
			wcout << S->no << setw(20) << S->studentid << setw(10) << S->firstname << setw(20) << S->lastname << setw(20) << S->gender << setw(20) << S->dateofbirth;
			wcout << endl;
			S = S->pnext;
		}
	}
}

void Read_File_Courses(STAFF*& S, wstring filecoursesname) {
	wifstream filecourses;
	filecourses.open(filecoursesname, ios_base::in);
	filecourses.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	if (filecourses.fail() == true) {
		cout << "File does not exist" << endl;
		system("pause");
	}
	STAFF* pcur = nullptr;
	while (!filecourses.eof()) {
		if (S == nullptr) {
			S = new STAFF;
			pcur = S;
		}
		else {
			pcur->pnext = new STAFF;
			pcur = pcur->pnext;
		}
		getline(filecourses, pcur->no, L',');
		getline(filecourses, pcur->coursename, L',');
		getline(filecourses, pcur->teachername, L',');
		getline(filecourses, pcur->credit, L',');
		getline(filecourses, pcur->maxperson, L',');
		getline(filecourses, pcur->daylt, L',');
		getline(filecourses, pcur->dayth);
		pcur->pnext = nullptr;
	}
	filecourses.close();
}

void View_Courses(STUDENT* T) {
	if (T == nullptr) return;
	else {
		wcout << "NO" << setw(20) << "COURSENAME" << setw(20) << "TEACHERNAME" << setw(20) << "CREDIT" << setw(20) << "MAXPERSON" << setw(20) << "dayLT" << setw(20) << "DAYTH" << endl;
		while (T != nullptr) {
			wcout << T->no << setw(20) << T->coursename << setw(20) << T->teachername << setw(20) << T->credit << setw(20) << T->maxperson << setw(20) << T->daylt << setw(20) << T->dayth;
			wcout << endl;
			T = T->pnext;
		}
	}
}

void Delete_Student_List(STAFF*& S) {
	if (S == nullptr) return;
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

void Delete_Courses_List(STUDENT*& T) {
	if (T == nullptr) return;
	else {
		STAFF* ptemp = nullptr;
		while (T != nullptr) {
			ptemp = T;
			T = T->pnext;
			delete ptemp;
			ptemp = nullptr;
		}
	}
}



