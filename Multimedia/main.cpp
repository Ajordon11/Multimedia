#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <conio.h>
#include <stdio.h>
#pragma comment( lib, "winmm" )

int main()
{
	char ch = 'a';
	int vyber, error,error2 = 0;
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pPlay = { 5,5 };COORD pPause = { 20,5 };COORD pResume = { 35,5 };COORD pStop = { 50,5 };COORD pEnd = { 65,5 };COORD pTime = { 10,10 };COORD pInfo = { 5,2 };
	printf("Chcete otvorit video (mys) alebo pesnicku (kolokolo)?\n");
	printf("Zadaj 1 pre mys, 2 pre kolokolo :");
	scanf("%d", &vyber);
	if (vyber == 1)
		error = mciSendString("open mys3.mpg alias file1", NULL, 0, NULL);
	else if (vyber == 2)
		error = mciSendString("open kolokolo.mp3 alias file1", NULL, 0, NULL);

	while (1) {
		SetConsoleCursorPosition(hConsole, pInfo);
		printf("Stlac prislusne cislo.");
		SetConsoleCursorPosition(hConsole, pPlay);
		printf("1 - Play %s", (ch == '1' )? "*" : " ");
		SetConsoleCursorPosition(hConsole, pPause);
		printf("2 - Pause %s", (ch == '2') ? "*" : " ");
		SetConsoleCursorPosition(hConsole, pResume);
		printf("3 - Resume %s", (ch == '3') ? "*" : " ");
		SetConsoleCursorPosition(hConsole, pStop);
		printf("4 - Stop %s", (ch == '4') ? "*" : " ");
		SetConsoleCursorPosition(hConsole, pEnd);
		printf("0 - END %s", (ch == '0') ? "*" : " ");
		SetConsoleCursorPosition(hConsole, pTime);
		printf("Cas: %d",error2);
		if (_kbhit()) {
			ch = _getch();
			if (ch == '0')
				break;
		}
		switch (ch) {
		case '1':error = mciSendString("play file1 from 0", NULL, 0, NULL);
			error2 = mciSendString("status file1 position", NULL, 0, NULL);
			ch = '5';
			break;
		case '2':error = mciSendString("pause file1", NULL, 0, NULL);
			break;
		case '3':error = mciSendString("resume file1", NULL, 0, NULL);
			break;
		case '4':error = mciSendString("stop file1", NULL, 0, NULL);
			break;
		}
	
		Sleep(10);
	}
	error = mciSendString("close file1", NULL, 0, NULL);
	return 0;
}

//printf(" S:%s", ch = '?"*":" ");
//SetConsoleCursorPosition(hConsole, point);
/*
open mys.mpg alias file1
play file1
pause file1
play file1
close file 1
status waveaudio position
				length
mciSendString("close CDAudio", NULL, 0, NULL);
if (_kbhit()) {
znak_vstup = _getch();
if (znak_vstup == znak)
break;
*/
