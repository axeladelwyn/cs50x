#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // pseudo code

    // in array of integer search the value inside of it
    int array[] = {25, 30, 25, 1, 2, 3, 4};

    // get input
    // int number = get_int
    int number = get_int("Enter the number you want to search!: ");

    string string[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};
    // get string
    string s = get_string("Enter the string you want to search? ");

    // do an algorithm to search for it
    // if number in array print True
    // return true
    // for every number in array if its match return True
    // for int i = 0; i < length of array ; i ++
    // index through the array array[i]
    // if array[i] same as number return True
    for (int i = 0; i < 7; i++)
    {
        if (array[i] == number)
        {
            printf("Found the number!\n");
            return true;
        }
        else
        {
            printf("Did not found number!\n");
            return false;
        }
    }


    //how to count through length of array?
    // for every element in array add a counter
    // return incremented counter



    // if string match then return True or print found! same like before
    // for every string if its match return true
    // for (int i = 0 ; i < length of string; i++)
    // index through the string and compare it
    for (int i = 0, length =  ; i < )

    return 0;
}


int get_length(arr[])
{
    // loop through all the away
    // increment counter
    // counter = 0
    int counter = 0;
    for (int i = 0 )
}
