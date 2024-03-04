#include <stdlib.h>
#include <stdio.h>

void checkIfEvenOrOdd(int);

int main(){
    int age = 24;

    printf("division by 2 = %d\n", age >> 1);
    printf("multiplication by 2 = %d\n", age << 1);


    // a byte - 2^8 = 256(0-255)
    unsigned char number = 10; //00001010 & 11111111
    // 00001010
    // 11111111
    // --------
    // 00001010
    // --------

    // 00001010
    // 11111111
    // --------
    // 11111111
    // --------

    // 00001010
    // 11110000
    // --------
    // 11111010
    
    int masked = number | 0xf0;
    printf("in binary %b\n", masked);


    // printf("please enter a number to check if it is even or odd\n");
    // int evenOrOddNumber;
    // scanf("%d", &evenOrOddNumber);
    // checkIfEvenOrOdd(evenOrOddNumber);
}

void checkIfEvenOrOdd(int number){
    // a number is odd if the lsb is 1
    // if we mask it with 1 then if the output is 1 then the number is odd

    // 10 = 0000 1010
    // 1 =  0000 0001

    // 0000 1010
    // 0000 0001
    // ---------
    // 0000 0000
    // ---------
    // there 10 is an odd number
    int result = number & 1;
    if(result == 1){
        printf("%d is an odd number\n");
    }else{
        printf("%d is an even number\n");
    }


}