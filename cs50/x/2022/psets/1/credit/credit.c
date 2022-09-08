#include <cs50.h>
#include <math.h>
#include <stdio.h>

int checksum(long card_number);
bool is_valid(int checksum);
char *ccard_type(long card_number);

int NO_OF_DIGITS = 0;

int main(void)
{
    // Prompt user to enter a credit card number
    long card_number = get_long("Number: ");
    // long number = card_number;

    // Calculate checksum
    int sum = checksum(card_number);

    // Print card type
    if (is_valid(sum))
    {
        printf("%s\n", ccard_type(card_number));
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}

// Calculate and return the checksum of a credit card number
int checksum(long card_number)
{
    int sum = 0;
    while (card_number)
    {
        // Get each digit, starting from the end
        int digit = card_number % 10;
        card_number /= 10;
        NO_OF_DIGITS++;

        // If digit is at even position
        if (NO_OF_DIGITS % 2 == 0)
        {
            // Multiply each digit by 2
            int product = digit * 2;

            // If product has two digits, split them
            if (product >= 10)
            {
                while (product)
                {
                    int digit2 = product % 10;
                    product /= 10;
                    sum += digit2;
                }
            }
            // If product is a single digit number
            else
            {
                sum += product;
            }
        }
        // If digit is at odd position
        else
        {
            sum += digit;
        }
    }
    return sum;
}

// Checks if a credit card number is valid or not
bool is_valid(int checksum)
{
    if (checksum % 10 == 0)
    {
        return true;
    }
    return false;
}

// Check and return the name of the credit card company
char *ccard_type(long card_number)
{
    // Getting first and first two digits of credit card number
    int first_two_digits = card_number / pow(10, NO_OF_DIGITS - 2);
    int first_digit = first_two_digits / 10;

    // VISA
    if ((NO_OF_DIGITS == 13 || NO_OF_DIGITS == 16) && (first_digit == 4))
    {
        return "VISA";
    }
    // AMERICAN EXPRESS
    else if ((NO_OF_DIGITS == 15) && (first_two_digits == 34 || first_two_digits == 37))
    {
        return "AMEX";
    }
    // MASTERCARD
    else if ((NO_OF_DIGITS == 16) && (first_two_digits >= 51 && first_two_digits <= 55))
    {
        return "MASTERCARD";
    }
    // INVALID
    else
    {
        return "INVALID";
    }
}
