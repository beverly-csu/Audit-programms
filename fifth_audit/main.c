#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int chance = 0;

    for (int y = 0; y < 15; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            chance = rand() % 10;
            if (chance > 4 && chance < 8)
                printf("\033[%d#B*", x);
        }
    }
}