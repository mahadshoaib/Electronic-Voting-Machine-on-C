#ifndef _INC_INTRO
#define _INC_INTRO


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<fcntl.h>
#include<unistd.h>

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Intro(){
	const char *txt = " ELECTRO VM  ";
int x = 39;
int c = 22;
int i, j, k, l;
	for(j=0;j<x-1;j++){
		gotoxy(x-j,10);
		printf("%c",c);
		gotoxy(x+j,10);
		printf("%c",c);
		usleep(25000);
	}

	for(i = 0;i<9;i++){
		for(j=0;j<x-1;j++){
			gotoxy(x-j,9-i);
			printf("%c",c+2);
			gotoxy(x+j,9-i);
			printf("%c",c+2);
			gotoxy(x-j,9+i);
			printf("%c",c+3);
			gotoxy(x+j,9+i);
			printf("%c",c+3);
		}
		usleep(30000);
		for(k=0;k<x-1;k++){
			gotoxy(x-k,9-i);
			printf(" ");
			gotoxy(x+k,9-i);
			printf(" ");
			gotoxy(x-k,9+i);
			printf(" ");
			gotoxy(x+k,9+i);
			printf(" ");
			}	
		
	}		
		for(l=0;l<x;l++){
		gotoxy(x-l,1);
		printf("%c",c);
		gotoxy(x+l,1);
		printf("%c",c);
		gotoxy(x-l,17);
		printf("%c",c);
		gotoxy(x+l,17);
		printf("%c",c);
		}

for(j=0;j<9;j++){
		gotoxy(x,10-j);
		printf("%c",c);
		gotoxy(x,10+j-1);
		printf("%c",c);
		usleep(25000);
	}

for(i = 0;i<x-1;i++){
		for(j=0;j<8;j++){
			gotoxy(x-i,9-j);
			printf("%c",c+5);
			gotoxy(x+i,9-j);
			printf("%c",c+4);
			gotoxy(x-i,9+j);
			printf("%c",c+5);
			gotoxy(x+i,9+j);
			printf("%c",c+4);
		}
		usleep(25000);
		for(k=0;k<8;k++){
			gotoxy(x-i,9-k);
			printf(" ");
			gotoxy(39-i,8);
			printf("%c",txt[6-i]);
			gotoxy(x+i,9-k);
			printf(" ");
			gotoxy(x-i,9+k);
			printf(" ");
			if(i <8){
			gotoxy(39+i,8);
			printf("%c",txt[6+i]);}
			gotoxy(x+i,9+k);
			printf(" ");
			}	
		
	}		

	for(l=0;l<9;l++){
		gotoxy(1,9-l);
		printf("%c",c);
		gotoxy(77,9-l);
		printf("%c",c);
		gotoxy(1,9+l);
		printf("%c",c);
		gotoxy(77,9+l);
		printf("%c",c);
		}

gotoxy(0,19);
 printf("PRESS ANY KEY TO CONTINUE ...");
 getch();
}

#endif
