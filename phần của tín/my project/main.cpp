#include"myproject.h"
void menu()
{
    node* phead = nullptr;
    node* phead1 = nullptr;
    wstring class1 = L"inputstudentscore.txt";
    wstring class2 = L"inputstudentscore2.txt";
    wstring class3 = L"inputstudentscore3.txt";
    wstring class4 = L"inputstudentscore4.txt";
    wcout << "school year: 2020-2021\n";
    int n = 1;
    while (n != 0)
    {
        wcout << "\n1. Class  ";
        wcout << "\n2. Score ";
        wcout << "\n0. cancel \n";
        wcin >> n;
        system("cls");
        switch (n)
        {
        case 1:
        {
            wcout << "\n1. Class 20CLC1 ";
            wcout << "\n2. Class 20CLC2 ";
            wcout << "\n3. Class 20CLC3 ";
            wcout << "\n4. Class 20CLC4 ";
            wcout << "\n0. Back\n ";
            int t1;
            wcin >> t1;
            system("cls");
            while (t1 != 0)
            {
                switch (t1)
                {
                case 1:
                {
                    int t2 = 1;
                    inputstudentscore(class1, phead);
                    liststudent(phead);
                    wcout << "\nyou want to add new student ";
                    wcout << "\n1.Yes ";
                    wcout << "\n0.No \n";

                    wcin >> t2;
                    system("cls");
                    while (t2 != 0)
                    {
                        wcin.ignore();
                        switch (t2)
                        {
                        case 1:
                        {
                            addnewstudent(class1, phead);
                            liststudent(phead);
                            break;
                        }
                        case 0: break;
                        }
                        if (t2 != 0)
                        {
                            wcout << "\nDo you want to continue add new student  ";
                            wcout << "\n1.Yes ";
                            wcout << "\n0.No \n";
                            wcin >> t2;
                            system("cls");
                        }
                    }
                    break;
                }
                case 2:
                {
                    int t2 = 1;
                    inputstudentscore(class2, phead);
                    liststudent(phead);
                    wcout << "\nyou want to add new student ";
                    wcout << "\n1.Yes ";
                    wcout << "\n0.No \n";
                    wcin >> t2;
                    system("cls");
                    while (t2 != 0)
                    {
                        wcin.ignore();
                        switch (t2)
                        {
                        case 1:
                        {
                            addnewstudent(class2, phead);
                            liststudent(phead);
                            break;
                        }
                        case 0: break;
                        }
                        if (t2 != 0)
                        {
                            wcout << "\nDo you want to continue add new student  ";
                            wcout << "\n1.Yes ";
                            wcout << "\n0.No \n";
                            wcin >> t2;
                            system("cls");
                        }
                    }
                    break;
                }
                case 3:
                {
                    int t2 = 1;
                    inputstudentscore(class3, phead);
                    liststudent(phead);
                    wcout << "\nyou want to add new student ";
                    wcout << "\n1.Yes ";
                    wcout << "\n0.No \n";
                    wcin >> t2;
                    system("cls");
                    while (t2 != 0)
                    {
                        wcin.ignore();
                        switch (t2)
                        {
                        case 1:
                        {
                            addnewstudent(class3, phead);
                            liststudent(phead);
                            break;
                        }
                        case 0: break;
                        }
                        if (t2 != 0)
                        {
                            wcout << "\nDo you want to continue add new student  ";
                            wcout << "\n1.Yes ";
                            wcout << "\n0.No \n";
                            wcin >> t2;
                            system("cls");
                        }
                    }
                    break;
                }
                case 4:
                {
                    int t2 = 1;
                    inputstudentscore(class4, phead);
                    liststudent(phead);
                    wcout << "\nyou want to add new student ";
                    wcout << "\n1.Yes ";
                    wcout << "\n0.No \n";
                    wcin >> t2;
                    system("cls");
                    while (t2 != 0)
                    {
                        wcin.ignore();
                        switch (t2)
                        {
                        case 1:
                        {
                            addnewstudent(class4, phead);
                            liststudent(phead);
                            break;
                        }
                        case 0: break;
                        }
                        if (t2 != 0)
                        {
                            wcout << "\nDo you want to continue add new student  ";
                            wcout << "\n1.Yes ";
                            wcout << "\n0.No \n";
                            wcin >> t2;
                            system("cls");
                        }
                    }
                    break;
                }
                case 0: break;
                }
                if (t1 != 0)
                {
                    wcout << "\n Continue view ";
                    wcout << "\n1. Class 20CLC1 ";
                    wcout << "\n2. Class 20CLC2 ";
                    wcout << "\n3. Class 20CLC3 ";
                    wcout << "\n4. Class 20CLC4 ";
                    wcout << "\n0. Back\n ";
                    wcin >> t1;
                    system("cls");
                }
                deletelist(phead);
            }
            break;
        }
        case 2:
        {
            wcout << "\n1. Class 20CLC1 ";
            wcout << "\n2. Class 20CLC2 ";
            wcout << "\n3. Class 20CLC3 ";
            wcout << "\n4. Class 20CLC4 ";
            wcout << "\n0. Back \n";
            int t1;
            wcin >> t1;
            system("cls");
            while (t1 != 0)
            {
                switch (t1)
                {
                case 1:
                {
                    inputstudentscore(class1, phead);
                    liststudentwithscore(phead);
                    break;
                }
                case 2:
                {
                    inputstudentscore(class2, phead);               //   addscoreofnewstudet(class2, phead);
                    liststudentwithscore(phead);
                    break;
                }
                case 3:
                {
                    inputstudentscore(class3, phead);               //   addscoreofnewstudet(class3, phead);
                    liststudentwithscore(phead);
                    break;
                }
                case 4:
                {
                    inputstudentscore(class4, phead);                 //  addscoreofnewstudet(class4, phead);
                    liststudentwithscore(phead);
                    break;
                }
                case 0: break;
                }
                if (t1 != 0)
                {
                    wcout << "\n Continue view ";
                    wcout << "\n1. Class 20CLC1 ";
                    wcout << "\n2. Class 20CLC2 ";
                    wcout << "\n3. Class 20CLC3 ";
                    wcout << "\n4. Class 20CLC4 ";
                    wcout << "\n0. Back\n ";
                    wcin >> t1;
                    system("cls");
                }

                deletelist(phead);
            }
            break;
        }
        case 0: break;
        }
    }
}
void main()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    HANDLE hdlConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX consoleFont;
    consoleFont.cbSize = sizeof(consoleFont);
    GetCurrentConsoleFontEx(hdlConsole, FALSE, &consoleFont);
    memcpy(consoleFont.FaceName, L"Consolas", sizeof(consoleFont.FaceName));
    SetCurrentConsoleFontEx(hdlConsole, FALSE, &consoleFont);
    menu();
    system("pause");
}