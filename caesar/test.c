#include "cs50.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2) // трябва точно един аргумент
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string key_str = argv[1];
    for (int i = 0; i < strlen(key_str); i++)
    {
        if (!isdigit(key_str[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(key_str) % 26; // нормализираме ключа
    string text = get_string("plaintext: ");

    printf("ciphertext: ");
    for (int i = 0; i < strlen(text); i++)
    {
        char c = text[i];
        if (isupper(c))
            printf("%c", 'A' + (c - 'A' + key) % 26);
        else if (islower(c))
            printf("%c", 'a' + (c - 'a' + key) % 26);
        else
            printf("%c", c);
    }
    printf("\n");
}
