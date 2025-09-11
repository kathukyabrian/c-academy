#include <stdlib.h>
#include <stdio.h>

void decorate();

int main(){
  char * name;
  printf("Enter your name\n");
  scanf("%s", &name);
  printf("My name is %s", &name);
  decorate();
}

void decorate(){
  printf("\n++++++++++++++++++++++++++++++++");
}
