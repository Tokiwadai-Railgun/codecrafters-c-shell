#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definitions of commands functions
int echo(char arguments[]);
int exit_function(char arguments[]);

const int commandNumbers = 1;
char *commandsNames[] = { "exit","echo" };
int (*p[]) (char[]) = {exit_function, echo};

int main() {
    // Flush after every printf
    setbuf(stdout, NULL);

    // Wait for user input
    char input[100];

    while (1) {
        printf("$ ");
        fgets(input, 100, stdin);
        input[strlen(input) - 1] = '\0';

        char * token = strtok(input, " ");
        char * arguments = strtok(NULL, "\0");


        int command = 0;
        // Check for commands
        for (int i = 0; i <= commandNumbers; i++) {
            if (strcmp(token, commandsNames[i]) == 0) {
                command = 1;
                int success = (*p[i]) (arguments);
                if (success != 0) {
                    printf("Command failed with exit status : %i\n", success);
                }
                continue;
            }
        }
    
        if (command == 1) { continue; };

        printf("%s: command not found\n", input);
    }
    return 0;
}

int exit_function(char arguments[]) {
    exit(0);
}

int echo(char arguments[]) {
    printf("%s\n", arguments);
    return 0;
}
