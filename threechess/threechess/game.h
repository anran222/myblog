#ifndef __GAME_H__
#define __GAME_H__

#include<stdio.h>
#include<time.h>
#include<windows.h>
#pragma warning(disable:4996)

#define ROW 3
#define COL 3
#define INT ' '//用空格来表示什么都没有
#define P_ICON 'X'//玩家我们用x来表示
#define C_ICON 'O'//电脑用o来表示
void InitialTable(char table[][COL], int row, int col);
void ShowTable(char table[][COL], int row, int col);
char Judge(char table[][COL], int row, int col);
void Computer(char table[][COL], int row, int col);
int Guess();

void Game();
#endif 
