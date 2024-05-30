/*
 file name:
  file_pos_low.c
 run as:
  ./run file_pos_low.c
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

static int write_text_to_file(const char *filename, const char *text) {
  int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd == -1) {
    perror("Error opening file for writing");
    return 1;
  }
  printf("offset1: %ld\n", lseek(fd, 0, SEEK_CUR));
  ssize_t res = write(fd, text, strlen(text));
  printf("offset2: %ld\n", lseek(fd, 0, SEEK_CUR));
  close(fd);
  if (res == -1) {
    perror("Error writing to file");
    return 1;
  }
  return 0;
}

static char *read_text_from_file(const char *filename) {
  int fd = open(filename, O_RDONLY);
  if (fd == -1) {
    perror("Error opening file for reading");
    return NULL;
  }
  printf("offset1: %ld\n", lseek(fd, 0, SEEK_CUR));
  char *text = malloc(1000);
  printf("offset2: %ld\n", lseek(fd, 0, SEEK_CUR));
  if (read(fd, text, 1000) == -1) {
    free(text);
    perror("Error reading from file");
    text = NULL;
  }
  printf("offset3: %ld\n", lseek(fd, 0, SEEK_CUR));
  close(fd);
  return text;
}

int main(int argc, char **argv) {
  const char *filename = "data.txt";

  // write
  const char *text = "Hello, World!";
  if (write_text_to_file(filename, text)) {
    perror("Text could not be written to file\n");
    return 1;
  }
  printf("\n");

  // read
  char *read_text = read_text_from_file(filename);
  if (read_text) {
    printf("Read text: %s\n", read_text);
    free(read_text);
  } else {
    perror("Text could not be read from file\n");
  }

  return 0;
}
