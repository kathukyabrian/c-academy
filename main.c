#include <stdlib.h>
#include <stdio.h>

void decorate(){
    printf("================================\n");
}

int main(){

    printf("Using malloc to allocate memory\n");

    // use malloc - returns a pointer
    // here we are creating an array of 4 integers
    int *intArray = malloc(4 * sizeof(int));

    // could be a null pointer
    if(intArray){
        for(int n=0; n<4; ++n){
            intArray[n] = n*n;
        }

        for(int n=0; n<4; ++n){
            printf("%d element is %d\n",n, intArray[n]);
        }
    }

    // free the memory address to avoid memory leak
    free(intArray);


    decorate();

    printf("Using calloc to allocate memory\n");

    // use  calloc - takes 2 arguments(number, size)
    int *intArrayCalloc = calloc(4, sizeof *intArrayCalloc);
    if(intArrayCalloc){
        for(int n=0; n<4; ++n){
            intArrayCalloc[n] = n*n;
        }

        for(int n=0; n<4; ++n){
            printf("%d element is %d\n",n, intArrayCalloc[n]);
        }
    }

    // free(intArrayCalloc);

    decorate();
    
    printf("Using realloc to reallocate memory\n");
    int *intArrayRealloc = realloc(intArrayCalloc, 10 * sizeof *intArrayRealloc);
    if(intArrayRealloc){
         for(int n = 0; n < 4; ++n){
            printf("%d element is %d\n",n, intArrayRealloc[n]);
         }

         free(intArrayRealloc);
    }else{
        free(intArrayCalloc);
    }

}