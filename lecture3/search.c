#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // pseudo code

    // in array of integer search the value inside of it
    int array[] = {25, 30, 25, 1, 2, 3, 4};
    int array_length = sizeof(array) / sizeof(array[0]);
    // get input
    // int number = get_int
    int number = get_int("Enter the number you want to search!: ");

    string letter[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};
    // divide the length of the array by 1
    int letter_length = sizeof(letter) / sizeof(letter[0]);
    // get string

    string s = get_string("Enter the string you want to search? ");

    // do an algorithm to search for it
    // if number in array print True
    // return true
    // for every number in array if its match return True
    // for int i = 0; i < length of array ; i ++
    // index through the array array[i]
    // if array[i] same as number return True
    bool found_number = false;
    for (int i = 0; i < array_length; i++)
    {
        if (array[i] == number)
        {
            found_number = true;
            break;
        }
    }

    // if found number then print(found)
    if (found_number)
    {
        printf("Found number!\n");
    }
    else
    {
        printf("Did not found number!\n");
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
    bool found_string = false;
    for (int i = 0; i < letter_length; i++ )
    {
        // if its return 0 means is return true
        if (strcmp(letter[i], s) == 0)
        {
            found_string = true;
            break;
        }
    }

    // if found string = true, print ("found string!")

    if (found_string)
    {
        printf("Found the string!\n");
    }
    else
    {
        printf("Did not found the string!\n");
    }

    return 0;
}


