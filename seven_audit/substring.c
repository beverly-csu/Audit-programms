#include <stdio.h>
#include <stdlib.h>
#include "substring.h"
#include "string_lib.h"

void uniqueString(char *string)
{
    int lenght = str_len(string);
    char **uniqueMass = (char**)malloc(lenght * sizeof(char));
    for (int i = 1; i < lenght + 1; i++)
    {
        if (string[i] != string[i - 1]) {
            uniqueMass[i - 1] = (char*)realloc(uniqueMass, i * sizeof(char));
        }
    }
}

void substring()
{
    char *string = {0};
    char symbol = {0};
    int elements = 0;
    printf("Enter the string: ");
    while (symbol != '\n')
    {
        symbol = getchar();
        if ((int)symbol == 127)
            break;
        if ((int)symbol >= 33 && (int)symbol <= 126)
        {
            elements++;
            string = (char *)realloc(string, elements * sizeof(char));
            string[elements - 1] = symbol;
        }
    }
    printf("Your string: ");
    for (int i = 0; i < elements; i++)
    {
        printf("%c", string[i]);
    }
    printf("\n");
}