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

#define YELLOW		1		// 노란 색 컬러 번호
#define BLUE		2		// 파란 색 컬러 번호
#define GREEN		3		// 녹색 색 컬러 번호
#define MAGENTA		4		// 자홍 색 컬러 번호
#define RED			5		// 붉은 색 컬러 번호
#define CYAN		6		// 하늘 색 컬러 번호
#define WHITE		7		// 흰색 색 컬러 번호

#define VOID		99		// 녹색 = 필드 기본

// SYSTEM NUMBER

#define BLANK		0		// 빈칸			□ 
#define BOTTOM		10		// 경계			-
#define WALL		20		// 왼 벽			|

#define YELLOW_HOLD	11		// 고정된 블럭  ■ 노란 색 컬러 번호
#define BLUE_HOLD	12		// 고정된 블럭  ■ 파란 색 컬러 번호
#define GREEN_HOLD	13		// 고정된 블럭  ■ 녹색 색 컬러 번호
#define MAGEN_HOLD	14		// 고정된 블럭  ■ 자홍 색 컬러 번호
#define RED_HOLD	15		// 고정된 블럭  ■ 붉은 색 컬러 번호
#define CYAN_HOLD	16		// 고정된 블럭  ■ 하늘 색 컬러 번호
#define WHITE_HOLD	17		// 고정된 블럭  ■ 흰색 색 컬러 번호

#define HOLD		50		// 고정

#define YELLOW		1		// 노란 색 컬러 번호
#define BLUE		2		// 파란 색 컬러 번호
#define GREEN		3		// 녹색 색 컬러 번호
#define MAGENTA		4		// 자홍 색 컬러 번호
#define RED			5		// 붉은 색 컬러 번호
#define CYAN		6		// 하늘 색 컬러 번호
#define WHITE		7		// 흰색 색 컬러 번호

#define VOID		99		// 녹색 = 필드 기본

#define QUIT		113		// 일반 키 'q'
#define UP			259		// 특수 키 ↑
#define DOWN		258		// 특수 키 ↓
#define LEFT		260		// 특수 키 ←
#define RIGHT		261		// 특수 키 →
#define SPACE		32		// 특수 키 [SPACEBAR]
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

extern int		x, y;					// 필드 좌표
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