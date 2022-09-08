#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // Prompt user for input & validate input
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int row = 0; row < height; row++)
    {
        // Print spaces
        for (int space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }
        // Print hashes
        for (int hash = 0; hash < row + 1; hash++)
        {
            printf("#");
        }
        // Next line
        printf("\n");
    }
}