#include <cs50.h>
#include <stdio.h>

void print_array(int a[], int length);

int main(void)
{
    // array with five element
    // int nights[5] = {7,8,6,8,9};
    // int length = 5;
    // print_array(nights, length);

    int  N = get_int("Enter a size " );
    int doubling[N];
    doubling[0] = 1;
    // append to element using for loop
    for (int i = 1; i < N; i++)
    {
        doubling[i] = doubling[i - 1] * 2;
        printf("%i\n" , doubling[i-1]);
    }


}

void print_array(int a[], int length)
{
    for (int i = 0 ; i < length; i++ )
    {
        // i is 0,1,2,3
        printf("element of array is %i\n", a[i]);
    }

}
