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

void Read_Student_List(STUDENT *T, wstring filename) {
	std::wifstream filelist;
	filelist.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	
	in.close();
}


std::ifstream file;

	file.open("test.csv");

	std::string line;
	std::string value;
	std::string temp;
	
	if (file)
		//while (getline(file, line)) {
		while(file.good()){

			getline(file, value, ',');
			std::cout << std::setw(10);
			std::cout << value;
			
		}
	else
		std::cout << "Failed to open File" << std::endl;
}
