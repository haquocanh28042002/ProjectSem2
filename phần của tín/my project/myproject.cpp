#include"myproject.h"

void liststudent(node* phead)
{
	wcout  << "No" << setw(20) << "StudentID" << setw(20) << "Firstname"  << setw(20) <<"Lastname" << setw(20) << "Gender" << setw(20) << "DayofBirth" << setw(20) << "SocialID" << endl;
	while (phead != nullptr)
	{
		wcout << phead->No << setw(20) << phead->ID << setw(20) << phead->firstname << setw(20) << phead->lastname << setw(20) << phead->gender << setw(20) << phead->dateofbirth << setw(20) << phead->socialID;
		wcout << endl;
		phead = phead->pnext;
	}
}
void addnewstudent(wstring classx, node* phead)
{
	if (phead == nullptr) return;
	wstring No;
	wstring ID; wstring socialID;
	wstring firstname; wstring lastname; wstring gender; wstring dateofbirth;
	node* pcur = phead;
	int t = 0;
	while (pcur->pnext != nullptr)
	{
		pcur = pcur->pnext;
		++t;
	}
	No = to_wstring(t + 1);
	pcur->pnext = new node;
	pcur = pcur->pnext;
	wcin.ignore();
	wcout << "\n the first name: ";
	getline(wcin, firstname);
	wcout << "\n the last name: ";
	getline(wcin, lastname);
	wcout << "\n ID: ";
	getline(wcin, ID);
	wcout << "\n gender: ";
	getline(wcin, gender);
	wcout << "\ndate of birth: ";
	getline(wcin, dateofbirth);
	wcout << "\n the social ID:  ";
	getline(wcin, socialID);
	pcur->No = No;
	pcur->firstname = firstname;
	pcur->lastname = lastname;
	pcur->ID = ID;
	pcur->gender = gender;
	pcur->dateofbirth = dateofbirth;
	pcur->socialID = socialID;
	pcur->pnext = nullptr;
	wstring s = L",";
	wofstream student;
	student.open(classx, ios::out | ios::app);
	student.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	student << pcur->No << s << pcur->ID << s << pcur->firstname << s << pcur->lastname << s << pcur->gender << s << pcur->dateofbirth << s << pcur ->socialID;
	student << endl;
	student.close();
}
void deletelist(node*& phead)
{
	node* ptmp = phead;
	while (phead != nullptr)
	{
		phead = phead->pnext;
		delete ptmp;
		ptmp = phead;
	}
}
void inputstudentscore(wstring classx, node*& phead)
{
	wifstream student;
	student.open(classx, ios::in);
	student.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	student.seekg(3);
	if (student.fail() == true)
	{
		wcout << "can't open file\n";
		system("pause");
	}	
		node* pcur = nullptr;
		while (!student.eof())
		{
			if (phead == nullptr)
			{
				phead = new node;
				pcur = phead;
			}
			else
			{
				pcur->pnext = new node;
				pcur = pcur->pnext;
			}
			getline(student, pcur->No, L',');			
			getline(student, pcur->ID, L',');
			getline(student, pcur->firstname, L',');
			getline(student, pcur->lastname, L',');
			getline(student, pcur->gender, L',');
			getline(student, pcur->dateofbirth, L',');
			getline(student, pcur->socialID, L',');
			getline(student, pcur->averagemark, L',');
			getline(student, pcur->gpa);
			pcur->pnext = nullptr;
		}
	student.close();
}
void liststudentwithscore(node* phead)
{
	wcout<<endl << "No" << setw(20) << "StudentID" << setw(20) << "Firstname" << setw(20) << "Lastname" << setw(20) << "Average mark"<<setw(20)<<"GPA"<< endl;
	while (phead != nullptr)
	{
		wcout << phead->No << setw(20) << phead->ID << setw(20) << phead->firstname << setw(20) << phead->lastname << setw(20) << phead->averagemark << setw(20) << phead->gpa;
		wcout << endl;
		phead = phead->pnext;
	}
}
void read_course(wstring classx,node*& phead1)
{
	wifstream student;
	student.open(classx, ios::in);
	student.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	student.seekg(3);
	if (student.fail() == true)
	{
		wcout << "can't open file\n";
		return;
	}
	else
	{
		node* pcur1 = nullptr;
		while (!student.eof())
		{
			if (phead1 == nullptr)
			{
				phead1 = new node;
				pcur1 = phead1;
			}
			else
			{
				pcur1->pnext = new node;
				pcur1 = pcur1->pnext;
				pcur1->pnext = nullptr;
			}
			//getline(student, pcur1->course, L',');
			getline(student, pcur1->No, L',');
			getline(student, pcur1->ID, L',');
			getline(student, pcur1->firstname, L',');
			getline(student, pcur1->lastname, L',');
			getline(student, pcur1->midtermmark, L',');			
			getline(student, pcur1->finalmark, L',');
			getline(student, pcur1->orthermark, L',');
			getline(student, pcur1->totalmark);
			//wcin.ignore();
			pcur1->pnext = nullptr;
		}
	}
	student.close();
	//scorecourse(phead1);
}
void scorecourse(node* phead1)
{
	if (phead1 == nullptr) return;
	wcout << endl << "No" << setw(20) << "StudentID" << setw(20) << "Firstname" << setw(20) << "Lastname"  <<setw(20)<< "Midtermmark" << setw(20) << "Finalmark" << setw(20) << "orthermark" << setw(20) << "Totalmark" << endl;
	//node* pcur1 = phead1;
	while (phead1 != nullptr)
	{
		wcout << phead1->No << setw(20) << phead1->ID << setw(20) << phead1->firstname << setw(20) << phead1->lastname  <<setw(20) << phead1->midtermmark << setw(20) << phead1->finalmark << setw(20) << phead1->orthermark << setw(20) << phead1->totalmark;
		wcout << endl;
		phead1 = phead1->pnext;
	}
}



