#include <stdlib.h>
#include <stdio.h>
#include "bitwise.h"

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

    int x = 10; //1010
    int y = 15; //1111

    printf("value of x before swapping is %d\n", x);
    printf("value of y before swapping is %d\n", y);

    // rules of bitwise xor
    // 1 ^ 0 = 1
    // 0 ^ 1 = 1
    // 0 ^ 0 = 0
    // 1 ^ 1 = 0


    // 1010
    // 1111
    // ----
    // 0101

    // 0101
    // 1111
    // ----
    // 1010 = 10

    // 1010
    // 0101
    // ----
    // 1111

    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    // explanation
    // x = x ^ y
    // y = x ^ y
    // y = (x ^ y) ^ y
    // y = x ^ (y ^ y)
    // y = x ^ 0
    // y = x  -> at this point the value of x is now in variable y

    // x = x ^ y
    // x = (x ^ y) ^ y
    // x = x ^ (y ^ y)
    // x = x ^ 0
    // x = x

    printf("value of x after swapping is %d\n", x);
    printf("value of y after swapping is %d\n", y);


    unsigned int hex = 0;
    unsigned char colorOne = 10;
    unsigned char colorTwo = 20;
    unsigned char colorThree = 30;
    unsigned char colorFour = 10;

    hex = colorOne << 24 | colorTwo << 16 | colorThree << 8 | colorFour ;
    // 00001010 00010100 00011110 00001010

    printf("the value of x is %b in binary and %x in hex\n", hex, hex);


    // not bitwise operator gets the 2's complement of a value
    // the result of the flipping is -(x+1)
    unsigned char num = 100;
    printf("not bitwise operation value %d\n", ~100);

    // you can or several flags instead of using booleans
    // if we used booleans we would use 3 bytes - each boolean flag is 3 bytes

    unsigned char flags = 0;
    flags |= READ_PERMISSION | WRITE_PERMISSION | ADMIN_PERMISSION;
    printf("flags = %b\n", flags);

    // linux file permissions uses bitwise operations
    // chmod 777 folder
    // 777 - file owner, group, everyone else
    // 7 in binary is 111 meaning that user can read, write and execute
    // 110 - 6 - read, write, no excute
    // 100 - 4 - read only

    unsigned char linuxPermission = 4;
    printf("linux permission in binary %b\n", linuxPermission);

    printf("This user can read %b\n", (linuxPermission & 0b100) ==  0b100);
    printf("This user can write %b\n", (linuxPermission & 0b010) == 0b010);
    printf("This user can execute %b\n", (linuxPermission & 0b001) == 0b001);
    // 100 & 111 = 100

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