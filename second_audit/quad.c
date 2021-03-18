#include <stdio.h>
#include <stdlib.h>
#include "quad.h"

void quad() {
	int number_int[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	char number_chr[] = "0123456789";
	unsigned char sym = { 0 };
	int* numbers = (int*)malloc(1000 * sizeof(int));
	int index = 0;
	while (sym != '!') {
		sym = getc(stdin);
		for (int i = 0; i < 10; i++)
		{
			if (sym == number_chr[i]) {
				if (numbers)
					numbers[index] = number_int[i];
				index++;
			}
		}
	}
	if (index > 0)
		for (int i = 0; i < index; i++)
		{
			if (numbers)
				printf("-->\t%d\n", numbers[i] * numbers[i]);
		}
	else
		printf("No one number!\n");
}