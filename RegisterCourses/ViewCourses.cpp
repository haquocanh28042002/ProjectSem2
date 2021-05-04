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

void Read_Student_List(STUDENT*& T, wstring filename) {
	wifstream filelist;
	filelist.open(filename, ios_base::in);
	filelist.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	if (filelist.fail() == true) {
		cout << "File does not exist." << endl;
		system("pause");
	}
	else {
		T = new STUDENT;
		STUDENT* pcur = T;
		wstring No; wstring ID;
		wstring firstname; wstring lastname; wstring gender; wstring dateofbirth;
		while (!filelist.eof()) {
			if (T == nullptr) {
				T = new STUDENT;
				pcur = T;
			}
			else {
				pcur->pnext = new STUDENT;
				pcur = pcur->pnext;
				pcur->pnext = nullptr;
			}
			getline(filelist, No, L',');
			getline(filelist, ID, L',');
			getline(filelist, firstname, L',');
			getline(filelist, lastname, L',');
			getline(filelist, gender, L',');

			pcur->No = No;
			pcur->ID = ID;
			pcur->firstname = firstname;
			pcur->lastname = lastname;
			pcur->gender = gender;
			pcur->dateofbirth = dateofbirth;
			pcur->pnext = nullptr;
		}
	}
	filelist.close();
}

void View_List(STUDENT*& T) {
	if (T == nullptr) return;
	else {
		STUDENT* pcur = T;
		wcout   << "No" 	<< setw(20)
			<< "StudentID"	<< setw(20)
			<< "Firstname"	<< setw(20)
			<< "Lastname"	<< setw(20)
			<< "Gender"	<< setw(20)
			<< "DayofBirth" << endl;

		while (T != nullptr) {
			wcout	<< T->No	  << setw(20)
				<< T->ID	  << setw(10)
				<< T->firstname   << setw(20)
				<< T->lastname	  << setw(20)
				<< T->gender	  << setw(20)
				<< T->dateofbirth << endl;
			T = T->pnext;
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
		wcout 	<< "NO"		<< setw(20) 
			<< "COURSENAME" << setw(20) 
			<< "TEACHERNAME"<< setw(20) 
			<< "CREDIT"	<< setw(20) 
			<< "MAXPERSON"	<< setw(20) 
			<< "dayLT"	<< setw(20) 
			<< "DAYTH"	<< endl;

		while (T != nullptr) {
			wcout 	<< T->no	 << setw(20) 
				<< T->coursename << setw(20) 
				<< T->teachername<< setw(20) 
				<< T->credit	 << setw(20) 
				<< T->maxperson  << setw(20) 
				<< T->daylt	 << setw(20) 
				<< T->dayth	 << endl;
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
		STUDENT* ptemp = nullptr;
		while (T != nullptr) {
			ptemp = T;
			T = T->pnext;
			delete ptemp;
			ptemp = nullptr;
		}
	}
}

void Write_Student_To_FileCourses(STUDENT*& T) {
	wifstream file1, file2, file3, file4, file5;
	if (T == nullptr) return;
	else {
		STUDENT* pcur = nullptr;
		pcur = T;
		while (pcur != nullptr) {
			if (pcur->no == L"1") {
				file1.open(L"Mon1.csv", std::ios_base::app);
				file1.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
				file1	<< pcur->No		<< ","
					<< pcur->ID		<< ","
					<< pcur->firstname	<< ","
					<< pcur->lastname	<< ","
					<< pcur->gender		<< ","
					<< pcur->dateofbirth	<< endl;
				pcur = pcur->pnext;
			}
			if (pcur->no == L"2") {
				file2.open(L"Mon2.csv", std::ios_base::app);
				file2.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
				file2	<< pcur->No		<< ","
					<< pcur->ID		<< ","
					<< pcur->firstname	<< ","
					<< pcur->lastname	<< ","
					<< pcur->gender		<< ","
					<< pcur->dateofbirth	<< endl;
				pcur = pcur->pnext;
			}
			if (pcur->no == L"3") {
				file3.open(L"Mon3.csv", std::ios_base::app);
				file3.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
				file3	<< pcur->No		<< ","
					<< pcur->ID		<< ","
					<< pcur->firstname	<< ","
					<< pcur->lastname	<< ","
					<< pcur->gender		<< ","
					<< pcur->dateofbirth	<< endl;
				pcur = pcur->pnext;
			}
			if (pcur->no == L"4") {
				file4.open(L"Mon4.csv", std::ios_base::app);
				file4.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
				file4	<< pcur->No		<< ","
					<< pcur->ID		<< ","
					<< pcur->firstname  	<< ","
					<< pcur->lastname	<< ","
					<< pcur->gender		<< ","
					<< pcur->dateofbirth	<< endl;
				pcur = pcur->pnext;
			}
			if (pcur->no == L"5") {
				file5.open(L"Mon5.csv", std::ios_base::app);
				file5.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
				file5	<< pcur->No		<< ","
					<< pcur->ID		<< ","
					<< pcur->firstname	<< ","
					<< pcur->lastname	<< ","
					<< pcur->gender		<< ","
					<< pcur->dateofbirth	<< endl;
				pcur = pcur->pnext;
			}
		}
	}
	file1.close(); file2.close(); file3.close(); file4.close(); file5.close();
}
