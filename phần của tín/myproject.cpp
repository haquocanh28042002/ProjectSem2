#include"myproject.h"
//school year

void liststudent(node* phead)
{
	wcout<<endl << "No" << setw(20) << "Firstname" << setw(20) << "Lastname" << setw(20) << "StudentID" << setw(20) << "Gender" << setw(20) << "DayofBirth" << setw(20) << "SocialID" << endl;
	while (phead != nullptr)
	{
		wcout << phead->No << setw(20) << phead->firstname << setw(20) << phead->lastname << setw(20) << phead->ID << setw(20) << phead->gender << setw(20) << phead->dateofbirth << setw(20) << phead->socialID;
		wcout << endl;
		phead = phead->pnext;
	}
}
void addnewstudent(wstring classx,node* phead)
{
	if (phead == nullptr) return;
	wstring No;
	wstring ID; wstring socialID;
	wstring firstname; wstring lastname; wstring gender; wstring dateofbirth;
	node* pcur = phead;
	int t=1;
	while (pcur->pnext != nullptr)
	{
		pcur = pcur->pnext;
		++t;
	}
	No = to_wstring(t + 1);
	pcur->pnext = new node;
	pcur = pcur->pnext;
//	wcout << "No ";
	//getline(wcin, No);
	wcout << "\n the first name ";
	getline(wcin, firstname);
	wcout << "\n the last name ";
	getline(wcin, lastname);
	wcout << "\n ID ";
	getline(wcin, ID);
	wcout << "\n gender: ";
	getline(wcin, gender);
	wcout << "\ndate of birth ";
	getline(wcin, dateofbirth);
	wcout << "\n the social ID  ";
	getline(wcin, socialID);
	pcur->No =No;
	pcur->firstname = firstname;
	pcur->lastname = lastname;
	pcur->ID = ID;
	pcur->gender = gender;
	pcur->dateofbirth = dateofbirth;
	pcur->socialID = socialID;
	pcur->pnext = nullptr;
	wstring s = L",";
	wofstream student;
	student.open(classx, ios::out|ios::app);
	student.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	student << s;
	student << endl;
	student << pcur->No << s << pcur->firstname << s << pcur->lastname << s << pcur->ID << s << pcur->gender << s << pcur->dateofbirth <<s << pcur->socialID ;

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
void inputstudentscore(wstring classx,node*& phead)
{
	wifstream student;
	student.open(classx,ios::in);
	student.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	if (student.fail() == true)
	{
		wcout << "can't open file\n";
		return;
	}
	else
	{
		node* pcur = nullptr;
		wstring No; wstring ID; wstring socialID;
		wstring firstname; wstring lastname; wstring gender; wstring dateofbirth;
		wstring totalmark; wstring midtermmark;
		wstring finalmark; wstring orthermark;
		while(!student.eof())
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
				pcur->pnext = nullptr;
			}
			getline(student, No, L',');
			getline(student, firstname, L',');
			getline(student, lastname, L',');
			getline(student, ID, L',');
			getline(student, gender, L',');
			getline(student, dateofbirth, L',');
			getline(student, socialID, L',');
			getline(student, midtermmark, L',');
			//wcin.ignore();
			getline(student, finalmark, L',');
			getline(student, totalmark, L',');
			getline(student, orthermark, L',');
			getline(student, finalmark);
			pcur->No = No;
			pcur->firstname = firstname;
			pcur->lastname = lastname;
			pcur->ID = ID;
			pcur->gender = gender;
			pcur->dateofbirth = dateofbirth;
			pcur->socialID = socialID;
			pcur->finalmark = finalmark;
			pcur->midtermmark = midtermmark;
			pcur->orthermark = orthermark;
			pcur->totalmark = totalmark;
			pcur->pnext = nullptr;

		}
	}
	student.close();
}
void liststudentwithscore(node* phead)
{
	wcout << "No" << setw(20) << "Firstname" << setw(20) << "Lastname" << setw(20) << "StudentID" << setw(20) << "Gender" << setw(20) << "DayofBirth" << setw(20) << "SocialID" << setw(20) << "Midtermmark" << setw(20) << "Finalmark" << setw(20) << "orthermark" << setw(20) << "Totalmark" << endl;
	node*pcur = phead;
	while (pcur != nullptr)
	{
		wcout << pcur->No << setw(20) << pcur->firstname << setw(20) << pcur->lastname << setw(20) << pcur->ID << setw(20) << pcur->gender << setw(20) << pcur->dateofbirth << setw(20) << pcur->socialID << setw(20) << pcur->midtermmark << setw(20) << pcur->finalmark << setw(20) << pcur->orthermark << setw(20) << pcur->totalmark;
		wcout << endl;
		pcur = pcur->pnext;
	}
}
/*void import(wstring classx, node*& phead)
{
	if (phead == nullptr)return;
	wofstream student;
	student.open(classx, ios::out);
	while (phead != nullptr)
	{
		student << phead->No << "," << phead->firstname << "," << phead->lastname << "," << phead->ID << "," << phead->gender << "," << phead->dateofbirth << "," << phead->socialID << endl;
		phead = phead->pnext;
	}
	student.close();
}
void importscoreboard(wstring classx,node*& phead)
{
	if (phead == nullptr)return;
	wofstream student;
	student.open(classx,ios::out);
	while (phead != nullptr)
	{
		student << phead->No << "," << phead->firstname << "," << phead->lastname << "," << phead->ID << "," << phead->gender << "," << phead->dateofbirth << "," << phead->socialID << endl;
		phead = phead->pnext;
	}
	student.close();
}
void addscoreofnewstudet(wstring classx, node* phead)
{
	if (phead == nullptr) return;
	node* pcur = phead;
	wcout << "\nscore of new student \n";
	while (pcur->pnext != nullptr)
	{
		pcur = pcur->pnext;
	}
	wcin.ignore();
	wcout << "\nmidterm score: ";
	getline(wcin, pcur->midtermmark);
	wcout << "\n final score: ";
	getline(wcin, pcur->firstname);
	wcout << "\norther score: ";
	getline(wcin, pcur->orthermark);
	wcout << "\ntotal score: ";
	getline(wcin, pcur->totalmark);
	wofstream student;
	student.open(classx, ios::out);
	while (pcur->pnext != nullptr) pcur = pcur->pnext;
	student << pcur->midtermmark << "," << pcur->finalmark << "," << pcur->orthermark << "," << pcur->totalmark << endl;

	student.close();
}*/