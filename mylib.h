#ifndef MYLIB_H
#define MYLIB_H
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
#include <iostream>
#include <limits> // for std::numeric_limits

char* MatKhau();
char* Pwd();
int CheckPwd();
void gotoxy(short x,short y);
int wherex( void );
int wherey( void );
void clreol( );
void SetColor(WORD color);
void SetBGColor(WORD color);
void clrscr();
#endif // MYLIB_H
