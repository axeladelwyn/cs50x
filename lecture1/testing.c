#include <stdio.h>
#include <cs50.h>


int main(void) {
    int calls = get_int("Input the value of calls: ");
    calls += 5;
    calls *= 2;
    calls -= 10;
    calls = calls / 3;

    printf("%i\n", calls);

    // int %i
    // float %f
    // char %c
    // string % s

}
