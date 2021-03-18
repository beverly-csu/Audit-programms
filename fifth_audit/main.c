#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void displayStar(int centerX, int centerY, int color) {
    printf("\033[%d;%dH*", centerY, centerX);
    printf("\033[%d;%dH*", centerY - 1, centerX);
    printf("\033[%d;%dH*", centerY + 1, centerX);
    printf("\033[%d;%dH*", centerY, centerX - 1);
    printf("\033[%d;%dH*", centerY, centerX + 1);
}

int main()
{
    srand(time(NULL));
    int chance = 0;
    printf("\033[2J");
    displayStar(5, 5, 0);
    // for (int x = 0; x < 24; x++)
    // {
    //     printf("\033[2J");
    //     for (int y = 0; y < 79; y++)
    //     {
    //         if ((rand() % 100) % 2 == 0)
    //             printf("\033[%d;%dH*", x, y);
    //     }
    //     sleep(1);
    // }
    printf("\033[75;0H");
}