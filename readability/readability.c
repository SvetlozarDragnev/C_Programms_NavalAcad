#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "cs50.h"

int get_letters(string text);
int get_words(string text);
int get_sentences(string text);
int main(void)
{

    string text = "";
    text = get_string("Text: \n");

    // index = 0.0588 * L - 0.296 * S - 15.8
    // where L is the average number of letters per 100 words in the text,
    //  and S is the average number of sentences per 100 words in the text.

    int letters = get_letters(text);
    int words = get_words(text);
    int sentences = get_sentences(text);

    
    double L = (double) letters / (double) words * 100.0;
    double S = (double) sentences / (double) words * 100.0;

    double formulaResult = (0.0588 * L) - (0.296 * S) - 15.8;

    int grade = (int) round(formulaResult);

    
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }

   // printf("%f\n", formulaResult);
}

int get_letters(string text)
{

    int letters = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            letters++;
        }
    }

    return letters;
}

int get_words(string text)
{
    int words = 0;

    int len = strlen(text);
    if (len > 0)
    {
        
        words = 1;
        for (int i = 0; i < len; i++)
        {
            if (text[i] == ' ')
            {
                words++;
            }
        }
    }

    return words;
}

int get_sentences(string text)
{

    int sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {

        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }
    return sentences;
}

// gcc .\readability\readability.c .\readability\cs50.c -o .\readability\readability    