#include"myproject.h"
#include"console.h"
#include"Menu.h"
void menu1()
{
    node* phead = nullptr;
    node* phead1 = nullptr;
    wstring class1 = L"inputstudentscore.csv";
    wstring class2 = L"inputstudentscore2.txt";
    wstring class3 = L"inputstudentscore3.txt";
    wstring class4 = L"inputstudentscore4.txt";
    wstring course = L"inputcourse.csv";
    wstring course1 = L"inputcourse1.csv";
    wstring course2 = L"inputcourse2.csv";
    wstring course3 = L"inputcourse3.csv";
    wstring course4 = L"inputcourse4.csv";
    wstring course5 = L"inputcourse5.csv";
    wstring course6 = L"inputcourse6.csv";
    int n = 1;
    while (n != 0)
    {
        wcout << "\nSchool year: " << endl;
        wcout << "1. 2020-2021\n     1st year student \n";
        wcout << "2. 2021-2022\n     2st year student \n";
        wcout << "3. 2022-2023\n     3st year student \n";
        wcout << "4. 2023-2024\n     4st year student \n";
        wcout << "0. cancel\n";    
        wcin >> n;
        system("cls");
        switch (n)
        {
        case 1:
        {
            wcout << "\n1. Class  ";
            wcout << "\n2. Course ";
            wcout << "\n0. cancel \n";
            int t1;
            wcin >> t1;
            system("cls");
            while (t1 != 0)
            {
                switch (t1)
                {
                case 1:
                {
                    wcout << "\n1. Class 20CLC1 ";
                    wcout << "\n2. Class 20CLC2 ";
                    wcout << "\n3. Class 20CLC3 ";
                    wcout << "\n4. Class 20CLC4 ";
                    wcout << "\n0. Back\n ";
                    int t2;
                    wcin >> t2;
                    system("cls");
                    while (t2 != 0)
                    {
                        switch (t2)
                        {
                        case 1:
                        {
                            int t3;
                            wcout << "\n1. Class list ";
                            wcout << "\n2. Add new student ";
                            wcout << "\n3. score ";
                            wcout << "\n4. score course ";
                            wcout << "\n0. cancel\n ";
                            wcin >> t3;
                            inputstudentscore(class1, phead);
                            system("cls");
                            while (t3 != 0)
                            {
                                switch (t3)
                                {
                                case 1:
                                {
                                    liststudent(phead);
                                    break;
                                }
                                case 2:
                                {
                                    // inputstudentscore(class1, phead);
                                    addnewstudent(class1, phead);
                                    system("cls");
                                    liststudent(phead);
                                    break;
                                }
                                case 3:
                                {
                                    //inputstudentscore(class1, phead);
                                    liststudentwithscore(phead);
                                    break;
                                }
                                case 4:
                                {
                                    int t4 = 1;
                                    while (t4 != 0)
                                    {
                                        wcout << L"\n1. KỸ THUẬT LẬP TRÌNH  ";
                                        wcout << L"\n2. VI TÍCH PHÂN  ";
                                        wcout << L"\n3. VẬT LÝ ĐẠI CƯƠNG ";
                                        wcout << L"\n4. TRIẾT HỌC ";
                                        wcout << L"\n5. NHẬP MÔN LẬP TRÌNH ";
                                        wcout << L"\n6. KINH TẾ ĐẠI CƯƠNG ";
                                        wcout << L"\n7. TOÁN RỜI RẠC ";
                                        wcout << "\n0. cancel\n";
                                        wcin >> t4;
                                        system("cls");
                                        switch (t4)
                                        {
                                        case 1:
                                        {
                                            read_course(course, phead1);
                                            scorecourse(phead1);
                                            break;
                                        }
                                        case 2:
                                        {
                                            read_course(course1, phead1);
                                            scorecourse(phead1);
                                            break;
                                        }
                                        case 3:
                                        {
                                            read_course(course2, phead1);
                                            scorecourse(phead1);
                                            break;
                                        }
                                        case 4:
                                        {
                                            read_course(course3, phead1);
                                            scorecourse(phead1);
                                            break;
                                        }
                                        case 5:
                                        {
                                            read_course(course4, phead1);
                                            scorecourse(phead1);
                                            break;
                                        }
                                        case 6:
                                        {
                                            read_course(course5, phead1);
                                            scorecourse(phead1);
                                            break;
                                        }
                                        case 7:
                                        {
                                            read_course(course6, phead1);
                                            scorecourse(phead1);
                                            break;
                                        }
                                        case 0:
                                            break;
                                            if (t4 != 0)
                                            {
                                                wcout << L"\n1. KỸ THUẬT LẬP TRÌNH  ";
                                                wcout << L"\n2. VI TÍCH PHÂN  ";
                                                wcout << L"\n3. VẬT LÝ ĐẠI CƯƠNG ";
                                                wcout << L"\n4. TRIẾT HỌC ";
                                                wcout << L"\n5. NHẬP MÔN LẬP TRÌNH ";
                                                wcout << L"\n6. KINH TẾ ĐẠI CƯƠNG ";
                                                wcout << L"\n7. TOÁN RỜI RẠC ";
                                                wcout << "\n0. cancel\n";
                                                wcin >> t4;
                                                system("cls");
                                            }

                                        }
                                    }

                                    break;
                                }
                                case 0:  break;
                                
                                }
                                if (t3 != 0)
                                {
                                    wcout << "\n1. Class list ";
                                    wcout << "\n2. Add new student ";
                                    wcout << "\n3. score ";
                                    wcout << "\n4. score course ";
                                    wcout << "\n0. cancel\n ";
                                    wcin >> t3;
                                    system("cls");
                                }
                            }
                            break;
                        }
                        case 2:
                        {
                            int t3;
                            wcout << "\n1. Class list ";
                            wcout << "\n2. Add new student ";
                            wcout << "\n3. score ";
                            wcout << "\n4. score course";
                            wcout << "\n0. cancel\n ";
                            wcin >> t3;
                            inputstudentscore(class2, phead);
                            system("cls");
                            while (t3 != 0)
                            {
                                switch (t3)
                                {
                                case 1:
                                {
                                    liststudent(phead);
                                    break;
                                }
                                case 2:
                                {
                                    // inputstudentscore(class1, phead);
                                    addnewstudent(class2, phead);
                                    system("cls");
                                    liststudent(phead);
                                    break;
                                }
                                case 3:
                                {
                                    //inputstudentscore(class1, phead);
                                    liststudentwithscore(phead);
                                    break;
                                }
                                case 4:
                                {
                                    int t4 = 1;
                                    while (t4 != 0)
                                    {
                                        wcout << L"\n1. KỸ THUẬT LẬP TRÌNH  ";
                                        wcout << L"\n2. VI TÍCH PHÂN  ";
                                        wcout << L"\n3. VẬT LÝ ĐẠI CƯƠNG ";
                                        wcout << L"\n4. TRIẾT HỌC ";
                                        wcout << L"\n5. NHẬP MÔN LẬP TRÌNH ";
                                        wcout << L"\n6. KINH TẾ ĐẠI CƯƠNG ";
                                        wcout << L"\n7. TOÁN RỜI RẠC ";
                                        wcout << "\n0. cancel\n";
                                        wcin >> t4;
                                        system("cls");
                                        switch (t4)
                                        {
                                        case 1:
                                        {
                                            read_course(course, phead1);
                                            scorecourse(phead1);
                                            break;
                                        }
                                        case 2:
                                        {
                                            read_course(course1, phead1);
                                            scorecourse(phead1);
                                            break;
                                        }
                                        case 3:
                                        {
                                            read_course(course2, phead1);
                                            scorecourse(phead1);
                                            break;
                                        }
                                        case 4:
                                        {
                                            read_course(course3, phead1);
                                            scorecourse(phead1);
                                            break;
                                        }
                                        case 5:
                                        {
                                            read_course(course4, phead1);
                                            scorecourse(phead1);
                                            break;
                                        }
                                        case 6:
                                        {
                                            read_course(course5, phead1);
                                            scorecourse(phead1);
                                            break;
                                        }
                                        case 7:
                                        {
                                            read_course(course6, phead1);
                                            scorecourse(phead1);
                                            break;
                                        }
                                        case 0:
                                            break;
                                            if (t4 != 0)
                                            {
                                                wcout << L"\n1. KỸ THUẬT LẬP TRÌNH  ";
                                                wcout << L"\n2. VI TÍCH PHÂN  ";
                                                wcout << L"\n3. VẬT LÝ ĐẠI CƯƠNG ";
                                                wcout << L"\n4. TRIẾT HỌC ";
                                                wcout << L"\n5. NHẬP MÔN LẬP TRÌNH ";
                                                wcout << L"\n6. KINH TẾ ĐẠI CƯƠNG ";
                                                wcout << L"\n7. TOÁN RỜI RẠC ";
                                                wcout << "\n0. cancel\n";
                                                wcin >> t4;
                                                system("cls");
                                            }

                                        }
                                    }
                                    break;
                                }
                                case 0:
                                {
                                    break;
                                }
                                }
                                if (t3 != 0)
                                {
                                    wcout << "\n1. Class list ";
                                    wcout << "\n2. Add new student ";
                                    wcout << "\n3. score ";
                                    wcout << "\n4. score course";
                                    wcout << "\n0. cancel\n ";
                                    wcin >> t3;
                                    system("cls");
                                }
                            }
                            break;
                        }
                        case 3:
                        {
                            int t3;
                            wcout << "\n1. Class list ";
                            wcout << "\n2. Add new student ";
                            wcout << "\n3. score ";
                            wcout << "\n4. score course";
                            wcout << "\n0. cancel\n ";
                            wcin >> t3;
                            inputstudentscore(class3, phead);
                            system("cls");
                            while (t3 != 0)
                            {
                                switch (t3)
                                {
                                case 1:
                                {
                                    liststudent(phead);
                                    break;
                                }
                                case 2:
                                {
                                    // inputstudentscore(class1, phead);
                                    addnewstudent(class3, phead);
                                    system("cls");
                                    liststudent(phead);
                                    break;
                                }
                                case 3:
                                {
                                    //inputstudentscore(class1, phead);
                                    liststudentwithscore(phead);
                                    break;
                                }
                                case 4:
                                {
                                    int t4 = 1;
                                    while (t4 != 0)
                                    {
                                        wcout << L"\n1. KỸ THUẬT LẬP TRÌNH  ";
                                        wcout << L"\n2. VI TÍCH PHÂN  ";
                                        wcout << L"\n3. VẬT LÝ ĐẠI CƯƠNG ";
                                        wcout << L"\n4. TRIẾT HỌC ";
                                        wcout << L"\n5. NHẬP MÔN LẬP TRÌNH ";
                                        wcout << L"\n6. KINH TẾ ĐẠI CƯƠNG ";
                                        wcout << L"\n7. TOÁN RỜI RẠC ";
                                        wcout << "\n0. cancel\n";
                                        wcin >> t4;
                                        system("cls");
                                        switch (t4)
                                        {
                                        case 1:
                                        {
                                            read_course(course, phead1);
                                            scorecourse(phead1);
                                            break;
                                        }
                                        case 2:
                                        {
                                            read_course(course1, phead1);
                                            scorecourse(phead1);
                                            break;
                                        }
                                        case 3:
                                        {
                                            read_course(course2, phead1);
                                            scorecourse(phead1);
                                            break;
                                        }
                                        case 4:
                                        {
                                            read_course(course3, phead1);
                                            scorecourse(phead1);
                                            break;
                                        }
                                        case 5:
                                        {
                                            read_course(course4, phead1);
                                            scorecourse(phead1);
                                            break;
                                        }
                                        case 6:
                                        {
                                            read_course(course5, phead1);
                                            scorecourse(phead1);
                                            break;
                                        }
                                        case 7:
                                        {
                                            read_course(course6, phead1);
                                            scorecourse(phead1);
                                            break;
                                        }
                                        case 0:
                                            break;
                                            if (t4 != 0)
                                            {
                                                wcout << L"\n1. KỸ THUẬT LẬP TRÌNH  ";
                                                wcout << L"\n2. VI TÍCH PHÂN  ";
                                                wcout << L"\n3. VẬT LÝ ĐẠI CƯƠNG ";
                                                wcout << L"\n4. TRIẾT HỌC ";
                                                wcout << L"\n5. NHẬP MÔN LẬP TRÌNH ";
                                                wcout << L"\n6. KINH TẾ ĐẠI CƯƠNG ";
                                                wcout << L"\n7. TOÁN RỜI RẠC ";
                                                wcout << "\n0. cancel\n";
                                                wcin >> t4;
                                                system("cls");
                                            }

                                        }
                                    }
                                    break;
                                }
                                case 0:
                                {
                                    break;
                                }
                                }
                                if (t3 != 0)
                                {
                                    wcout << "\n1. Class list ";
                                    wcout << "\n2. Add new student ";
                                    wcout << "\n3. score ";
                                    wcout << "\n4. score course";
                                    wcout << "\n0. cancel\n ";
                                    wcin >> t3;
                                    system("cls");
                                }
                            }
                            break;
                        }
                        case 4:
                        {
                            int t3;
                            wcout << "\n1. Class list ";
                            wcout << "\n2. Add new student ";
                            wcout << "\n3. score ";
                            wcout << "\n4. score course";
                            wcout << "\n0. cancel\n ";
                            wcin >> t3;
                            inputstudentscore(class4, phead);
                            system("cls");
                            while (t3 != 0)
                            {
                                switch (t3)
                                {
                                case 1:
                                {
                                    liststudent(phead);
                                    break;
                                }
                                case 2:
                                {
                                    // inputstudentscore(class1, phead);
                                    addnewstudent(class4, phead);
                                    system("cls");
                                    liststudent(phead);
                                    break;
                                }
                                case 3:
                                {
                                    //inputstudentscore(class1, phead);
                                    liststudentwithscore(phead);
                                    break;
                                }
                                case 4:
                                {
                                    break;
                                }
                                case 0:
                                {
                                    int t4 = 1;
                                    while (t4 != 0)
                                    {
                                        wcout << L"\n1. KỸ THUẬT LẬP TRÌNH  ";
                                        wcout << L"\n2. VI TÍCH PHÂN  ";
                                        wcout << L"\n3. VẬT LÝ ĐẠI CƯƠNG ";
                                        wcout << L"\n4. TRIẾT HỌC ";
                                        wcout << L"\n5. NHẬP MÔN LẬP TRÌNH ";
                                        wcout << L"\n6. KINH TẾ ĐẠI CƯƠNG ";
                                        wcout << L"\n7. TOÁN RỜI RẠC ";
                                        wcout << "\n0. cancel\n";
                                        wcin >> t4;
                                        system("cls");
                                        switch (t4)
                                        {
                                        case 1:
                                        {
                                            read_course(course, phead1);
                                            scorecourse(phead1);
                                            break;
                                        }
                                        case 2:
                                        {
                                            read_course(course1, phead1);
                                            scorecourse(phead1);
                                            break;
                                        }
                                        case 3:
                                        {
                                            read_course(course2, phead1);
                                            scorecourse(phead1);
                                            break;
                                        }
                                        case 4:
                                        {
                                            read_course(course3, phead1);
                                            scorecourse(phead1);
                                            break;
                                        }
                                        case 5:
                                        {
                                            read_course(course4, phead1);
                                            scorecourse(phead1);
                                            break;
                                        }
                                        case 6:
                                        {
                                            read_course(course5, phead1);
                                            scorecourse(phead1);
                                            break;
                                        }
                                        case 7:
                                        {
                                            read_course(course6, phead1);
                                            scorecourse(phead1);
                                            break;
                                        }
                                        case 0:
                                            break;
                                            if (t4 != 0)
                                            {
                                                wcout << L"\n1. KỸ THUẬT LẬP TRÌNH  ";
                                                wcout << L"\n2. VI TÍCH PHÂN  ";
                                                wcout << L"\n3. VẬT LÝ ĐẠI CƯƠNG ";
                                                wcout << L"\n4. TRIẾT HỌC ";
                                                wcout << L"\n5. NHẬP MÔN LẬP TRÌNH ";
                                                wcout << L"\n6. KINH TẾ ĐẠI CƯƠNG ";
                                                wcout << L"\n7. TOÁN RỜI RẠC ";
                                                wcout << "\n0. cancel\n";
                                                wcin >> t4;
                                                system("cls");
                                            }

                                        }
                                    }
                                    break;
                                }
                                }
                                if (t3 != 0)
                                {
                                    wcout << "\n1. Class list ";
                                    wcout << "\n2. Add new student ";
                                    wcout << "\n3. score ";
                                    wcout << "\n4. score course";
                                    wcout << "\n0. cancel\n ";
                                    wcin >> t3;
                                    system("cls");
                                }

                            }
                            break;
                        }
                        case 0: break;
                        }
                        if (t2 != 0)
                        {
                            wcout << "\n1. Class 20CLC1 ";
                            wcout << "\n2. Class 20CLC2 ";
                            wcout << "\n3. Class 20CLC3 ";
                            wcout << "\n4. Class 20CLC4 ";
                            wcout << "\n0. Back\n ";
                            wcin >> t2;
                            system("cls");
                        }
                    }
                    break;
                }
                case 2:
                    menu(thaotac,4);
                    break;
                case 0: break;
             
                }
                break;
            }
        }
        case 2:
        {
            cout << "no data ";
            break;
        }
        case 3: 
        {
            cout << "no data ";
            break;
        }
        case 4:
        {
            cout << "no data ";
            break;
        }
        case 0: break;
        }
        if (n != 0)
        {
            wcout << "\nschool year: " << endl;
            wcout << "1. 2020-2021\n     1st year student \n";
            wcout << "2. 2021-2022\n     2st year student \n";
            wcout << "3. 2022-2023\n     3st year student \n";
            wcout << "4. 2023-2024\n     4st year student \n";
            wcout << "0. cancel\n";
            wcin >> n;
            system("cls");
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
     menu1();    
}