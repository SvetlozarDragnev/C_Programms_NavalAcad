#include <stdio.h>
#include "cs50.h"

int main(void)
{

    int cents;
    do
    {
        cents = get_int("Change:  ");
    }

    while (cents < 0);

    int quaters = 0;
    if (cents >= 25)
    {
        quaters = cents / 25;
    }

    printf("Result %d - %d", cents, quaters);

    return 0;
}