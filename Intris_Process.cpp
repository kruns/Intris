#include "Intris_Headers.h"
// UPLOAD!!!!!!
int testBlock[5][5] = {
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0 },
	{ 0, 0, 1, 0, 0 },
	{ 0, 0 ,1 ,0 ,0 },
	{ 0, 0, 1, 0, 0 }
};

int		x = 1, y = 7;					// ÇÊµå ÁÂÇ¥

void usingBlock(){
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			if (testBlock[i][j] == 0){
				continue;
			}
			else{
				myMap[x + i][y + j * 2] = testBlock[i][j];
				//printf("EE");
			}
		}
	}
}

void gameProcess(WINDOW* thisWindow){

	int gameState = LIVE;
	int keyValue = NULL;
	keypad(thisWindow, true);
	while (gameState == LIVE){
		usingBlock();
		for (int i = 0; i < 21; i++)
			renewField(thisWindow, i);
		for (int i = 0; i < 5; i++){
			for (int j = 0; j < 5; j++){
				cout << testBlock[i][j];
			}
			cout << endl;
		}

		wrefresh(thisWindow);
		keyValue = wgetch(thisWindow);
		if (keyValue == QUIT) break;
		else{
			moveBlock(keyValue);
		}
	}


}