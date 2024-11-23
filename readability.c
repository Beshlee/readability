#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(char *text);
int count_words(char *text);
int count_sentences(char *text);

int main(void)
{
    char text[1000];
    printf("Text: ");
    fgets(text, sizeof(text), stdin);

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = ((float)letters / (float)words) * 100;
    float S = ((float)sentences / (float)words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    int final_index = round(index);

    if (final_index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (final_index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", final_index);
    }
}

int count_letters(char *text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(char *text)
{
    int count = 0;
    int in_word = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isspace(text[i]))
        {
            if (in_word)
            {
                count++;
                in_word = 0;
            }
        }
        else
        {
            in_word = 1;
        }
    }

    if (in_word)
    {
        count++;
    }

    return count;
}

int count_sentences(char *text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}

