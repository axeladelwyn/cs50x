#include "bmp.h"
// header file basically just a prototype collected into a group
// Convert image to grayscale
// image[0][0] represents the pixel in the upper-left corner of the image
void grayscale(int height, int width, RGBTRIPLE image[height][width]);

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]);

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width]);

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]);

