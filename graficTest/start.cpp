#include "grafic.h"
#include "action.h"
#include "Header.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	bgShow();
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwWritten;
    COORD coord = { 0, 0 };
    while (true) {
        if (_kbhit()) {
            wchar_t show;
            char key = _getch();
            cout << int(key) << endl;
            MultiByteToWideChar(CP_ACP, 0, &key, 1, &show, 1);
            WriteConsoleOutputCharacter(hConsole, &show, 1, coord, &dwWritten);
            if (key == 'w') {

            }
            if (key == 's') {

            }
        }
        //showObj();
        sinMove();
    }
	return 0;
}