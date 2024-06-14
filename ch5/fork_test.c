/*
file name:
  fork_test.c
run as:
  ./run fork_test.c
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/file.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void print_pid(int x) {
  printf("parent pid: %d, current pid: %d, x: %d\n", getppid(), getpid(), x);
}

int main(int argc, char **argv) {
  int x = 0;
  pid_t pid;

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
  } else {
    printf("fork failed\n");
    return 1;
  }
  getc(stdin);  // wait for input (to keep the process running
  return 0;
}
