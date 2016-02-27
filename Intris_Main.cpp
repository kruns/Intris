#include "Intris_Headers.h"

WINDOW* myScoreWindow;
WINDOW* myPlayGround;
WINDOW* myTempBlock;

WINDOW* otherScoreWIndow;
WINDOW* otherPlayGround;
WINDOW* otherTempBlock;

WINDOW* skillSetWindow;
WINDOW* upperStateWindow;
WINDOW* chatWindow;
WINDOW* etcWindow;

WINDOW* mainTitle;

 
 int		blockState = 0;
 int		A, B, C, D, E, F, G, H;
 int		blockNumber;

#define	MAP_SIZE					23

 int		myMap[MAP_SIZE][MAP_SIZE + 1] = { BLANK };
 int		otherMap[MAP_SIZE][MAP_SIZE + 1] = { BLANK };


WINDOW* makeWindow(int width, int height, int startx, int starty){
	WINDOW *createWindow = newwin(width, height, startx, starty);
	//box(createWindow, 5, 0);
	//wborder(createWindow, 'L', 'R', 'U', 'B', '1', '2', '3', '4');
	wborder(createWindow, '|', '|', '-', '-', '*', '*', '*', '*');
	wrefresh(createWindow);
	return createWindow;
}

void deleteWindow(WINDOW* delWin){
	wborder(delWin, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(delWin);
	delwin(delWin);
	
}


void main(){
	
	initscr();
	// √ ±‚»≠
	initSystem();

	titleWindow(mainTitle);

	clear();
	refresh();


	initializeGame();

	printf("%d", myPlayGround);
	printf("%d", skillSetWindow);
	gameProcess(myPlayGround);
	fgetchar();
	endwin();
}