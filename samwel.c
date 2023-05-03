#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

void prompt(void)
{
    char my_prompt[] = "#buddies$ ";
    write(STDOUT_FILENO, my_prompt, strlen(my_prompt));
}

void get_line(char **line)
{
    ssize_t characters_read;
    size_t size = 0;

    characters_read = getline(line, &size, stdin);

    if (characters_read < 0)
    {
        printf("\n");
        exit(0);
    }

    (*line)[strcspn(*line, "\n")] = '\0';
}

int main(void)
{
    char **env = environ;
    char *argv[] = {"/bin/bash", NULL};
    pid_t pid;
    int status;

    while (1)
    {
        char *line = NULL;

        prompt();
        get_line(&line);

        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            execve(line, argv, env);
	    perror("sam");
            exit(EXIT_FAILURE);
        }
        else
        {
            waitpid(pid, &status, 0);
        }

        free(line);
    }

    return 0;
}
