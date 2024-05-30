/*
 file name:
  file_pos_high.c
 run as:
  ./run file_pos_high.c
*/

#include <stdio.h>
#include <stdlib.h>

static int write_text_to_file(const char *filename, const char *text) {
  FILE *file = fopen(filename, "w");
  if (!file) {
    perror("Error opening file for writing");
    return 1;
  }
  printf("offset1: %ld\n", ftell(file));
  fputs(text, file);
  printf("offset2: %ld\n", ftell(file));
  fclose(file);
  return 0;
}

static char *read_text_from_file(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (!file) {
    perror("Error opening file for reading");
    return NULL;
  }

  printf("offset1: %ld\n", ftell(file));
  char *text = malloc(1000);

  if (fgets(text, 1000, file) == NULL) {
    free(text);
    perror("Error reading from file");
    text = NULL;
  }
  printf("offset2: %ld\n", ftell(file));

  fseek(file, 0, SEEK_END);
  printf("offset3: %ld\n", ftell(file));

  fclose(file);
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
