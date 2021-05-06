//	ID: 20127001
//	Name: Ha Quoc Anh
//	Class: 20CLC11

#include "HeaderCourses.h"

int main() {
	STUDENT* T = nullptr;
	SetMode();
	Read_Student_List(T, L"Mon1.csv");
	View_List(T);
	Delete_Student_List_Student(T);
	return 0;
}

