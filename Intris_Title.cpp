#include "Intris_Headers.h"

#define	MENU1		20
#define	MENU2		25
#define	MENU3		30
#define MOVE_MENU	5

void titleWindow(WINDOW* thisWindow){

	int selectMenu = MENU1;
	int inputKey = 0;

	thisWindow = makeWindow(36, 126, 2, 2);
	wborder(thisWindow, 'I', 'I', '-', '-', '*', '*', '*', '*');

	wattron(thisWindow, COLOR_PAIR(MAGENTA));
	mvwprintw(thisWindow, 7, 10, "¡á¡á¡á¡¡¡á¡á¡á¡¡¡á¡á¡á¡¡¡á¡á¡á¡¡¡á¡á¡á¡¡¡á¡á¡á");
	mvwprintw(thisWindow, 8, 10, "¡¡¡á¡¡¡¡¡á¡¡¡¡¡¡¡¡¡á¡¡¡¡¡á¡¡¡á¡¡¡¡¡á¡¡¡¡¡á¡¡¡¡");
	mvwprintw(thisWindow, 9, 10, "¡¡¡á¡¡¡¡¡á¡á¡á¡¡¡¡¡á¡¡¡¡¡á¡á¡¡¡¡¡¡¡á¡¡¡¡¡á¡á¡á");
	mvwprintw(thisWindow, 10, 10, "¡¡¡á¡¡¡¡¡á¡¡¡¡¡¡¡¡¡á¡¡¡¡¡á¡¡¡á¡¡¡¡¡á¡¡¡¡¡¡¡¡¡á");
	mvwprintw(thisWindow, 11, 10, "¡¡¡á¡¡¡¡¡á¡á¡á¡¡¡¡¡á¡¡¡¡¡á¡¡¡á¡¡¡á¡á¡á¡¡¡á¡á¡á");
	wattroff(thisWindow, COLOR_PAIR(MAGENTA));


	mvwprintw(thisWindow, MENU1, 90, "Start game");

	mvwprintw(thisWindow, MENU2, 90, "Multiplay Game");

	mvwprintw(thisWindow, MENU3, 90, "Exit game");

	
	keypad(thisWindow, true);
	noecho();
	curs_set(0);
	while (inputKey != ENTER){
		mvwprintw(thisWindow, selectMenu, 86, "  ");
		switch (inputKey){
		case KEY_DOWN: if (selectMenu == MENU3){
					   selectMenu = MENU1;
		}
				   else{
					   selectMenu += MOVE_MENU;
				   }
				   break;
		case KEY_UP: if (selectMenu == MENU1){
					 selectMenu = MENU3;
		}
				 else{
					 selectMenu -= MOVE_MENU;
				 }
				 //printf("HEEEEE");
				 break;
		case KEY_ENTER:
			selectMenu = ENTER;
			break;

		}
		wattron(thisWindow, COLOR_PAIR(CYAN));
		mvwprintw(thisWindow, selectMenu, 86, "¢Ñ");
		//printf("%d", selectMenu);
		wattroff(thisWindow, COLOR_PAIR(CYAN));
		
		wrefresh(thisWindow);
		inputKey = wgetch(thisWindow);
	}
	keypad(thisWindow, false);
	deleteWindow(mainTitle);
	// END TITLE
}

