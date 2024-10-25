#include <stdio.h>
#include <stdlib.h>

int main()
{  
    int *ptr = malloc(10 * sizeof(int));

    for(int i = 0; i < 10; i++)
    {
        ptr[i] = i;
    } 


    int *ptr2 = ptr;
    free(ptr2);

    //note**** - free doesn't nullify the memory, it just ensures that the memory can be used again
    //the real diff - after freeing ptr2, allocating dynamic memory using malloc vs calloc
    //malloc does not zero the values
    //calloc zeros the values

    ptr2 = malloc(10 * sizeof(int));
    printf("*********************\n");
    printf("allocating memory using malloc.....\n\n");
    for(int i = 0; i < 10; i++) printf("%d = %d\n", i, ptr2[i]);

    ptr2 = calloc(10, sizeof(int));
    printf("*********************\n");
    printf("allocating memory using calloc.....\n\n");
    for(int i = 0; i < 10; i++) printf("%d = %d\n", i, ptr2[i]);

    free(ptr2);

    return 0;
}