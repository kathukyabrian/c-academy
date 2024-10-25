#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Person{
    char name[20];
    char email[40];
    int age;
};

int main(){

    // create an instance of person
    struct Person brian;

    // create a pointer to brian
    struct Person* ptr = &brian;

    strcpy(brian.name, "Brian");
    strcpy(brian.email, "briankathukya2000@gmail.com");
    brian.age = 20;

    printf("My name is %s. I am %d years and my email is %s", (*ptr).name, (*ptr).age, (*ptr).email);

}