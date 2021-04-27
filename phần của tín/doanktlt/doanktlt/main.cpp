#include"myproject.h"
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
	wstring inputstd = L"inputstd.txt";
    int a, b;
    wcout << "number of schoolyear\n";
    wcin >> a >> b;
    schoolyear(a, b);
    wcout << endl;
    inputstudent(inputstd);
    system("pause");
}