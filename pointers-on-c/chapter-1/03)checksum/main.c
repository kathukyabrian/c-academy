/*
Write a program that reads characters from the standard input and writes them to
the  standard  output.  It  should  also  compute  a  checksum  and  write  it  out  after  the
characters.
The checksum is computed in a signed char variable that is initialized to —1. As
each  character  is  read  from  the  standard  input,  it  is  added  to  the  checksum.  Any
overflow  from  the  checksum  variable  is  ignored.  When  all  of  the  characters  have
been  written,  the  checksum  is  then  written  as  a  decimal  integer,  which  may  be
negative. Be sure to follow the checksum with a newline.
On  computers  that  use  ASCII,  running  your  program  on  a  file  containing  the
words Hello world! followed by a newline should produce the following output:
Hello world!
102
 */

/*
H - 72
e - 101
l - 108
l - 108
o - 111
  - 32
w - 119
o - 111
r - 114
l - 108
d - 100
! - 33
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char input[100];

  printf("enter a line, I will give you the line and a checksum\n");

  while (fgets(input, sizeof(input), stdin))
  {
    printf("%s\n", input);
    // printf("generating checksum, line size = %d.....", sizeof(input));

    signed char checksum = -1;
    for (int i = 0; i < strlen(input) - 1; i++)
    {
      signed char character = input[i];
      checksum += character;
      printf("character = %c, value = %d\n", input[i], character);
    }
    printf("checksum = %d", checksum);
  }
}
