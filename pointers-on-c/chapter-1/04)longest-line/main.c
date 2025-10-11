/*
Write  a  program  that  reads  input  lines  one  by  one  until  end  of  file  is  reached, 
determines the length of each input line, and then prints out only the longest line 
that  was  found.  To  simplify  matters,  you  may  assume  that  no  input  line  will  be 
longer than 1000 characters.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int main()
{
    
    int longestLine = 0;
    char line[MAX_LINE_LENGTH];
    while(fgets(line, sizeof(line), stdin)){
        printf("%s", line);
        if(longestLine < (strlen(line) - 1)){
            longestLine = (strlen(line) - 1);
        }
        printf("longest line = %d\n", longestLine);

    }

    printf("longest line = %d", longestLine);

    return EXIT_SUCCESS;      

}