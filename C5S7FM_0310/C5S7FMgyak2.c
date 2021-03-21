#include <stdio.h>
#include <stdlib.h>

int main()
{
   char input[100];
   printf("Enter the command:\n");
   scanf("%s", input);
   system(input);

   return 0;
}