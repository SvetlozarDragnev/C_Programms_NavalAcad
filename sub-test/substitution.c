#include "cs50.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
bool valid_key(string key);
char substitute(char plain, string key);

int main(int argc, string argv[])
{
    // Ensure only one command-line argument (the key)
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    // Validate the key
    if (!valid_key(key))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    // Get plaintext input
    string plaintext = get_string("plaintext:  ");

    printf("ciphertext: ");

    // Encrypt and print each character
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", substitute(plaintext[i], key));
    }

    printf("\n");
    return 0;
}

// Function to validate the key
bool valid_key(string key)
{
    int length = strlen(key);

    // Must contain exactly 26 characters
    if (length != 26)
    {
        return false;
    }

    // Track letters (case-insensitive)
    bool seen[26] = {false};

    for (int i = 0; i < length; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        int index = toupper(key[i]) - 'A';
        if (seen[index])
        {
            return false; // duplicate letter
        }
        seen[index] = true;
    }

    return true;
}

// Function to perform substitution
char substitute(char plain, string key)
{
    if (isupper(plain))
    {
        int index = plain - 'A';
        return toupper(key[index]);
    }
    else if (islower(plain))
    {
        int index = plain - 'a';
        return tolower(key[index]);
    }
    else
    {
        // Non-alphabetic characters unchanged
        return plain;
    }
}


//gcc .\sub-test\substitution.c .\sub-test\cs50.c -o .\sub-test\substitution    