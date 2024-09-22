/**
 * adder-1.c
 * Doug Lloyd
 * lloyd@cs50.harvard.edu
 *
 * Adds two numbers.
 *
 * Demonstrates use of CS50's library and functions
 */


// includes
#include <cs50.h>
#include <stdio.h>

float multiply(int a, int b);
// declare function prototype
int add_two_ints(int a, int b);

int main(void)
{
    // ask user for input
    int x = get_int("Give me an integer: ");
    int y = get_int("Give me another integer: ");

    // add the two numbers together via a function call
    int z = add_two_ints(x, y);

    float mult = multiply(x, y);
    // output the result
    printf("The sum of %i and %i is %i!\n", x, y, z);

    printf("The product of %i and %i is %f!\n", x, y, mult);

}

int add_two_ints(int a, int b)
{
    int sum = a + b;
    return sum;
}
float multiply(int a, int b)
 {
    float sum;
    sum = (float)a * (float)b;
    return sum;
 }
