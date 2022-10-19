#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = image[i][j].rgbtBlue;
            float blue = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float average = round((red + blue + green) / 3);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp[i][j] = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = 0;
            float blue = 0;
            float green = 0;
            int counter = 0;
            for (int h = -1; h < 2; h++)
            {
                for (int w = -1; w < 2; w++)
                {
                    if (i + h < 0 || i + h >= height)
                    {
                        continue;
                    }
                    if (j + w < 0 || j + w >= width)
                    {
                        continue;
                    }
                    red += temp[i + h][j + w].rgbtRed;
                    blue += temp[i + h][j + w].rgbtBlue;
                    green += temp[i + h][j + w].rgbtGreen;
                    counter++;
                }
            }
            image[i][j].rgbtRed = round(red / counter);
            image[i][j].rgbtBlue = round(blue / counter);
            image[i][j].rgbtGreen = round(green / counter);
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float xRed = 0;
            float xBlue = 0;
            float xGreen = 0;
            float yRed = 0;
            float yBlue = 0;
            float yGreen = 0;
            for (int h = -1; h < 2; h++)
            {
                for (int w = -1; w < 2; w++)
                {
                    if (i + h < 0 || i + h >= height)
                    {
                        continue;
                    }
                    if (j + w < 0 || j + w >= width)
                    {
                        continue;
                    }
                    xRed += temp[i + h][j + w].rgbtRed * Gx[h + 1][w + 1];
                    xBlue += temp[i + h][j + w].rgbtBlue * Gx[h + 1][w + 1];
                    xGreen += temp[i + h][j + w].rgbtGreen * Gx[h + 1][w + 1];
                    yRed += temp[i + h][j + w].rgbtRed * Gy[h + 1][w + 1];
                    yBlue += temp[i + h][j + w].rgbtBlue * Gy[h + 1][w + 1];
                    yGreen += temp[i + h][j + w].rgbtGreen * Gy[h + 1][w + 1];
                }
            }
            int red = round(sqrt(xRed * xRed + yRed * yRed));
            int green = round(sqrt(xGreen * xGreen + yGreen * yGreen));
            int blue = round(sqrt(xBlue * xBlue + yBlue * yBlue));
            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }

            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
    }
    return;
}
