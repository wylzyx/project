#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<fstream>
#include"Book.h"
#define CMD_COLS 80
#define CMD_LINES 25
using namespace std;

void SetScreenGrid();
void SetSysCaption();
void ClearScreen();
void SetSysCaption(const char* pText);
void ShowWelcome();
void ShowRootMeun();
void WaitUser();
int GetSelect();
void GuideInput();
long GetFileLength(ifstream& ifs);
void DeleteBookFromFile();
void ViewData(int iSelPage);
void mainloop();
void WaitView(int iCurPage);