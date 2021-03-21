#include <stdio.h>
#include <stdbool.h>

bool primeStatus(int number)
{
    int div = 2;
    bool isPrime = false;
    if (number == 1)
        return false;
    else if (number == 2)
        return true;
    while (div < number)
    {
        if (number % div != 0)
            isPrime = true;
        else
            return false;
        div++;
    }
    return isPrime;
}

int posPrime(int number)
{
    bool isNextPrime = false;
    int i = 2;
    int count = 0;
    while (1)
    {
        isNextPrime = primeStatus(i);
        if (isNextPrime)
            count++;
        if (count == number)
            return i;
        i++;
    }
}

int main()
{
    //int NextPrime = 0;
    //bool isPrime = false;
    int count = 0;
    scanf("%d", &count);
    int numbers[count];
    for (int i = 0; i < count; i++)
    {
        scanf("%d", &numbers[i]);
    }
    for (int i = 0; i < count; i++)
    {
        printf("%d\n", posPrime(numbers[i]));
    }
}