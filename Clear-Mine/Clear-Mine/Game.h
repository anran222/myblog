#ifndef GAME_H__
#define GAME_H__


#include<stdio.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#pragma warning(disable:4996)

#define ROW 12
#define COL 12
#define NUMBER 30

void SetMine(mine, row,col);
void ShowTable(show,row,col);
int CountMine(mine, x, y);
int CountMine(mine, x, y);

#endif


