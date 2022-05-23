#include <stdlib.h>
#include <stdio.h>

#include "sum.h"

int sumOfTwoNumbers(int a, int b)
{
    return a + b;
}

int main()
{   
    int sum = sumOfTwoNumbers(1,2);
    printf("The sum of the 2 numbers is %d\n", sum);
    return 1;
}