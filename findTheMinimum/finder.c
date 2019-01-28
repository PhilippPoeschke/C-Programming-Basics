#include <stdio.h>
#include <stdlib.h> // exit(), EXIT_FAILURE
#include <limits.h> // INT_MAX, INT_MIN
//This function takes a txt file and reads out the numbers.

int main()
{
   int num;
   int min = INT_MAX; //for finding the min of the input file the initial min value must be as high as possible
   int max = INT_MIN; //for finding the max of the input file the initial max value must be as low as possible

   FILE *fp;
   fp = fopen("number.txt", "r"); //opens the file and gives you the rights of only reading

   while((fscanf(fp,"%d",&num)) != EOF) // says: until the End of File is not reached -> scan the file for a integer and store it in the variable num
     {
          if (num < min)
             min = num;
          if (num > max)
             max = num;
     }

    fclose(fp); //IMPORTANT -> Closing the file-input


    printf("Minimum is: %d\nMaximum is: %d \n", min, max);

return 0;
}
