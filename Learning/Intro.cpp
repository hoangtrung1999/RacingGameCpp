#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include "Intro.h"
#include "console.h"
using namespace std;
void Intro()
{
	char c;
	ifstream file;
	file.open("Intro.txt",ios::in);
	while(!file.eof())
	{
		file.get(c);
		TextColor(7);
		cout<<c;
		Sleep(10);
		if (kbhit())
		{
			break;
		}
	}
	cout<<"\n";
	file.close();
}
void Over(char map[50][50])
{
	char ch;
	ifstream file2;
	file2.open("Over.txt",ios::in);
	while(!file2.eof())
	{
		file2.get(ch);
		TextColor(7);
		cout<<ch;
		Sleep(10);
		if (kbhit())
		{
			break;
		}
	}
	cout<<"\n";
	file2.close();
}