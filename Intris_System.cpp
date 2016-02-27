#include "Intris_Headers.h"

/*
class Block{
public:
	Block() {}

	void phaseShift()
	{
		if (blockNumber == YELLOW)
		{
			if (blockState == 1) blockState = 0;
			if (blockState == 0){ A = 0; E = 0; B = 2; F = 0; C = 0; G = 1; D = 2; H = 1; }
		}
		if (blockNumber == BLUE)
		{
			if (blockState == 4) blockState = 0;
			if (blockState == 0){ A = 2; E = 0; B = 2; F = 1; C = 2; G = 2; D = 4; H = 2; }
			if (blockState == 1){ A = 4; E = 0; B = 0; F = 1; C = 2; G = 1; D = 4; H = 1; }
			if (blockState == 2){ A = 0; E = 0; B = 2; F = 0; C = 2; G = 1; D = 2; H = 2; }
			if (blockState == 3){ A = 0; E = 1; B = 2; F = 1; C = 4; G = 1; D = 0; H = 2; }
		}
		if (blockNumber == GREEN)
		{
			if (blockState == 4) blockState = 0;
			if (blockState == 0){ A = 2; E = 0; B = 2; F = 1; C = 2; G = 2; D = 0; H = 2; }
			if (blockState == 1){ A = 0; E = 1; B = 2; F = 1; C = 4; G = 1; D = 4; H = 2; }
			if (blockState == 2){ A = 4; E = 0; B = 2; F = 0; C = 2; G = 1; D = 2; H = 2; }
			if (blockState == 3){ A = 0; E = 1; B = 2; F = 1; C = 4; G = 1; D = 0; H = 0; }
		}
		if (blockNumber == MAGENTA)
		{
			if (blockState == 2) blockState = 0;
			if (blockState == 0){ A = 2; E = 0; B = 2; F = 1; C = 4; G = 1; D = 4; H = 2; }
			if (blockState == 1){ A = 2; E = 0; B = 4; F = 0; C = 0; G = 1; D = 2; H = 1; }
		}
		if (blockNumber == RED)
		{
			if (blockState == 2) blockState = 0;
			if (blockState == 0){ A = 2; E = 0; B = 0; F = 1; C = 2; G = 1; D = 0; H = 2; }
			if (blockState == 1){ A = 0; E = 0; B = 2; F = 0; C = 2; G = 1; D = 4; H = 1; }
		}
		if (blockNumber == CYAN)
		{
			if (blockState == 4) blockState = 0;
			if (blockState == 0){ A = 2; E = 0; B = 0; F = 1; C = 2; G = 1; D = 4; H = 1; }
			if (blockState == 1){ A = 2; E = 0; B = 0; F = 1; C = 2; G = 1; D = 2; H = 2; }
			if (blockState == 2){ A = 0; E = 1; B = 2; F = 1; C = 4; G = 1; D = 2; H = 2; }
			if (blockState == 3){ A = 2; E = 0; B = 2; F = 1; C = 4; G = 1; D = 2; H = 2; }
		}
		if (blockNumber == WHITE)
		{
			if (blockState == 2) blockState = 0;
			if (blockState == 0){ A = 2; E = 0; B = 2; F = 1; C = 2; G = 2; D = 2; H = 3; }
			if (blockState == 1){ A = 0; E = 1; B = 2; F = 1; C = 4; G = 1; D = 6; H = 1; }
		}
	}

};
*/

class Block{
private:
	int maxState;
	int blockForm[4][4];

public:
	


};

void colorSet()		// 컬러 셋
{
	start_color();
	init_pair(VOID, COLOR_GREEN, COLOR_BLACK);
	init_pair(RED, COLOR_RED, COLOR_BLACK);
	init_pair(YELLOW, COLOR_YELLOW, COLOR_BLACK);
	init_pair(BLUE, COLOR_BLUE, COLOR_BLACK);
	init_pair(MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(BLUE, COLOR_BLUE, COLOR_BLACK);
	init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
	init_pair(WHITE, COLOR_WHITE, COLOR_BLACK);
	init_pair(CYAN, COLOR_CYAN, COLOR_BLACK);
	init_pair(WALL, COLOR_WHITE, COLOR_GREEN);	
}

void initSystem(){
	resize_term(WINDOW_WIDTH_SIZE, WINDOW_HEIGHT_SIZE);
	// 창 크기
	colorSet();
	// 색 설정
}

void refreshField(WINDOW* thisWindow, int colorNumber, int x, int y){
	wattron(thisWindow, COLOR_PAIR(colorNumber));
	if (colorNumber == VOID) mvwprintw(thisWindow, x, y, "□");
	else mvwprintw(thisWindow, x, y, "■");
	wattroff(thisWindow, COLOR_PAIR(colorNumber));
	//printf("x : %d y : %d ", x , y);
	//wrefresh(thisWindow);
}

void renewField(WINDOW *thisWindow, int colorNumber)	// 필드 갱신
{
	for (int a = 1; a < 23; a++)
		for (int b = 1; b < 24; b = b + 2){
			if (myMap[a][b] == BLANK)
				refreshField(thisWindow, VOID, a, b);
			else if (myMap[a][b] == colorNumber + BOTTOM || myMap[a][b] == colorNumber)
				refreshField(thisWindow, colorNumber, a, b);
		}
	//	printf("sdsd");
	wrefresh(thisWindow);
}


void initField()				// 이동 잔상 제거
{
	for (int b = 1; b < 19; b++)
	for (int a = 1; a <= 19; a = a + 2)
	if (myMap[a][b] < BOTTOM) myMap[a][b] = BLANK;
}

void moveBlock(int keyValue){
	int temp = blockState;
	printf("%d",keyValue);
	switch (keyValue){
	case KEY_UP: spinBlock(testBlock, 4);
		printf("STST");
		break;
	case KEY_LEFT:
		break;
	case KEY_RIGHT:
		break;
	case KEY_DOWN:
		break;
	case SPACE:
		break;
	default:
		break;
	}
	
	
}

void spinBlock(int(*arr)[5], int len){
	int i, j, k, temp, l_point;
	for (i = 0, j = 0, k = 0, l_point = len; k<2; i++, j++, k++, l_point--)
	{
		for (; i<l_point; i++)
		{
			temp = arr[j][i];
			arr[j][i] = arr[len - i][j];
			arr[len - i][j] = arr[len - j][len - i];
			arr[len - j][len - i] = arr[i][len - j];
			arr[i][len - j] = temp;
		}
		i = 0;
	}

	
}

