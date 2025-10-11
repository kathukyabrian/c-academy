/*
Write a program that reads lines from the standard input. Each line is printed on 
the standard output preceded by its line number. Try to write the program so that 
it has no built in limit on how long a line it can handle.
*/

#include <stdlib.h>
#include <stdio.h>

int main(){
    int i = 1;

    char input[100];

    printf("Enter a line, I will respond with a line number and the line\n");

    while(fgets(input, sizeof(input), stdin)){
        printf("%d: %s", i, input);
        i++;
    }
}