/*
 file name:
  file_text_low.c
 run as:
  ./run file_text_low.c
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int write_text_to_file(const char *filename, const char *text) {
  int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd == -1) {
    perror("Error opening file for writing");
    return 1;
  }
  int res = write(fd, text, strlen(text));
  close(fd);
  if (res == -1) {
    perror("Error writing to file");
    return 1;
  }
  return 0;
}

int append_text_to_file(const char *filename, const char *text) {
  int fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0644);
  if (fd == -1) {
    perror("Error opening file for appending");
    return 1;
  }
  int res = write(fd, text, strlen(text));
  close(fd);
  if (res == -1) {
    perror("Error writing to file");
    return 1;
  }
  return 0;
}

char *read_text_from_file(const char *filename) {
  int fd = open(filename, O_RDONLY);
  if (fd == -1) {
    perror("Error opening file for reading");
    return NULL;
  }
  char *text = malloc(1000);
  if (read(fd, text, 1000) == -1) {
    free(text);
    perror("Error reading from file");
    text = NULL;
  }
  close(fd);
  return text;
}

int main() {
  const char *filename = "file.txt";
  const char *text = "Hello, World!";

  if (write_text_to_file(filename, text)) {
    fprintf(stderr, "Text could not be written to file\n");
    return 1;
  }

  if (append_text_to_file(filename, "\nHello, again!")) {
    fprintf(stderr, "Text could not be written to file\n");
    return 1;
  }

  char *read_text = read_text_from_file(filename);
  if (read_text) {
    printf("Read text: %s\n", read_text);
    free(read_text);
  } else {
    fprintf(stderr, "Text could not be read from file\n");
  }

  return 0;
}
