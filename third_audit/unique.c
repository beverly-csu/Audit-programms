#include <stdio.h>
#include <stdlib.h>

#define RFACTOR 1.24733

int* combSorter(int* numbers, int count) {
	int gap = count;
	int swaps = 1;
	int i, j;

	while (gap > 1 || swaps) {
		gap = (int)(gap / RFACTOR);
		if (gap < 1)
			gap = 1;
		swaps = 0;
		for (i = 0; i < count - gap; ++i) {
			j = i + gap;
			if (numbers[i] > numbers[j]) {
				int temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
				swaps = 1;
			}
		}
	}
	return numbers;
}

int* deleteDuplicate(int* numbers, int index) {
	numbers[index] = '\0';
	return numbers;
}

int* findDuplicate(int* numbers, int count, int number, int index) {
	for (int i = 0; i < count; i++)
	{
		if (i != index)
			if (numbers[i] == number)
				numbers = deleteDuplicate(numbers, i);
	}
	return numbers;
}

void uniqueNumbers() {
	int count = 0;
	int* numbers = { 0 };
	printf("\x1B[36mEnter size: \033[0m");
	scanf("%d", &count);
	numbers = (int*)malloc(count * sizeof(int));
	printf("\x1B[36mEnter %d values: \033[0m\n", count);
	for (int i = 0; i < count; i++)
		scanf("%d", &numbers[i]);
	for (int i = 0; i < count; i++)
	{
		findDuplicate(numbers, count, numbers[i], i);
	}
	printf("\x1B[36mUnique mass: \033[0m");
	numbers = combSorter(numbers, count);
	int lenght = 0;
	for (int i = 0; i < count; i++)
	{
		if (numbers[i] != '\0') {
			printf("%d ", numbers[i]);
			lenght++;
		}
	}
	printf("\nLenght of unique mass: %d\n", lenght);
}
