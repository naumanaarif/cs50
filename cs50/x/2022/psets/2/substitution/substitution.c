#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool only_alphabets(string s);
bool any_duplicates(string s);
string encipher(string s, string key);

int main(int argc, string argv[])
{
    // Validate command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // Check key length
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // Check for non-alphabetic characters
    if (!(only_alphabets(argv[1])))
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }
    // Check for duplicate characters
    if (any_duplicates(argv[1]))
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }

    // Store command-line argument as key
    string key = argv[1];

    // Get plaintext from the user
    string plaintext = get_string("plaintext:  ");

    // Encipher plaintext and store as ciphertext
    string ciphertext = encipher(plaintext, key);

    // Print ciphertext
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

// Return true if string contains only alphabetic characters, else return false
bool only_alphabets(string s)
{
    // Iterate through each character of the string
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // If a character is non-alphabetic, return false
        if (!(isalpha(s[i])))
        {
            return false;
        }
    }
    return true;
}

// Return true if any duplicate characters found in the string, else return false
bool any_duplicates(string s)
{
    // Iterate through each character of the string
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // Compare the character with each character of the string (excluding itself)
        for (int j = 0; j < n; j++)
        {
            // Return true if a match is found
            if (!(i == j) && (s[i] == s[j]))
            {
                printf("Key must not contain repeated characters.\n");
                return true;
            }
        }
    }
    return false;
}

// Encipher text using a key, while preserving the case
string encipher(string s, string key)
{
    // Iterate through each character of plaintext
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // If character is an alphabet
        if (isalpha(s[i]))
        {
            // If character is uppercase
            if (isupper(s[i]))
            {
                // Enchipher character using key, while preserving the case
                s[i] = toupper(key[(s[i] - 'A')]);
            }
            // If character is lowercase
            else if (islower(s[i]))
            {
                // Enchipher character using key, while preserving the case
                s[i] = tolower(key[(s[i] - 'a')]);
            }
        }
    }
    return s;
}