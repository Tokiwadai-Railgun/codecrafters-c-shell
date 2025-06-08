#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definitions of commands functions
int echo(char arguments[]);
int exit_function(char arguments[]);
int type(char arguments[]);

const int commandNumbers = 3;
char *commandsNames[] = { "exit","echo", "type" };
int (*p[]) (char[]) = {exit_function, echo, type};

int main() {
    // Flush after every printf
    setbuf(stdout, NULL);

    // Wait for user input
    char input[100];

    while (1) {
        printf("$ ");
        fgets(input, 100, stdin);

        if (strlen(input) == 1) { continue; } // 1 because of carriage return char

        input[strlen(input) - 1] = '\0';

        char * token = strtok(input, " ");
        char * arguments = strtok(NULL, "");


        int command = 0;
        // Check for commands
        for (int i = 0; i < commandNumbers; i++) {
            if (strcmp(token, commandsNames[i]) == 0) {
                command = 1;
                int success = (*p[i]) (arguments);
                if (success != 0) {
                    printf("Command failed with exit status : %i\n", success);
                }
                break;
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
    if (arguments == NULL) return 0;
    printf("%s\n", arguments);
    return 0;
}

int type(char arguments[]) {
    if (arguments == NULL) {
        printf("Invalid command\n");
        return 0;
    }
    for (int i = 0; i < commandNumbers; i++) {
        if (strcmp(&arguments[0], commandsNames[i]) == 0) {
            printf("%s is a shell builtin\n", &arguments[0]);
            return 0;
        }
    }

    printf("%s: not found\n", &arguments[0]);
    return 0;
}
