#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
  //just setting up vars
  char command[100];
  char taskname[100];
  char taskform[104] = "[_]";
  char taskentry[104];
  char * prompt="*** ";
  FILE *ofile;
  char *helpmessage = "To add a task, enter 'add.' To see your tasks, enter 'read.' To leave the program, enter 'exit.' To see these instructions again, enter 'help.'";

  //check if the file exists
  char *filename="task-data.txt";
  ofile = fopen(filename, "r");
  if (ofile == NULL) { 
    printf("%swelcome to the kingdom of lists!\n", prompt);
  } else {
    printf("%swelcome back to the kingdom of lists!\n", prompt);
  }
  fclose(ofile);
  printf("%s * * * * * * * * * * * * * * * * * * * *\n", prompt);
  printf("%s%s\n%s", prompt, helpmessage, prompt);
  //start the program loop
  do {
    //I think this strncpy should actually be a malloc
    strncpy(taskentry, taskform, sizeof(taskentry) - strlen(taskentry) - 1);
    scanf("%s", command); //we take in the command -- "add" | "help" | "read" | "exit" 
    if(strcmp(command,"exit")!=0){ // we check if we should exit.
      if (strcmp(command,"read")==0){
        char task[104];
        //read out the file and print to screen.
        //this is actually a great usecase for malloc. but we'll get back to that.
        ofile = fopen(filename, "r"); 
        while(fscanf(ofile, "%s", task)!=EOF){
          printf("%s%s\n", prompt, task);
        }
        printf("%s", prompt);
        fclose(ofile);
      } else if (strcmp(command,"add")==0){
        //get the task name with no spaces
        printf("%sPlease enter a task name with no spaces: ", prompt);
        scanf("%s", taskname);
        //add the command
        ofile = fopen(filename, "a");
        fprintf(ofile, "%s ", strncat(taskentry, taskname, sizeof(taskentry) - strlen(taskentry) - 1));
        printf("%sYour task '%s' has been successfully added. \n%s", prompt, taskname, prompt);
        fclose(ofile);
      } else if (strcmp(command,"help")==0){
        printf("%s%s\n%s", prompt, helpmessage, prompt);
      } else {
        // if you type in a multi-word command that it doesn't recognize, this looks weird. Another fgets opportunity
        printf("%s'%s' is not a valid command. Enter 'help' to see a list of commands.\n%s", prompt, command, prompt);
      }
    } else {
      printf("%sExiting program.\n", prompt);
    }
  } while (strcmp(command,"exit")!=0);

  fclose(ofile);
  return 0;
}
