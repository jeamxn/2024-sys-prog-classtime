/*
 file name:
  file_lock.c
 run as:
  ./run file_lock.c
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
  int fd;
  int op;  // Lock_SH, Lock_EX
  if (argc < 2) {
    printf("Usage: %s <file> <lock type>\n", argv[0]);
    return 1;
  }
  if (!strcmp(argv[1], "sh")) {
    op = LOCK_SH;
  } else if (!strcmp(argv[1], "ex")) {
    op = LOCK_EX;
  } else {
    printf("Usage: %s <file> <lock type | sh or ex>\n", argv[0]);
    return 1;
  }
  if ((fd = open("hello", O_RDONLY)) < 0) {
    perror("open() error");
    return 1;
  }
  printf("trying to grab file lock...\n");

  if (flock(fd, op) < 0) {
    perror("flock() error");
    close(fd);
    return 1;
  }
  printf("grabbed the lock!!\n");
  getc(stdin);

  if (flock(fd, LOCK_UN) < 0) {
    perror("flock() error");
    close(fd);
    return 1;
  }
  close(fd);

  return 0;
}
