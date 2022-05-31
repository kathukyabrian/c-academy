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

    if (!file)
    {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // keep reading the file if EOF not reached
    int c;
    while ((c = fgetc(file)) != EOF)
    { // standard C I/O file reading loop
        putchar(c);
    }

    // check if an error occured or if EOF was reached
    if (ferror(file))
    {
        puts("I/O error while reading file");
    }
    else if (feof(file))
    {
        puts("End of file reached successfully");
    }

    // close the file
    fclose(file);

   
    return 0;
}