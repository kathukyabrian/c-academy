#include <stdlib.h>
#include <stdio.h>

int main()
{

    // open note.txt in read mode
    // the result is a file pointer
    // possible modes
    // r - read
    // w - write
    // a - append
    // r+ - read extended
    // w+ - write extended
    // a+ - append extended
    // b - optionally specified to open a file in binary

    /**
     * @brief
     * file access mode x can be appended to w or w+ to avoid
     * overwriting a file if it exists already
     */
    FILE *file = fopen("note.txt", "r");

    char buff[255];

    while(fgets(buff, 255, file)){
        printf("%s", buff);
    }

    // close the file
    fclose(file);

   
    return 0;
}