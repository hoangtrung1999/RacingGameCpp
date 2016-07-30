#include <iostream>

void DrawPlayer(int x , int y , char map[50][50]);
void DrawEnemy (int x , int y , char map[50][50]);
void resizeConsole(int width, int height);
void MovePlayerT (int &x , int &y , char map[50][50]);
void MoveEnemy( int &x , int &y , char map[50][50]);