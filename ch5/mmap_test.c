/*
 file name:
  mmap_test.c
 run as:
  ./run mmap_test.c
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int fd;
  if ((fd = open(argv[1], O_RDONLY)) == -1) {
    perror("Error opening file");
    return 1;
  }

  struct stat statbuf;
  if (fstat(fd, &statbuf) < 0) {
    perror("Error getting file status");
    close(fd);
    return 1;
  }

  printf("size: %ld\n", statbuf.st_size);
  printf("page size: %ld\n", sysconf(_SC_PAGESIZE));

  char *file = NULL;
  file = (char *)mmap(0, statbuf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
  if (file == MAP_FAILED) {
    perror("Error mapping file");
    close(fd);
    return 1;
  }
  printf("%s", file);
  printf("%s", file + 3);

  if (munmap(file, statbuf.st_size) == -1) {
    perror("Error unmapping file");
    close(fd);
    return 1;
  }
  close(fd);

  return 0;
}
