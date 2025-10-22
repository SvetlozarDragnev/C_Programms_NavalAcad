#include "cs50.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }

    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {

        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key \n");
            return 1;
        }
    }

    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");
    int len = strlen(plaintext);
    char ciphertext[len + 1];
    ciphertext[len] = '\0';

    for (int i = 0; i < len; i++)
    {

        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                ciphertext[i] = (plaintext[i] - 'A' + key) % 26 + 'A';
            }
            else if (islower(plaintext[i]))
            {
                ciphertext[i] = (plaintext[i] - 'a' + key) % 26 + 'a';
            }
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    printf("ciphertext: %s\n", ciphertext);
}

//gcc .\caesar\caesar.c .\caesar\cs50.c -o .\caesar\caesar
//PS G:\ICT, Naval Academy\C tests> ./caesar/caesar