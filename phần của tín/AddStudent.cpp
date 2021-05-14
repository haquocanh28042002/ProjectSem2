#ifndef LIBRARIES_H
#define LIBRARIES_H
#include<string>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<fcntl.h> //_O_WTEXT
#include<io.h>    //_setmode()
#include<codecvt> //possible C++11?
#include<iostream>
#include<locale>
#include<locale.h>
#include<conio.h>
#include<windows.h>
#include<shlwapi.h>
using namespace std;
struct student
{
	unsigned short No{};
	std::wstring studentID{};
	std::wstring firstName{};
	std::wstring lastName{};
	std::wstring gender{};
	std::wstring dateOfBirth{};
	std::wstring socialID{};
	std::wstring coreClass{};
	std::wstring coureClass{};
	student* next{};
};
struct coreClass  //Để quản lý SV khi đã đăng kí vào file tổng course
{
	std::wstring coreClassName;
	student* students = nullptr;
	coreClass* next;
};
struct courseClass {
	std::wstring courseClassName{};
	std::wstring sessionFirst{}; //VD: THU S3 (13h30)
	std::wstring sessionSecond{}; //VD: TUE S1 (7h30)
	unsigned int currentStudent{};
	unsigned int maxStudent{};
	courseClass* next{};
};
struct semester
{
	std::wstring semesterID{};
	std::wstring startDate{};
	std::wstring endDate{};
	std::wstring registerStartDate{};
	std::wstring registerEndDate{};
	course* courses = nullptr;
	semester* next{};
};

struct year
{
	std::wstring yearID{};
	semester* sem = nullptr;
	//coreClass* coreClasses;
	year* next{};
};
struct course
{
	std::wstring courseID{};
	std::wstring courseName{};
	std::wstring teacherName{};
	unsigned int numberOfCredits{};
	courseClass* courseClasses = nullptr;
	course* next{};
};
struct user
{
	std::wstring username{};
	std::wstring password{};
	user* next{};
};
#endif
void Readcoreclass(semester* semCur, year* yearCur, course* courseCur, coreClass*& head) //Hàm đọc CoreClass ở file Course tổng
{
	if (_setmode(_fileno(stdout), _O_WTEXT) != -1) {
		std::locale loc(std::locale(), new std::codecvt_utf8<wchar_t>);// UTF-8
		std::wifstream fin;
		fin.open(yearCur->yearID + L' ' + semCur->semesterID + L' ' + L"1" + L".txt");
		std::wstring temp;
		std::wstring word;
		fin.imbue(loc);
		if (fin.is_open())
		{
			coreClass* Cur = nullptr;
			while (!fin.eof()) {
				if (!head) {
					head = new coreClass;
					Cur = head;
				}
				else if (Cur) {
					Cur->next = new coreClass;
					Cur = Cur->next;
				}
				if (Cur) {
					std::getline(fin, temp);
					std::wstringstream line(temp);

					std::getline(line, Cur->coreClassName, static_cast<wchar_t>(','));

					Cur->next = nullptr;
					student* studentcur = nullptr;
					while (std::getline(fin, temp)) {
						if (temp == L"***") break;
						if (Cur) {
							if (!Cur->students) {
								Cur->students = new student;
								studentcur = Cur->students;
							}
							else if (studentcur) {
								studentcur->next = new student;
								studentcur = studentcur->next;
							}
							if (studentcur) {
								std::wstringstream studentclass(temp);
								std::getline(studentclass, word, static_cast<wchar_t>(','));
								std::wstringstream No(word);
								No >> studentcur->No;
								std::getline(studentclass, studentcur->studentID, L',');
								std::getline(studentclass, studentcur->firstName, L',');
								std::getline(studentclass, studentcur->lastName, L',');
								std::getline(studentclass, studentcur->coureClass, L',');

								studentcur->next = nullptr;
							}
						}
					}
				}
			}
		}
		fin.close();
	}
}
void OutputStudentListToCourseClass(semester* semCur, year* yearCur, course* courseCur, coreClass*& head) //Cập Nhật lại File Tổng SV ở File Tổng Course
{
	if (_setmode(_fileno(stdout), _O_WTEXT) != -1)
	{
		locale loc(std::locale(), new std::codecvt_utf8<wchar_t>);  // UTF-8
		wofstream fout(yearCur->yearID + L' ' + semCur->semesterID + L' ' + L"1" + L".txt");
		fout.imbue(loc);
		if (fout.is_open())
		{
			coreClass* coreClassCur = head;
			while (coreClassCur->next != nullptr)
			{
				fout << coreClassCur->coreClassName << endl; //Cho DSLK lớp gốc chạy để xuất ra tên lớp gốc
				student* Cur = coreClassCur->students;
				while (Cur != nullptr) //Nếu SV của lớp gốc có đăng ký vào lớp học phần nhỏ thì sẽ xuất dữ liệu SV đó theo DSLK
				{
					fout << Cur->No << L',' << Cur->studentID << L',' << Cur->firstName << L',' << Cur->lastName << L',' << Cur->coureClass << endl;
					Cur = Cur->next;
				}
				fout << L"***" << endl; //Xuất *** Để Đọc cho dễ trước vì File chưa đúng với CurrentStudent :vv
				coreClassCur = coreClassCur->next;
			}
		}
		fout.close();
	}
}
void AddStudenttoCourseClass(student*& cur, coreClass*& head, wstring& courseclassname) //Add SV vào cuối DSLK của list SV ở List CoreClass
{
	wstring t = cur->coreClass; //Gán string t là tên của lớp gốc của SV
	cur->next = nullptr; //Để hủy liên kết với mấy thằng đằng sau khi lấy thông tin  SV đó.
	coreClass* Cur = head;
	while (Cur != nullptr)
	{
		if (t == Cur->coreClassName) //Tìm lớp gốc chứa DSLK của list SV
		{
			if (Cur->students == nullptr) //Nếu HeadStudent=null thì gán HeadStudent = StudentCur 
			{
				Cur->students = cur;
				Cur->students->coureClass = courseclassname; //Lấy tên lớp học phần nhỏ
			}
			else
			{
				student* curstudent = Cur->students;
				while (curstudent != nullptr) //Chạy StudentCur tới cuối DSLK để liên kết thèn SV đã get info 
				{
					if (curstudent->next == nullptr)
					{
						curstudent->next = cur;
						cur->coureClass = courseclassname; //Lấy tên lớp học phần nhỏ
						break;
					}
					curstudent = curstudent->next;
				}
			}
			break;
		}
		Cur = Cur->next;
	}
}
void UpdateFileCourse(semester* semCur, year* yearCur, course* head) //Update lại thông tin currentstudent ở file Course sau khi SV đã đăng ký thành công
{
	if (_setmode(_fileno(stdout), _O_WTEXT) != -1)
	{
		locale loc(std::locale(), new std::codecvt_utf8<wchar_t>);  // UTF-8
		wofstream fout(yearCur->yearID + L' ' + semCur->semesterID + L".txt"); //Mở file VD 2021 1.txt
		fout.imbue(loc);
		if (fout.is_open())
		{
			course* cur = head;
			while (cur != nullptr)
			{
				fout << cur->courseID << L',' << cur->courseName << L',' << cur->teacherName << L',' << cur->numberOfCredits << endl;
				courseClass* courseClassCur = cur->courseClasses;
				while (courseClassCur != nullptr)
				{
					fout << courseClassCur->courseClassName << L',' << courseClassCur->sessionFirst << L',' << courseClassCur->sessionSecond << ',' << courseClassCur->maxStudent << ',' << courseClassCur->currentStudent << endl;
					courseClassCur = courseClassCur->next;
				}
				fout << "***" << endl;
				cur = cur->next;
			}
		}
		else
		{
			wcout << "Error";
		}
		fout.close();
	}
}
bool SearchCourseClass(course*& head, wstring& courseclassname)
{
	course* cur = head;
	while (cur != nullptr)
	{
		courseClass* courseclassCur = cur->courseClasses;
		while (courseclassCur)
		{
			if (courseclassCur->courseClassName == courseclassname)
			{
				return true;
			}
			courseclassCur = courseclassCur->next;
		}
		cur = cur->next;
	}
	return false;
}
student* SearchInfStudent(student* head, wstring studentID) //Get Info Của SV
{
	student* cur = head;
	while (cur != nullptr)
	{
		if (cur->studentID == studentID)
		{
			return cur;
		}
		cur = cur->next;
	}
	return nullptr;
}
courseClass* SearchInfCourseClass(courseClass* head, wstring courseClassName) //Get Info của lớp học phần nhỏ để có thể tăng giá trị currentstudent
{
	courseClass* cur = head;
	while (cur != nullptr)
	{
		if (cur->courseClassName == courseClassName)
		{
			return cur;
		}
		cur = cur->next;
	}
	return nullptr;
}
void RegisterCourse(course*& coursehead, user& studentuser, student* head, coreClass*& head1)
{
	wcout << L"Enter Name CourseClass" << endl;
	wstring courseclassname;
	getline(wcin, courseclassname);
	wcout << L"CourseClass Name is" << courseclassname << endl;
	if (coursehead == nullptr)
	{
		wcout << "Don't have any course to register";
	}
	if (SearchCourseClass(coursehead, courseclassname)) {
		student* cur = SearchInfStudent(head, studentuser.username);
		AddStudenttoCourseClass(cur, head1, courseclassname); //Add SV vào cuối DSLK SV ở lớp gốc
		courseClass* CourseClassCur = SearchInfCourseClass(coursehead->courseClasses, courseclassname);
		CourseClassCur->currentStudent++; //Tăng giá trị currentstudent
		wcout << "Register success";
	}
	else wcout << "Register Fail";
}
