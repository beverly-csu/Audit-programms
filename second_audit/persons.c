#include <stdio.h>
#include <stdlib.h>
#include "persons.h"

typedef struct person
{
	int age;
	char* name;
	char* surname;
} person_struct;

void persons() {
	FILE* persons_data;
	person_struct* persons;
	char filename[] = "person.txt";
	int count = 0;

	int age = 0;
	char name[255], surname[255];

	fopen_s(&persons_data, filename, "r");

	if (persons_data)
		fscanf_s(persons_data, "%d", &count);

	persons = (person_struct*)malloc(count * sizeof(person_struct));

	if (persons) {
		for (int i = 0; i < count; i++)
		{
			fscanf_s(persons_data, "%d", &age);
			fscanf_s(persons_data, "%s", &name, 255);
			fscanf_s(persons_data, "%s", &surname, 255);

			persons[i].age = age;
			persons[i].name = (char*)malloc(255);
			persons[i].surname = (char*)malloc(255);
			for (int x = 0; x < 255; x++)
			{
				persons[i].name[x] = name[x];
				persons[i].surname[x] = surname[x];
			}
		}
	}

	for (int i = 0; i < count; i++)
	{
		printf("%s %s. Age: %d years.\n", persons[i].name, persons[i].surname, persons[i].age);
	}
	int maxAge = 0;
	int maxIndex = 0;
	for (int i = 0; i < count; i++)
	{
		if (persons[i].age > maxAge)
		{
			maxAge = persons[i].age;
			maxIndex = i;
		}
	}
	if (persons)
		printf("Person who elder then others: %s %s. Age: %d years.\n", persons[maxIndex].name, persons[maxIndex].surname, persons[maxIndex].age);
}
