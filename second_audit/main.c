#include <stdio.h>
#include <stdlib.h>
#include "persons.h"
#include "quad.h"
#define True 1
#define Menu "1. Persons\n2. Quad's\n0. Exit\n"
#define Line "------------------------------------------------------------\n"

int main() {
	int menu_item = 0;
	printf(Menu);
	while (True)
	{
		printf("<--");
		scanf_s("%d", &menu_item);
		switch (menu_item)
		{
		case 1:
			printf(Line);
			persons();
			printf(Line);
			break;
		case 2:
			printf(Line);
			printf("! - to exit.\n");
			printf(Line);
			quad();
			printf(Line);
			break;
		case 0:
			exit(0);
		default:
			break;
		}
	}
}