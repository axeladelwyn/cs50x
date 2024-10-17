#include <stdio.h>

void meow(int n);

int main(void)
 {
    int i = 0;
    while (i < 10) {
        printf("meow\n");
        i++;
    }

    for (int counter = 0; counter < 10; counter++) {
        printf("woof\n");
    }

    meow(500);
 }


void meow(int n) {
    for (int i = 0; i < n; i++) {
        printf("meow\n");
    }
 }
