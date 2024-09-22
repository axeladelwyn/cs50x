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

    string letter[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};
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
    // use size of function that alrady been made
    // strcmp takes both string and compare it and return true or false depending on the result
    for (int i = 0, length = sizeof(letter) ; i < length; i++ )
    {
        string elem = letter[i];
        // if its return 0 means is return true
        if (strcmp(elem, s) == 0)
        {
            printf("Found the string!\n");
        }
        else
        {
            printf("Did not found the string!\n");
        }
    }

    return 0;
}


