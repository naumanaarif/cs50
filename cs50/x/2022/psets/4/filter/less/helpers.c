#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // For each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate the average pixel value and round it to the nearest integer
            int avgRGB = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            // Set each color value to the average value
            image[i][j].rgbtRed = avgRGB;
            image[i][j].rgbtGreen = avgRGB;
            image[i][j].rgbtBlue = avgRGB;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // For each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate each new color value using the Sepia formula
            int sepiaRed = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

            // Ensure each Sepia value is an integer between 0 and 255, inclusive
            if (sepiaRed < 0)
            {
                sepiaRed = 0;
            }
            if (sepiaGreen < 0)
            {
                sepiaGreen = 0;
            }
            if (sepiaBlue < 0)
            {
                sepiaBlue = 0;
            }
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // Set each color value to its Sepia value
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // For each row
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Swap pixels on horizontally opposite sides
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][(width - 1) - j];
            image[i][(width - 1) - j] = tmp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image array
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // For Each Pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate the average color value for each channel
            int avgRed = 0, avgGreen = 0, avgBlue = 0;
            float count = 0;

            // Iterate through all neighbouring pixels
            for (int m = i - 1; m <= i + 1; m++)
            {
                for (int n = j - 1; n <= j + 1; n++)
                {
                    // If the pixel is valid
                    if (!(m < 0 || m > height - 1 || n < 0 || n > width - 1))
                    {
                        avgRed += copy[m][n].rgbtRed;
                        avgGreen += copy[m][n].rgbtGreen;
                        avgBlue += copy[m][n].rgbtBlue;
                        count++;
                    }
                }
            }
            // Round the average value to the nearest integer
            avgRed = round(avgRed / count);
            avgGreen = round(avgGreen / count);
            avgBlue = round(avgBlue / count);

            // Update old color values of each channel
            image[i][j].rgbtRed = avgRed;
            image[i][j].rgbtGreen = avgGreen;
            image[i][j].rgbtBlue = avgBlue;
        }
    }
}
