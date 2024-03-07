#ifndef BITWISE_H
#define BITWISE_H

#define READ_PERMISSION 0b00000001
#define WRITE_PERMISSION 0b00000010
#define ADMIN_PERMISSION 0b00000100

#define LINUX_READ_PERMISSION 0b00000100
#define LINUX_WRITE_PERMISSION 0b00000010
#define LINUX_EXECUTE_PERMISSION 0b00000001

void checkIfEvenOrOdd(int);
void checkLinuxPermissions(unsigned char);

void decorate(){
    printf("================================\n");
}

void swapVariables(int, int);

#endif