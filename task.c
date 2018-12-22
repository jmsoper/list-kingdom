#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
  //just setting up vars
  char command[100];
  char taskname[100];
  char taskform[104] = "[ ]";
  char taskentry[104];
  FILE *ofile;
  char *helpmessage = "To add a task, enter 'add.' To see your tasks, enter 'read.' To leave the program, enter 'exit.' To see these instructions again, enter 'help.'";

  //check if the file exists - we append if existing, create it not.
  char *filename="task-data.txt";
  ofile = fopen(filename, "r");
  if (ofile == NULL) { 
    printf("welcome to the kingdom of lists!\n");
  } else {
    printf("welcome back to the kingdom of lists!\n");
  }
  fclose(ofile);
  ofile = fopen(filename, "a");
  printf("* * * * * * * * * * * * * * * * * * * *\n");
  printf("%s\n", helpmessage);

  //start the program loop
  do {
    strncpy(taskentry, taskform, sizeof(taskentry) - strlen(taskentry) - 1);
    scanf("%s", command); //we take in the command -- "add" | "help" | "read" | "exit" 
    if(strcmp(command,"exit")!=0){ // we check if we should exit.
      if (strcmp(command,"read")==0){
        //read out the file and print to screen.
        printf("reading out your tasks!!\n");
      } else if (strcmp(command,"add")==0){
        //get the task name with no spaces
        printf("Please enter a task name with no spaces: ");
        scanf("%s", taskname);
        //add the command
        fprintf(ofile, "%s ", strncat(taskentry, taskname, sizeof(taskentry) - strlen(taskentry) - 1));
        printf("\nYour task '%s' has been successfully added. \n", taskname);
      } else if (strcmp(command,"help")==0){
        printf("%s\n", helpmessage);
      } else {
        // if you type in a multi-word command that it doesn't recognize, this looks weird. Another fgets opportunity
        printf("'%s' is not a valid command. Enter 'help' to see a list of commands.\n", command);
      }
    } else {
      printf("Exiting program.\n");
    }
  } while (strcmp(command,"exit")!=0);

  fclose(ofile);
  return 0;
}
