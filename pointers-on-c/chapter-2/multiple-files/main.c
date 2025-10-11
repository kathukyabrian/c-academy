/*
Write  a  program  with  three  functions  in  three  separate  source  files.  The  function 
increment  should  take  a  single  integer  argument  and  return  the  value  of  that 
argument plus one. This function should be in the file increment.c 
The  second  function  is  called  negate.  It  also  takes  a  single  integer  argument  and 
return the negated value of that argument (for example, if the argument is 25, the 
function should return -25; if the argument is -612, the function should return 612). 
The  final  function  is  main,  in  the  file  main.c,  and  it  should  call  each  of  the  other 
functions with the values 10, 0, and -10 and print the results. 
*/

#include <stdlib.h>
#include <stdio.h>

int increment(int);
int negate(int);
void decorate();

int main()
{
    int values[] = {10,0,-10};
    int size = sizeof(values) / sizeof(int);

    for(int i = 0; i < size; i++){
        int val = values[i];
        decorate();
        printf("increment value of %d = %d\n", val, increment(val));
        printf("negation value of %d = %d\n", val, negate(val));
        
    }
}

void decorate()
{
    printf("++++++++++++++++++++++++++++++++\n");
}

/*
To compile run
gcc main.c negate.c increment.c -o main
*/