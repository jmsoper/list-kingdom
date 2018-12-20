#include <stdio.h>

int main(void){
  //just setting up vars
  int N;
  FILE *ofile;
  int selection = 1;

  //check if the file exists - we append if existing, create it not.
  char *filename="task-data.txt";
  printf("welcome to the kingdom of lists!\n");
  ofile = fopen(filename, "a");

  //start the program loop
  do {
    printf("Please enter a number. Enter -1 to quit.\n");
    scanf("%d", &N);
    if(N != -1){
      fprintf(ofile, "%d ", N);
    } else {
      printf("Exiting program.\n");
    }
  } while (N != -1);

  fclose(ofile);
  return 0;
}
