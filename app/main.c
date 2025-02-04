#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  // Flush after every printf
  setbuf(stdout, NULL);

  // Uncomment this block to pass the first stage

  // Wait for user input
  char input[100];

  while (1) {
    printf("$ ");
    fgets(input, 100, stdin);
    input[strlen(input) - 1] = '\0';

    char * token = strtok(input, " ");
    char * arguments = strtok(NULL, "\0");

    if (strcmp(token, "echo") == 0) {
      printf("%s\n", arguments);
    } else if (strcmp(token, "exit") == 0) {
      exit(0);
    } else {
      printf("%s: command not found\n", input);
    }


  }


  return 0;
}
