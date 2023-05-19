#include "grafic.h"
#include "Header.h"

short int updateMatrx[24][81];
char showMatrix[24][81];



objForGraf testObj = { 0, 11, &box };

void bgShow() {
	for (int i = 0; i < bg.hight; i++)
	{
		for (int j = 0; j < bg.wight; j++) {
			cout << bg.img[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < bg.hight; i++)
		for (int j = 0; j < bg.wight; j++)
			updateMatrx[i][j] = -1;
}

void test() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwWritten;
	COORD coord = { testObj.y, testObj.x};
	wchar_t* wText = new wchar_t[testObj.img->wight + 1];
	for (int i = 0; i < testObj.img->hight; i++) {
		MultiByteToWideChar(CP_ACP, 0, testObj.img->img[i], -1, wText, testObj.img->wight + 1);
		WriteConsoleOutputCharacter(hConsole, wText, testObj.img->wight, coord, &dwWritten);
		coord.Y++;
	}
}

void updateShow() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwWritten;
	COORD coord = { 0, 0};
	COORD coordT = {9, 9};
	char ch;
	for (int i = 0; i < bg.hight; i++) 
	{
		for (int j = 0; j < bg.wight; j++) 
		{
			if (updateMatrx[i][j] != -1) {
				coord.X = j;
				coord.Y = i;
				ch = char(updateMatrx[i][j]);
				updateMatrx[i][j] = -1;
				char newChar = ch;
				wchar_t wChar;
				MultiByteToWideChar(CP_ACP, 0, &newChar, 1, &wChar, 1);

				WriteConsoleOutputCharacter(hConsole, &wChar, 1, coord, &dwWritten);
			}
		}
	}
}

void clearMatrix(int xStart, int yStart, int wight, int hight) {
	for (int i = yStart; i < yStart + hight; i++)
		for (int j = xStart; j < xStart + wight; j++)
			updateMatrx[i][j] = bg.img[i][j];
}

void showObj(objForGraf* obj) {
	for (int i = obj->y; i < obj->y + obj->img->hight; i ++) {
		for (int j = obj->x; j < obj->x + obj->img->wight; j++)
			if(obj->img->img[i - obj->y][j - obj->x]!='`')
				updateMatrx[i][j] = int(obj->img->img[i - obj->y][j - obj->x]);
	}
}
unsigned int k = 0;
void sinMove() {
	k++;
		clearMatrix(testObj.x, testObj.y, testObj.img->wight, testObj.img->hight);
		testObj.x = bg.wight/2 + 1 - testObj.img->wight + sin(k*3.14/4000) * (bg.wight/2 - testObj.img->wight);
		showObj(&testObj);
		updateShow();
		if (k == 8000)
			k = 0;
}

