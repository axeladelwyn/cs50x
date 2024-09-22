#include <cs50.h>
#include <stdio.h>


int main(void) {
    string name = get_string("please input your name: ");

    string last_name = get_string("Input your last name: ");
    // printf("Hello, World.\n");


    // get int
    int age = get_int("Input your age: ");

    int number = get_int("Input your phone number: ");
    printf("Hello, %s %s. Your age is %i and your phonenumber is %i \n", name, last_name, age, number);
    // get name , age, phone number
}
