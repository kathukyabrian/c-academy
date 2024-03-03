#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void decimalToBinary(int);

int main()
{

    int decimalNumber;
    printf("Enter a number to get binary value for:\n");
    scanf("%d", &decimalNumber);

    decimalToBinary(decimalNumber);

    return 0;
}

void decimalToBinary(int number)
{
    int binaryNumber = 0, i = 1, remainder;

    while (number > 0)
    {
        remainder = number % 2; 
        number /= 2; 
        binaryNumber += remainder * i; 
        i *= 10;
    }

    printf("binary value: %d\n", binaryNumber);
}
