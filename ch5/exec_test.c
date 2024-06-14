/*
file name:
  exec_test.c
run as:
  ./run exec_test.c
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

int main(int argc, char **argv) {
  // asdf
  printf("exec_test.c pid: %d\n", getpid());
  execl("./exec_test2", "exec_test2", "hello", "world", NULL);
  printf("bye!!\n");
  return 0;
}
