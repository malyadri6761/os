#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int f[2];

    if (pipe(f) == -1) {
        perror("Pipe creation failed. ");
        exit(EXIT_FAILURE);
    }

    if ((pid = fork()) == -1) {
        perror("Fork not created. ");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        close(f[0]);
        dup2(f[1], STDOUT_FILENO);
        close(f[1]);

        execlp("history", "history", NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    } else {
        close(f[1]);
        dup2(f[0], STDIN_FILENO);
        close(f[0]);

        execlp("grep", "grep", ".c", NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    return 0;
}
