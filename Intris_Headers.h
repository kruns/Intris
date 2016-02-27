//#pragma once
// UPLOAD!!!!!!
#ifndef __INTRIS_HEADER_FILES__
#define __INTRIS_HEADER_FILES__

//HEADERS

#include <curses.h>
#include <fstream>
#include <cstring>
#include <iostream>

using namespace std;

// DEFINES

#define PAUSE system("pause")


#define	WINDOW_WIDTH_SIZE			40
#define	WINDOW_HEIGHT_SIZE			130

#define PLAY_WIDTH_SIZE				24
#define PLAY_HEIGHT_SIZE			26

#define	MY_UI_START_X				55
#define OTHER_UI_START_X			7

#define PG_LINE_X					10
#define PG_LINE_WIDTH				12


// COLORS

#define YELLOW		1		// ��� �� �÷� ��ȣ
#define BLUE		2		// �Ķ� �� �÷� ��ȣ
#define GREEN		3		// ��� �� �÷� ��ȣ
#define MAGENTA		4		// ��ȫ �� �÷� ��ȣ
#define RED			5		// ���� �� �÷� ��ȣ
#define CYAN		6		// �ϴ� �� �÷� ��ȣ
#define WHITE		7		// ��� �� �÷� ��ȣ

#define VOID		99		// ��� = �ʵ� �⺻

// SYSTEM NUMBER

#define BLANK		0		// ��ĭ			�� 
#define BOTTOM		10		// ���			-
#define WALL		20		// �� ��			|

#define YELLOW_HOLD	11		// ������ ��  �� ��� �� �÷� ��ȣ
#define BLUE_HOLD	12		// ������ ��  �� �Ķ� �� �÷� ��ȣ
#define GREEN_HOLD	13		// ������ ��  �� ��� �� �÷� ��ȣ
#define MAGEN_HOLD	14		// ������ ��  �� ��ȫ �� �÷� ��ȣ
#define RED_HOLD	15		// ������ ��  �� ���� �� �÷� ��ȣ
#define CYAN_HOLD	16		// ������ ��  �� �ϴ� �� �÷� ��ȣ
#define WHITE_HOLD	17		// ������ ��  �� ��� �� �÷� ��ȣ

#define HOLD		50		// ����

#define YELLOW		1		// ��� �� �÷� ��ȣ
#define BLUE		2		// �Ķ� �� �÷� ��ȣ
#define GREEN		3		// ��� �� �÷� ��ȣ
#define MAGENTA		4		// ��ȫ �� �÷� ��ȣ
#define RED			5		// ���� �� �÷� ��ȣ
#define CYAN		6		// �ϴ� �� �÷� ��ȣ
#define WHITE		7		// ��� �� �÷� ��ȣ

#define VOID		99		// ��� = �ʵ� �⺻

#define QUIT		113		// �Ϲ� Ű 'q'
#define UP			259		// Ư�� Ű ��
#define DOWN		258		// Ư�� Ű ��
#define LEFT		260		// Ư�� Ű ��
#define RIGHT		261		// Ư�� Ű ��
#define SPACE		32		// Ư�� Ű [SPACEBAR]
#define	ESC			27		// ESC
#define ENTER		10		// ENTER KEY

#define LIVE		1
#define OVER		2


// WINDOWS
	
extern WINDOW* myScoreWindow;
extern WINDOW* myPlayGround;
extern WINDOW* myTempBlock;

extern WINDOW* otherScoreWIndow;
extern WINDOW* otherPlayGround;
extern WINDOW* otherTempBlock;

extern WINDOW* skillSetWindow;
extern WINDOW* upperStateWindow;
extern WINDOW* chatWindow;
extern WINDOW* etcWindow;

extern WINDOW* mainTitle;

extern int		x, y;					// �ʵ� ��ǥ
extern int		blockState;
extern int		A, B, C, D, E, F, G, H;
extern int		blockNumber;

#define	MAP_SIZE					23

extern int		myMap[MAP_SIZE][MAP_SIZE + 1];
extern int		otherMap[MAP_SIZE][MAP_SIZE + 1];

extern int		testBlock[5][5];

// INIT FUNCTIONS

WINDOW* makeWindow(int width, int height, int startx, int starty);
void initializeGame();
void deleteWindow(WINDOW* delWindow);

// MAIN TITLE

void titleWindow(WINDOW* thisWindow);

// SYSTEM FUNCTION, VARIABLES



void colorSet();
void initSystem();
void refreshField(WINDOW* thisWindow, int colorNumber, int x, int y);
void initField();
void renewField(WINDOW *thisWindow, int colorNumber);

void setBlock();
void gameProcess(WINDOW *thisWindow);

void spinBlock(int(*arr)[5], int len);

void moveBlock(int keyValue);
#endif