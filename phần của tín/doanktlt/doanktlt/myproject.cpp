#include"myproject.h"
//school year
void schoolyear(int a, int b)
{

	if (a < 0 || b < 0)
	{
		wcout << "errol";
		return;
	}
	wcout << "school year: " << a << "-" << b << endl;
	
}
void inputstudent(wstring inputstd, node*& phead)
{
	wifstream student;
	student.open(L"inputstd");
	if (student.fail() == true)
	{
		wcout << "cant open file";
		return;
	}
	else
	{
		int n;
		student >> n;
		if (phead == nullptr)
		{
			phead = new node;
		}
		for (int i = 1; i <= n; i++)
		{
			getline(student, phead->No, L',');
			getline(student, phead->firstname, L',');
			getline(student, phead->lastname, L',');
			getline(student, phead->ID, L',');
			getline(student, phead->gender, L',');
			getline(student, phead->dateofbirth, L',');
			getline(student, phead->socialID);
			phead = phead->pnext;
			phead->pnext = nullptr;
		}
		student.close();
	}
}
	void liststudent(node* phead)
	{
		wcout << "No" << setw(20) << "Firstname" << setw(20) << "Lastname" << setw(20) << "StudentID" << setw(20) << "Gender" << setw(20) << "DayofBirth" << setw(20) << "SocialID" << endl;

		while (phead != nullptr)
		{
			wcout << setw(25) << phead->No << setw(25) << phead->firstname << setw(25) << phead->lastname << setw(25) << phead->ID << setw(25) << phead->gender << setw(25) << phead->dateofbirth << setw(25) << phead->socialID;
			wcout << endl;
			phead = phead->pnext;
		}
    }
//list of classes

//add new student
/*void addstudent(wstring classnumber, int n)
{
	input in;
	if (n < 0)
	{
		wcout << "errol";
		return ;
	}
	for (int i = 0; i < n; i++)
	{
		wcout << "the student " << i + 1;
		getline(wcin,in.firstname);
		getline(wcin, in.lastname);
		getline(wcin, in.ID);
		getline(wcin, in.gender);
		getline(wcin, in.dateofbirth);
		getline(wcin, in.socialID);
	}
	cout << "the new list of class ";

}*/

