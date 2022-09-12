#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Take text as input from the user
    string text = get_string("Text: ");

    // Count and store the number of letters, words and sentences
    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);

    // Calculate Grade of the text using Coleman-Liau index
    float L = (letters / words) * 100;
    float S = (sentences / words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    // Print Grade of the text
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

// Count and return number of letters in a text
int count_letters(string text)
{
    int letters = 0;

    // Iterate through each character in the text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

// Count and return number of words in a text
int count_words(string text)
{
    int words = 0;

    // Iterate through each character in the text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words + 1;
}

// Count and return number of sentences in a text
int count_sentences(string text)
{
    int sentences = 0;

    // Iterate through each character in the text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}