#include <stdlib.h>
#include <stdio.h>

int main(){
    int age = 10;
    char * name = "Brian";

    printf("memory address of age %p\n", &age);
    printf("memory address of name %p\n", &name);

    // &age and &name are reffered to as pointers
    // pointers are variables that story the memory address of a variable
}