#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "getUsers.h"
#include "string_lib.h"

char *strParser(char *string, char endChar)
{
    int len = str_len(string);
    char *real_user = "/bin/bash";
    int real_exist = 1;
    char *tempStr = (char *)malloc(sizeof(char));

    for (int i = 0; i < 9; i++)
    {
        //printf("%c", string[i + (len - 9)]);
        if (string[i + (len - 9)] != real_user[i]){
            real_exist = 0;
            break;
        }
    }

    for (int i = 0; i < len + 1; i++)
    {
        if (string[i] != endChar)
        {
            tempStr = (char *)realloc(tempStr, (i + 3) * sizeof(char));
            tempStr[i] = string[i];
        }
        else if (string[i] == endChar)
        {
            tempStr[i] = '\0';
            break;
        }
    }
    string = 0;
    if (real_exist == 1)
        return tempStr;
    else
        return "NonReal";
}

int stringsCount(char *filename)
{
    FILE *file;
    file = fopen(filename, "r");
    char sym = {0};
    int count = 0;
    while (1)
    {
        sym = fgetc(file);
        if (sym == '\n')
            count++;
        if (sym == EOF)
            break;
    }
    fclose(file);
    return count + 1;
}

void delSpaces(char *filename)
{
    FILE *file, *newfile;
    file = fopen(filename, "r");
    system("touch newfile.txt");
    newfile = fopen("newfile.txt", "w");
    char sym = 0;
    while (1)
    {
        sym = fgetc(file);
        if (sym == ' ')
        {
            fputc('_', newfile);
        }
        else
        {
            fputc(sym, newfile);
        }
        if (sym == EOF) {
            break;
        }
    }
    fclose(file);
    fclose(newfile);
}

void getUserInfo()
{
    FILE *passwd;
    char temp[255] = {0};
    delSpaces("/etc/passwd");
    passwd = fopen("newfile.txt", "r");
    *temp = 0;
    int counter = 0;
    int count = stringsCount("/etc/passwd");
    for (int i = 0; i < count - 1; i++)
    {
        fscanf(passwd, "%s", temp);
        if (strParser(temp, ':') != "NonReal")
        {
            printf("%s\n", strParser(temp, ':'));
            counter++;
        }
    }
    printf("Programm found only %d local users\n", counter);
    fclose(passwd);
    system("rm newfile.txt");
}