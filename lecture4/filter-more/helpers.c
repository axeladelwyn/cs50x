#include "helpers.h"
#include <math.h>

// Convert image to grayscale
// top row first and bottom row last
// represent bitmap as a 2-dimensional array of pixels
// apply filtering
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // image height and width
    // round all floating point numbers into integers
    // black and white, set everything to 0x0
    // get the average color of RGB and set the value to that (all 3 of them)!
    // changing each indivudal pixels, convert it into black and white
    // loop through all pixels rows
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average_color =
                round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = average_color;
            image[i][j].rgbtGreen = average_color;
            image[i][j].rgbtBlue = average_color;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // original pixels still appears in the new image, just reflected
    // from left to right, using swap?
    // taking individual pixels and reflecting it on each row
    // how to reflect each individual pixels?
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            // for half the image
            // tmp variable
            RGBTRIPLE tmp = image[i][j];
            // swap the pixels, how to do it?
            // what do i want to swap? the pixels, what value is the pixels?
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = tmp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Blur image, using box blur
    // get the average color values that are within 1 row and column forming 3x3 box
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int redSum = 0, greenSum = 0, blueSum = 0;
            int count = 0;
            // change individual pixels, the average of 9 pixels
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;

                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        redSum += image[ni][nj].rgbtRed;
                        greenSum += image[ni][nj].rgbtGreen;
                        blueSum += image[ni][nj].rgbtBlue;
                        count++;
                    }
                }
            }

            temp[i][j].rgbtRed = round((float) redSum / count);
            temp[i][j].rgbtGreen = round((float) greenSum / count);
            temp[i][j].rgbtBlue = round((float) blueSum / count);
        }
    }
    // copy the blurred values back to the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}
// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Gx and Gy
    // multiplying the left by negative and right by positive in Gx
    // combine Gx and Gy into a single value by suing square root of Gx^2 + Gy^2
    // rounded to nearest integer
    // edge of the pixels will be 0
    int Gx[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    int Gy[] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};
    RGBTRIPLE temp[height][width];

    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            int sum_horizontal_red = 0, sum_vertical_red = 0;
            int sum_horizontal_green = 0, sum_vertical_green = 0;
            int sum_horizontal_blue = 0, sum_vertical_blue = 0;

            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = row + di;
                    int nj = column + dj;

                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        int index = (di + 1) * 3 + (dj + 1);
                        sum_horizontal_red += image[ni][nj].rgbtRed * Gx[index];
                        sum_vertical_red += image[ni][nj].rgbtRed * Gy[index];
                        sum_horizontal_green += image[ni][nj].rgbtGreen * Gx[index];
                        sum_vertical_green += image[ni][nj].rgbtGreen * Gy[index];
                        sum_horizontal_blue += image[ni][nj].rgbtBlue * Gx[index];
                        sum_vertical_blue += image[ni][nj].rgbtBlue * Gy[index];
                    }
                    // image[row][j] is individual pixels
                    // what i want to do with this?
                }
            }
            // the sums of horizontal and verticals

            // squares each channel and capped it at 255
            int red = round(sqrt(sum_horizontal_red * sum_horizontal_red +
                                 sum_vertical_red * sum_vertical_red));

            int green = round(sqrt(sum_horizontal_green * sum_horizontal_green +
                                   sum_vertical_green * sum_vertical_green));

            int blue = round(sqrt(sum_horizontal_blue * sum_horizontal_blue +
                                  sum_vertical_blue * sum_vertical_blue));

            temp[row][column].rgbtRed = (red > 255) ? 255 : red;
            temp[row][column].rgbtGreen = (green > 255) ? 255 : green;
            temp[row][column].rgbtBlue = (blue > 255) ? 255 : blue;
        }
    }
    // Copy the edge-detected values back to the original image
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            image[row][column] = temp[row][column];
        }
    }

    return;
}
