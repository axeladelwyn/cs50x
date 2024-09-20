#include <cs50.h>
#include <stdio.h>


int main(void) {
    string name = get_string("please input your name: ");

    string last_name = get_string("Input your last name: ");
    printf("Hello, World.\n");



    int age = get_int("Input your age: ");

    string number = get_string("Input your phone number: ");



    printf("name: %s\n", name);
    printf("age: %i\n", age);
    printf("Number: %s\n", number);



}
