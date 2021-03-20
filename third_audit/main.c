#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "unique.h"
#define True 1
#define Menu "1. Game <Cities>\n2. Unique numbers\n0. Exit\n"
#define Line "------------------------------------------------------------\n"

int main() {
	int menu_item = 0;
	printf(Menu);
	while (True)
	{
		printf("<--");
		scanf("%d", &menu_item);
		switch (menu_item)
		{
		case 1:
			printf(Line);
			game_c();
			printf(Line);
      break;
		case 2:
			printf(Line);
			uniqueNumbers();
			printf(Line);
			break;
		case 0:
			exit(0);
		default:
			break;
		}
	}
	// game_c();
}
