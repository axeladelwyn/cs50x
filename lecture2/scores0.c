// Averages three (hardcoded) numbers

#include <stdio.h>
#include <cs50.h>
int main(void)
{
    // Scores
    int score1 = 72;
    int score2 = 73;
    int score3 = 33;

    // Print average
    printf("Average: %f\n", average());
}

// make a function that return a float and average
float average(int length, int array[])
{
    int sum = 0;
    for(int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    // return float and average
    return sum / (float) length;

}
