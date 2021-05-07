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
	STAFF* phead = nullptr;
	wstring filestudent = L"input.csv";
	wstring readfile = L"enrollstaff.csv", writefile = L"writestudentenrollcourse.csv";
	wstring class4 = L"20CLC04.csv";
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
		int n = 1;
		while (n != 0) {
			S = nullptr;
			T = nullptr;
			wcout << endl;
			wcout << "1.enroll course " << endl;
			wcout << "2.remove course" << endl;
			wcout << "3.view list of your course" << endl;
			wcout << "4.View list of classes" << endl;
			wcout << "5.View list of students in a class" << endl;
			wcout << "6.View list of courses" << endl;
			wcout << "7.View list of students in a course" << endl;
			wcout << "0.break" << endl;
			wcin >> n;
			system("cls");
			switch (n)
			{
			case 1: {
				read_file_course_staff(S, readfile);
				//output_enroll_course_staff(S);
				student_enroll_course(T, S);
				output_enroll_course_student(T);
				write_student_enroll_course(T, writefile);
				break;
			}
			case 2: {
				read_file_courses_student(T, writefile);
				wcout << "input course to remove(exit if input 0): ";
				wcin >> x;
				while (x != L"0") {
					output_enroll_course_student(T);
					remove_course_student(T, x);
					wcout << "input course to remove(exit if input 0): ";
					wcin >> x;
				}
				output_enroll_course_student(T);
				write_student_enroll_course(T, writefile);
				break;
			}
			case 3: {
				read_file_courses_student(T, writefile);
				output_enroll_course_student(T);
				break;
			}
			case 4: {
				wcout << "\n1. Class 20CLC1 ";
				wcout << "\n2. Class 20CLC2 ";
				wcout << "\n3. Class 20CLC3 ";
				wcout << "\n4. Class 20CLC4 ";
				break;
			}
			case 5: {
				inputstudentscore(class4, phead);
				liststudent(phead);
				break;
			}
			case 6: {
				read_file_course_staff(S, readfile);
				output_enroll_course_staff(S);
				break;
			}
			case 7: {
				wstring course1 = L"course1.csv";
				wstring course2 = L"course2.csv";
				wstring course3 = L"course3.csv";
				wstring course4 = L"course4.csv";
				wstring course5 = L"course5.csv";
				wstring course6 = L"course6.csv";
				wstring course7 = L"course7.csv";
				int t = 1;
				while (t != 0) {
					phead = nullptr;
					wcin.ignore();
					wcout << "1.course 1" << endl;
					wcout << "2.course 2" << endl;
					wcout << "3.course 3" << endl;
					wcout << "4.course 4" << endl;
					wcout << "5.course 5" << endl;
					wcout << "6.course 6" << endl;
					wcout << "7.course 7" << endl;
					wcout << "0.back" << endl;
					wcin >> t;
					system("cls");
					switch (t)
					{
					case 1: {
						read_student_a_course(course1, phead);
						liststudent(phead);
						break;
					}
					case 2: {
						read_student_a_course(course2, phead);
						liststudent(phead);
						break;
					}
					case 3: {
						read_student_a_course(course3, phead);
						liststudent(phead);
						break;
					}
					case 4: {
						read_student_a_course(course4, phead);
						liststudent(phead);
						break;
					}
					case 5: {
						read_student_a_course(course5, phead);
						liststudent(phead);
						break;
					}
					case 6: {
						read_student_a_course(course6, phead);
						liststudent(phead);
						break;
					}
					case 7: {
						read_student_a_course(course7, phead);
						liststudent(phead);
						break;
					}
					case 0:break;
					}
				}
			}
			case 0:break;
			
			}

		}
		break;
	}

	}
	delete_student_enroll_course(T);
	delete_enroll_staff(S);
	return 0;
}

