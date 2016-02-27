#include "Intris_Headers.h"
// UPLOAD!!!!!!

void settingMyPlayGround(WINDOW* thisWindow){
	//(thisWindow, 'I', 'I', '-', '-', '*', '*', '*', '*');
	for (int i = 1; i < 23; i = i++){
		for (int j = 1; j < 24; j = j + 2){
			if (i == 1 || i == 22 || j == 1 || j == 23)	// WALL
				//mvwprintw(thisWindow, i, j, "■");
				myMap[i][j] = WALL;
			else
				myMap[i][j] = BLANK;
		}
	}
	
	wrefresh(thisWindow);
}

void settingOtherPlayGround(WINDOW* thisWindow){
	//wborder(thisWindow, 'I', 'I', '-', '-', '*', '*', '*', '*');
	for (int i = 1; i < 23; i = i++){
		for (int j = 1; j < 24; j = j + 2){
			if (i == 0 || i == 23)
				mvwprintw(thisWindow, i, j, "□");
			else
				mvwprintw(thisWindow, i, j, "□");
		}
	}

	initField();
	refreshField(thisWindow, 5, 5, 5);

	wrefresh(thisWindow);
}

void settingMyTemp(WINDOW* thisWindow){
	mvwprintw(thisWindow, 3, 4, "다");
	mvwprintw(thisWindow, 5, 4, "음");
	mvwprintw(thisWindow, 7, 4, "블");
	mvwprintw(thisWindow, 9, 4, "럭");
	mvwprintw(thisWindow, 11, 4, "리");
	mvwprintw(thisWindow, 13, 4, "스");
	mvwprintw(thisWindow, 15, 4, "트");
	wrefresh(thisWindow);
}


void settingChat(WINDOW* thisWindow){
	mvwprintw(thisWindow, 3, 4, "채");
	mvwprintw(thisWindow, 5, 4, "");
	mvwprintw(thisWindow, 7, 4, "");
	mvwprintw(thisWindow, 9, 4, "팅");
	mvwprintw(thisWindow, 11, 4, "");
	mvwprintw(thisWindow, 13, 4, "");
	mvwprintw(thisWindow, 15, 4, "창");
	wrefresh(thisWindow);
}

void initializeGame(){
	upperStateWindow = makeWindow(7, 100, 2, 5);

	myPlayGround = makeWindow(PLAY_WIDTH_SIZE, PLAY_HEIGHT_SIZE, PG_LINE_X, 51);
	settingMyPlayGround(myPlayGround);
	myScoreWindow = makeWindow(4, 24 + 12 + 2 + 2, 34, 51);
	myTempBlock = makeWindow(PLAY_WIDTH_SIZE, 12, PG_LINE_X, 53 + PLAY_WIDTH_SIZE + 2);

	otherPlayGround = makeWindow(PLAY_WIDTH_SIZE, PLAY_HEIGHT_SIZE, PG_LINE_X, 5);
	settingOtherPlayGround(otherPlayGround);
	otherScoreWIndow = makeWindow(4, 24 + 12 + 2 + 2, 34, 5);
	otherTempBlock = makeWindow(PLAY_WIDTH_SIZE, 12, PG_LINE_X, 7 + PLAY_WIDTH_SIZE + 2);

	chatWindow = makeWindow(28, 30, PG_LINE_X, 95);
	
	settingMyTemp(myTempBlock);
	settingChat(chatWindow);
	
	//otherPlayGround = makeWindow(40, 20, 25, 50);

}
