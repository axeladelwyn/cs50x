#include <cs50.h>
#include <stdio.h>

int addition(int a , int b);

int main(void) {
    int x = get_int("x : ");

    int y = get_int("y : ");

    // int z = addition(x , y);
    // format to accept integer %i

    double z = (double)x / (double)y;
    printf("%.20f\n", z);

    int ina_code = 62;
    printf("The code is {%i}\n", ina_code);

    

    // char country_code = 82;
    // printf("the variable is %c\n", country_code);
}

// int addition(int a, int b) {
//     return a + b;
// }

