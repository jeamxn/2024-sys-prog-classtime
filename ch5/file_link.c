/*
 file name:
  file_link.c
 run as:
  ./run file_link.c
*/

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#define _ORIG_SOURCE "hello"

int main(int argc, char **argv) {
  // Hard link
  if (link(_ORIG_SOURCE, "hello_link") == -1) {
    printf("error no: %d\n", errno);
    perror("Error creating hard link");
    return 1;
  }

  // Soft link
  if (symlink(_ORIG_SOURCE, "hello_symlink") == -1) {
    printf("error no: %d\n", errno);
    perror("Error creating soft link");
    return 1;
  }

  return 0;
}
