#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Flush after every printf
    setbuf(stdout, NULL);

    // Uncomment this block to pass the first stage

    // Wait for user input
    char input[100];

    char commands[3][10] = {"echo", "type", "exit"};
    char types[3][7] = {"builtin","builtin","builtin"};

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
        } else if (strcmp(token, "type")  == 0) {
            bool found = false;
            for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++) {
                if (strcmp(arguments, commands[i]) == 0) {
                    printf("%s is a shell builtin\n", arguments);
                    found = true;
                    break;
                }
            }
            if (!found) {
                printf("%s: Command not found\n", arguments);
            }
        } else {
            printf("%s: command not found\n", input);
        }
    }

    return 0;
}
