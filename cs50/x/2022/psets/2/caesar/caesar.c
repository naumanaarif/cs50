#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char chr, int key);

int main(int argc, string argv[])
{
    // Check command-line arguments
    if (!(argc == 2) || !(only_digits(argv[1])))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert command-line argument to int and store as key
    int key = atoi(argv[1]);

    // Prompt user to type plaintext
    string plaintext = get_string("plaintext:  ");

    // Iterate through each character of plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // Rotate character by key while preserving the case
        plaintext[i] = rotate(plaintext[i], key);
    }

    // Print ciphertext
    printf("ciphertext: %s\n", plaintext);

    return 0;
}

// Return true if string contains only digits, else return false
bool only_digits(string s)
{
    // Iterate through each character of string
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // If character is not a digit, return false
        if (!(isdigit(s[i])))
        {
            return false;
        }
    }
    return true;
}

// Return a character rotated by given key while preserving the case
char rotate(char chr, int key)
{
    // If character is an alphabet
    if (isalpha(chr))
    {
        // Uppercase character
        if (isupper(chr))
        {
            int ci = ((chr - 'A') + key) % 26;
            return ci + 'A';
        }
        // Lowercase character
        else if (islower(chr))
        {
            int ci = ((chr - 'a') + key) % 26;
            return ci + 'a';
        }
    }
    return chr;
}
