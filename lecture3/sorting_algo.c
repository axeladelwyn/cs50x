#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // For i from 0 to n-1
    // Find the smallest number between numbers[i] and numbers[n-1]
    // Swap smallest number with numbers[i]

    /* repeat n-1 times
        For i from 0 to n-2
            If numbres[i] and number[i+1] out of order
                swap them*/

    string name[]= {"Matthew", "Samis", "Alyssa", "Douglas", "Cecelia", "Lucas", "Ramya"};
    for (int i = 0, length = sizeof(name)/ sizeof(name[0]); i < length; i++)
    {
        printf("%s\n", name[i]);
    }
    /* If no doors left
    Return false
If number behind middle door
    Return true
Else if number < middle door
    Search left half
Else if number > middle door
    Search right half */


    /* Merge Sort
    If only one number
    Quit
    Else
        Sort left half of number
        Sort right half of numbre
        Merge sorted halves*/
}
