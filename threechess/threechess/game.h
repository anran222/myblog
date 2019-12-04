#ifndef __GAME_H__
#define __GAME_H__

#include<stdio.h>
#include<time.h>
#include<windows.h>
#pragma warning(disable:4996)

#define ROW 3
#define COL 3
#define INT ' '//�ÿո�����ʾʲô��û��
#define P_ICON 'X'//���������x����ʾ
#define C_ICON 'O'//������o����ʾ
void InitialTable(char table[][COL], int row, int col);
void ShowTable(char table[][COL], int row, int col);
char Judge(char table[][COL], int row, int col);
void Computer(char table[][COL], int row, int col);
int Guess();

void Game();
#endif 
