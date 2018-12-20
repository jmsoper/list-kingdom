#include <stdio.h>
#include <string.h>

int main(void){
  //just setting up vars
  int taskcmp=0;
  int commandcmp=0;
  int exitcmp=0;
  char command[100];
  char taskname[100];
  FILE *ofile;

  //check if the file exists - we append if existing, create it not.
  char *filename="task-data.txt";
  printf("welcome to the kingdom of lists!\n");
  ofile = fopen(filename, "a");

  //start the program loop
  do {
    printf("Please enter a task name. Type 'exit' to quit.\n");
    scanf("%s %s", command, taskname);
    exitcmp = strcmp(command, "exit");
    if(exitcmp!=0){
      commandcmp = strcmp(command, "read");
      if (commandcmp==0){
        //read out the file and print to screen.
        printf("reading out your tasks!!");
      }
      commandcmp = strcmp(command, "add");
      if (commandcmp==0){
        //add the command
        // -> we have an error in this whole thing about taking in the wrong number of args
        fprintf(ofile, "%s ", taskname);
      }
    } else {
      printf("Exiting program.\n");
    }
  } while (exitcmp!=0);

  fclose(ofile);
  return 0;
}
