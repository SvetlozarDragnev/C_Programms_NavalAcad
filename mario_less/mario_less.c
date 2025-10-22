#include <stdio.h>
#include "cs50.h"

int main(void)
{

    int height;

    do
    {
        height = get_int("Height: ");
    } while (height < 1 || height > 8);

    for (int row = 1; row <= height; row++)
    {

        for (int space = height - row; space > 0; space--)
        {

            printf(" ");
        }

        for (int sym = 0; sym < row; sym++)
        {
            printf("#");
        }

        printf("  ");

        for (int sym = 0; sym < row; sym++)
        {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}