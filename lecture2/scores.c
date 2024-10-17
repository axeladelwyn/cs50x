#include <stdio.h>
#include <cs50.h>

float average(int length, int array[]);

int main(void)
{
    // initialization
    const int N = 3;

    int scores[N];

    for (int i = 0; i < N; i++)
    {
        // i is 0,1,2,3,4
        scores[i] = get_int("Scores: ");
    }
    // divide by float number 3.0 to change it into float
    printf("Average: %f\n", average(N, scores));
}

float average(int length, int array[])
{
    int sum = 0 ;
    for (int i = 0; i < length; i++)
    {
        // add sum with array
        sum += array[i];
    }
    // return average(float)
    return sum / (float) length;
}
