#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
  // We use two pipes
  // First pipe send input string from parent
  // Second pipe to send concatenated string from child
  int pipefd1[2];
  int pipefd2[2];
  char fixed_str[] = "guilan.ac.ir";
  char input_str[100];
  pid_t p;

  if(pipe(pipefd1)==-1){
    fprintf(stderr, "Pipe Failed");
    return 1;
  }
  if(pipe(pipefd2)==-1){
    fprintf(stderr, "Pipe Failed");
    return 1;
  }
  printf("Enter the input string:\n");
  scanf("%s",input_str);
  p = fork();
  if(p<0){
    fprintf(stderr, "Fork Failed");
    return 1;
  }
  else if(p>0){
    //Parent Process
    char concat_str[100];
    // Write=1, Read=0
    close(pipefd1[0]); //Close reading end of first pipe
    // Write the input strig and close writing end of First
    //pipe
    write(pipefd1[1],input_str,strlen(input_str)+1);
    // Wait for child to send a string
    wait(NULL);
    close(pipefd2[1]); // close writing end of second pipe
    // Read string from child, print it and close
    //reading end
    read(pipefd2[0],concat_str,100);
    printf("concatenated string %s\n", concat_str);
    close(pipefd2[0]);
  }// Child process
  else{
     close(pipefd1[1]); // Close writing end of first pipe
     // Read a string using first pipe
     char concat_str[100];
     read(pipefd1[0],concat_str,100);
     //concantenate a fixed string with it
     int k = strlen(concat_str);
     int i;
     for(i=0;i<(int)strlen(fixed_str);i++)
       concat_str[k++] = fixed_str[i];
     concat_str[k] = '\0'; // strings end with '\O'
     //close both reading ends
     close(pipefd1[0]);
     close(pipefd2[0]);
     // write concatenated string and close writing end
     write(pipefd2[1],concat_str,strlen(concat_str)+1);
     close(pipefd2[1]);

     exit(0);
  }


}
