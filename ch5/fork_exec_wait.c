/*
file name:
  fork_exec_wait.c
run as:
  ./run fork_exec_wait.c
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/file.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void print_pid(int x) {
  printf("parent pid: %d, current pid: %d, x: %d\n", getppid(), getpid(), x);
}

int main(int argc, char **argv) {
  int x = 0;
  pid_t pid;
  int exit_status;

  pid = fork();
  printf("after fork pid: %d\n", pid);

  if (pid > 0) {
    x = 1;
    printf("I'm parent process.\n");
    print_pid(x);
  } else if (pid == 0) {
    x = 2;
    printf("I'm child process.\n");
    print_pid(x);

    char *args[] = {"exec_test2", "Hello", "World", NULL};
    execv("./exec_test", args);
  } else {
    printf("fork failed\n");
    return 1;
  }

  pid = wait(&exit_status);  // wait for child process to finish

  if (WIFEXITED(exit_status)) {
    printf("child pid: %d\n", pid);
    printf("child process exited with status: %d\n", WEXITSTATUS(exit_status));
  } else {
    printf("child process exited abnormally\n");
  }

  if (WIFSIGNALED(exit_status)) {
    printf("child pid: %d\n", pid);
    printf("child process was terminated by signal: %d\n",
           WTERMSIG(exit_status));
  }

  return 0;
}
