#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid, wpid;
    int status;

    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        
        printf("Child process: PID = %d\n", getpid());
        sleep(2);
        exit(EXIT_SUCCESS);
    } else {
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), child_pid);
        wpid = wait(&status);
        if (wpid == -1) {
            perror("wait");
            exit(EXIT_FAILURE);
        }
        printf("Child process %d exited with status %d\n", wpid, WEXITSTATUS(status));
        execl("/bin/ls","ls","-l",NULL);
        
    }

    return 0;
}
