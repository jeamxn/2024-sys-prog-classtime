/*
 file name:
  file_binary_high.c
 run as:
  ./run file_binary_high.c
*/

#include <stdio.h>
#include <stdlib.h>

struct person {
  char name[20];
  int age;
};
size_t person_size = sizeof(struct person);

int write_text_to_file(const char *filename, struct person p) {
  FILE *fp = fopen(filename, "wb");
  if (!fp) {
    perror("Error opening file for writing");
    return 1;
  }
  size_t size = fwrite(&p, person_size, 1, fp);
  fclose(fp);
  if (size != 1) {
    perror("Error writing to file");
    return 1;
  }
  return 0;
}

struct person *read_text_from_file(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (!fp) {
    perror("Error opening file for reading");
    return NULL;
  }
  struct person *p = malloc(person_size);
  if (fread(p, person_size, 1, fp) != 1) {
    free(p);
    perror("Error reading from file");
    return NULL;
  }
  fclose(fp);
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