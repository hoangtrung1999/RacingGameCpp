#include "PlayerScript.h"
#include <iostream>
#include <Windows.h>
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void DrawPlayer (int x , int y , char map[50][50])
{
	map[y][x] = 'X';
	map[y][x-1] = 'T';
	map[y][x+1] = 'T';
	map[y+1][x+1] = '0';
	map[y-1][x+1] = '0';
	map[y+1][x-1] = '0';
	map[y-1][x-1] = '0';
}
void ClearBuffer(int &x , int &y , char map[50][50])
{
	map[y][x] = ' ';
	map[y][x-1] = ' ';
	map[y][x+1] = ' ';
	map[y+1][x+1] = ' ';
	map[y-1][x+1] = ' ';
	map[y+1][x-1] = ' ';
	map[y-1][x-1] = ' ';
}
void MovePlayerT (int &x , int &y , char map[50][50])
{
	if ( GetAsyncKeyState(VK_LEFT)&&x!=2)
	{
		ClearBuffer(x,y,map);
		x--;
		map[y][x] = 'X';
		map[y][x-1] = 'T';
		map[y][x+1] = 'T';
		map[y+1][x+1] = '0';
		map[y-1][x+1] = '0';
		map[y+1][x-1] = '0';
		map[y-1][x-1] = '0';
		DrawPlayer(x,y,map);
	}
	else if ( GetAsyncKeyState(VK_RIGHT)&&x!=27)
	{
		ClearBuffer(x,y,map);
		x++;
		map[y][x] = 'X';
		map[y][x-1] = 'T';
		map[y][x+1] = 'T';
		map[y+1][x+1] = '0';
		map[y-1][x+1] = '0';
		map[y+1][x-1] = '0';
		map[y-1][x-1] = '0';
		DrawPlayer(x,y,map);
	}
	else if ( GetAsyncKeyState(VK_UP)&&y!=1)
	{
		ClearBuffer(x,y,map);
		y--;
		map[y][x] = 'X';
		map[y][x-1] = 'T';
		map[y][x+1] = 'T';
		map[y+1][x+1] = '0';
		map[y-1][x+1] = '0';
		map[y+1][x-1] = '0';
		map[y-1][x-1] = '0';
		DrawPlayer(x,y,map);
	}
		else if ( GetAsyncKeyState(VK_DOWN)&&y!=28)
	{
		ClearBuffer(x,y,map);
		y++;
		map[y][x] = 'X';
		map[y][x-1] = 'T';
		map[y][x+1] = 'T';
		map[y+1][x+1] = '0';
		map[y-1][x+1] = '0';
		map[y+1][x-1] = '0';
		map[y-1][x-1] = '0';
		DrawPlayer(x,y,map);
	}
}
void DrawEnemy (int x , int y , char map[50][50])
{
	map[y][x] = 'O';
	map[y][x-1] = 'I';
	map[y][x+1] = 'I';
	map[y+1][x+1] = '>';
	map[y-1][x+1] = '>';
	map[y+1][x-1] = '<';
	map[y-1][x-1] = '<';
}
void MoveEnemy( int &x , int &y , char map[50][50])
{
	ClearBuffer(x,y,map);
	y++;
	map[y][x] = 'O';
	map[y][x-1] = 'I';
	map[y][x+1] = 'I';
	map[y+1][x+1] = '>';
	map[y-1][x+1] = '>';
	map[y+1][x-1] = '<';
	map[y-1][x-1] = '<';
	if (y == 26)
	{
		y = 2;
	}
	DrawEnemy(x,y,map);
}
