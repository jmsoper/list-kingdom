#include <stdio.h>
#include <string.h>

int main(void){
  //just setting up vars
  int i=0;
  char command[100];
  FILE *ofile;

  //check if the file exists - we append if existing, create it not.
  char *filename="task-data.txt";
  printf("welcome to the kingdom of lists!\n");
  ofile = fopen(filename, "a");

  //start the program loop
  do {
    printf("Please enter a task name. Type 'exit' to quit.\n");
    scanf("%s", command);
    i = strcmp(command, "exit");
    if(i!=0){
      fprintf(ofile, "%s ", command);
    } else {
      printf("Exiting program.\n");
    }
  } while (i!=0);

  fclose(ofile);
  return 0;
}
