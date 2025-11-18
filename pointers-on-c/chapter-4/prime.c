#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void checkIfPrime(int number);

int main()
{
    printf("this function checks if a number is prime....\n");

    checkIfPrime(10);
    checkIfPrime(1);
    checkIfPrime(-13);
    checkIfPrime(13);
    checkIfPrime(27);
    checkIfPrime(57);
    checkIfPrime(1009);
    checkIfPrime(23773737);
    checkIfPrime(810);
    checkIfPrime(100000001);
    checkIfPrime(499999);
    checkIfPrime(91);
}

void checkIfPrime(int number)
{
    printf("checking if number: %d is prime\n", number);

    if (number < 1)
    {
        printf("number %d is not prime\n", number);
        return;
    }

    if (number == 1 || number == 2)
    {
        printf("number %d is prime\n", number);
        return;
    }

    if (number % 2 == 0)
    {
        printf("number %d is not prime\n", number);
        return;
    }

    // get squareroot of number
    int optimizedMaximumDivisor = sqrt((double)number) + 1;

    for (int i = 2; i < optimizedMaximumDivisor; i++)
    {
        if (number % i == 0)
        {
            printf("number %d is not prime, it is divisible by %d\n", number, i);
            return;
        }
    }

    printf("number %d is prime\n", number);
}