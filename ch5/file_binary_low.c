/*
 file name:
  file_binary_low.c
 run as:
  ./run file_binary_low.c
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

struct person {
  char name[20];
  int age;
};
size_t person_size = sizeof(struct person);

int write_text_to_file(const char *filename, struct person p) {
  int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd == -1) {
    perror("Error opening file for writing");
    return 1;
  }
  ssize_t res = write(fd, &p, person_size);
  close(fd);
  if (res != person_size) {
    perror("Error writing to file");
    return 1;
  }
  return 0;
}

struct person *read_text_from_file(const char *filename) {
  int fd = open(filename, O_RDONLY);
  if (fd == -1) {
    perror("Error opening file for reading");
    return NULL;
  }
  struct person *p = malloc(person_size);
  if (read(fd, p, person_size) != person_size) {
    free(p);
    perror("Error reading from file");
    close(fd);
    return NULL;
  }
  close(fd);
  return p;
}

int main(int argc, char **argv) {
  const char *filename = "person.dat";
  struct person p = {.name = "IU", .age = 31};

  if (write_text_to_file(filename, p)) {
    fprintf(stderr, "Binary Text could not be written to file\n");
    return 1;
  }

  struct person *read_text = read_text_from_file(filename);
  if (read_text) {
    printf("Read struct: %s %d\n", read_text->name, read_text->age);
    free(read_text);
  } else {
    fprintf(stderr, "Binary Text could not be read from file\n");
  }

  return 0;
}
