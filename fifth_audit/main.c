#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main()
{
    srand(time(NULL));
    int chance = 0;
    printf("\033[2J");
    for (int x = 0; x < 24; x++)
    {
        
        printf("\033[2J");
        for (int y = 0; y < 79; y++)
        {
            if ((rand() % 100) % 2 == 0)
                printf("\033[%d;%dH*", x, y);
        }
        sleep(1);
    }
}