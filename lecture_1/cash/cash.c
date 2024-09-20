#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int change;
    // initialize counter
    int counter = 0;
    // if its bigger than 25 bite using 25
    // it only return 1
    // my assumption that this is gonna works and change get decreased every time
    // but what happens is it only increment counter by 1
    // i need a loop to itereate through this
    do
    {
        change = get_int("What is the change value: ");
    }
    while (change < 0);

    while (change > 0)
    {
        if (change > 25)
        {
            counter += 1;
            change = change - 25;
        }
        else if (change > 10)
        {
            counter += 1;
            change = change - 10;
        }
        else if (change > 5)
        {
            counter += 1;
            change = change - 5;
        }
        else
        {
            counter += 1;
            change = change - 1;
        }
        // print the change
        printf("The change is %i\n", change);
        printf("Amount of coin given %i\n", counter);
    }
    // print the counter
    printf("%i\n", counter);
}
