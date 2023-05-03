#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

int main(int argc, char **argv, char **envp) {
    while (1) {
        printf("simple_shell> ");

        char *input = NULL;
        size_t input_len = 0;
        ssize_t read_len = getline(&input, &input_len, stdin);

        if (read_len == -1) {
            // Handle end of file condition or error
            printf("\n");
            free(input);
            exit(0);
        }

        // Remove trailing newline character from input
        input[strcspn(input, "\n")] = '\0';

        pid_t pid = fork();
        if (pid < 0) {
            // Handle fork error
            perror("fork");
            free(input);
            continue;
        } else if (pid == 0) {
            // Child process
            char *args[] = {input, NULL};
            if (execve(input, args, envp) == -1) {
                // If we get here, the execve call failed
                perror("execve");
                free(input);
                exit(1);
            }
        } else {
            // Parent process
            int status;
            if (waitpid(pid, &status, 0) == -1) {
                // Handle waitpid error
                perror("waitpid");
                free(input);
                continue;
            }
        }

        free(input);
    }

    return 0;
}
