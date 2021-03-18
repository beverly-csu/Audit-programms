#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "colors.h"

void displayStar(int centerX, int centerY, int color)
{
    printf("\033[%dm\033[%d;%dH*\033[0m", color, centerY, centerX);
    printf("\033[%dm\033[%d;%dH*\033[0m", color, centerY - 1, centerX);
    printf("\033[%dm\033[%d;%dH*\033[0m", color, centerY + 1, centerX);
    printf("\033[%dm\033[%d;%dH*\033[0m", color, centerY, centerX - 1);
    printf("\033[%dm\033[%d;%dH*\033[0m", color, centerY, centerX + 1);
}

int main()
{
    srand(time(NULL));
    int star_data[5][3] = {{5, 5, GREEN}, {9, 4, YELLOW}, {25, 8, RED}, {50, 7, MAGENTA}, {62, 4, CYAN}};
    int chance = 0;
    printf("\033[2J\033?25l");
    while (1)
    {
        printf("\033[2J");
        for (int i = 0; i < 5; i++)
        {
            displayStar(star_data[i][0], star_data[i][1], star_data[i][2]);
        }
        for (int i = 0; i < 5; i++)
        {
            if ((rand() % 10) % 2 == 0 && star_data[i][0] > 0 && star_data[i][0] < 25)
                star_data[i][0] -= 1;
            else
                star_data[i][0] += 1;
            if ((rand() % 10) % 2 == 0 && star_data[i][1] > 0 && star_data[i][1] < 80)
                star_data[i][1] -= 1;
            else
                star_data[i][1] += 1;
        }
        Sleep(1000);
    }
    printf("\033[75;0H\033?25h");
}