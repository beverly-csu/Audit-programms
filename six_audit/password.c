#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include "password.h"

#define ENG "(symbol >= 33 && symbol <= 126)"
#define RUS "|| (symbol >= 128 && symbol <= 175) || (symbol >= 224 && symbol <= 243)"

int checkPassword(char *password, int index)
{
    // lenght | digits | big letters | symbols | complex
    int factors[5] = {0, 0, 0, 0, 0};
    int sumup = 0;

    if (index <= 8)
    {
        return 0;
    }
    else
    {
        factors[0] = 1;
        for (int i = 0; i < index; i++)
        {
            if ((int)password[i] >= 91 && (int)password[i] <= 96 && factors[3] == 0)
            {
                factors[3] = 1;
            }
            else if ((int)password[i] >= 33 && (int)password[i] <= 47 && factors[3] == 0)
            {
                factors[3] = 1;
            }
            else if ((int)password[i] >= 58 && (int)password[i] <= 64 && factors[3] == 0)
            {
                factors[3] = 1;
            }
            else if ((int)password[i] >= 123 && (int)password[i] <= 126 && factors[3] == 0)
            {
                factors[3] = 1;
            }
            else if ((int)password[i] >= 48 && (int)password[i] <= 57 && factors[1] == 0)
            {
                factors[1] = 1;
            }
            else if ((int)password[i] >= 65 && (int)password[i] <= 90 && factors[2] == 0)
            {
                factors[2] = 1;
            }
        }
    }
    if (factors[1] > 0 && factors[2] > 0)
        factors[4] = 1;
    for (int i = 0; i < 5; i++)
    {
        sumup += factors[i];
    }
    return sumup;
}

void factor_print(int factor)
{
    if (factor == 0)
    {
        printf("\033[s\033[56GTo low\033[u");
    }
    if (factor == 1)
    {
        printf("\033[s\033[56G\033[91m*\033[37m\033[u");
    }
    if (factor == 2)
    {
        printf("\033[s\033[56G\033[91m*\033[93m*\033[37m\033[u");
    }
    if (factor == 3)
    {
        printf("\033[s\033[56G\033[91m*\033[93m**\033[37m\033[u");
    }
    if (factor == 4)
    {
        printf("\033[s\033[56G\033[91m*\033[93m***\033[37m\033[u");
    }
    if (factor == 5)
    {
        printf("\033[s\033[56G\033[91m*\033[93m***\033[92m*\033[37m\033[u");
    }
    if (factor == 6)
    {
        printf("\033[s\033[56G\033[91mTo low\033[37m\033[u");
    }
}

void password()
{
    static struct termios oldTermios, newTermios;
    tcgetattr(STDIN_FILENO, &oldTermios);
    newTermios = oldTermios;
    cfmakeraw(&newTermios);

    char password[32] = {0};
    char symbol = 0;
    int index = 0;
    int factor = 0;

    printf("Enter password: ");
    tcsetattr(STDIN_FILENO, TCSANOW, &newTermios);
    while (index < 32)
    {
        symbol = getchar();
        factor = checkPassword(password, index + 1);
        if (symbol == 13)
        {
            if (factor > 0)
            {
                break;
            }
            if (factor == 0)
            {
                factor_print(6);
            }
        }
        else if (symbol == 127 && index > 0)
        {
            index--;
            password[index] = 0;
            printf("\b \b");
            printf("\033[K");
            factor_print(factor);
        }
        else if (ENG)
        {
            if ((int)symbol != 127)
            {
                password[index] = symbol;
                putchar('*');
                index++;
                factor = checkPassword(password, index + 1);
                printf("\033[K");
                factor_print(factor);
            }
        }
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &oldTermios);
    printf("\nYour password: %s\n", password);
}