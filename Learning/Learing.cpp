#include <iostream>
#include"console.h"
#include<conio.h>
#include<string>
#include "Intro.h"
#include "PlayerScript.h"
#include <time.h>
using namespace std;

void MakeMap(char map[50][50])
{
	for ( int i = 0 ; i < 30 ; i++)
	{
		for ( int j = 0 ; j < 30 ; j++)
		{
			map[i][j] = ' ';
			if ( j == 15)
			{
				if ( i % 2 != 0)
				{
					map[i][j] = '|';
				}
				else
				{
					map[i][j] = ' ';
				}
			}
		}
	}
}
void MakeMap1(char map[50][50])
{
	for ( int i = 0 ; i < 30 ; i++)
	{
		for ( int j = 0 ; j < 30 ; j++)
		{
			map[i][j] = ' ';
			if ( j == 15)
			{
				if ( i % 2 != 0)
				{
					map[i][j] = ' ';
				}
				else
				{
					map[i][j] = '|';
				}
			}
		}
	}
}
void DrawMap(char map[50][50])
{
	for ( int i = 0 ; i < 30 ; i++)
	{
		TextColor(0);
		cout<<"\t\t\t";
		for ( int j = 0 ; j < 30 ; j++)
		{
			if ( j == 0 || j == 29)
			{
				TextColor(191);
			}
			else
			{
				TextColor(7);
			}
			if (map[i][j] == '<'||map[i][j] == '>'
				||map[i][j] == 'O'||map[i][j] == 'I')
			{
				TextColor(14);
			}

			cout<<map[i][j];
		}
		cout<<endl;
	}
}

int main()
{
	int static x = 15;
	int static y = 15;
	int static x1 = 15;
	int static y1 = 10;
	int draw = 0;
	int EnemyLife = 0;
	bool drawmap = false;
	int a = 0;
	char map[50][50];
	resizeConsole(800,414);
	Intro();
	cout<<"Press Any Key To Play";
	getch();
	while(1)
	{
		gotoXY(0,0);
		if(drawmap)
		{
			MakeMap(map);
		}
		else
		{
			MakeMap1(map);
		}
		DrawPlayer(x,y,map);
		/*random [a,b]
		srand(time(0));
		int x = a + rand() % ( b - a + 1 )
		*/
		DrawEnemy(x1,y1,map);
		MovePlayerT (x , y , map);
		//Detect collider
		DrawMap(map);
		if (map[y][x-1] != 'T' || map[y][x+1] != 'T' ||
			map[y+1][x+1] != '0'||
			map[y-1][x+1] != '0'||
			map[y+1][x-1] != '0'||
			map[y-1][x-1] != '0')
			{
				break;
			}

		draw++;
		EnemyLife++;
		if(draw>5)
		{
			drawmap = !drawmap;
			draw = 0;
		}
		if ( EnemyLife > 10)
		{
			MoveEnemy(x1 ,y1 ,map);
			EnemyLife = 0;
		}

	}
	Over(map);
	getch();
	return 0;
}