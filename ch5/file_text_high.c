#include <stdio.h>
#include <stdlib.h>

int write_text_to_file(const char *filename, const char *text) {
  FILE *file = fopen(filename, "w");
  if (!file) {
    perror("Error opening file for writing");
    return 1;
  }
  fputs(text, file);
  fclose(file);
  return 0;
}

char *read_text_from_file(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (!file) {
    perror("Error opening file for reading");
    return NULL;
  }
  char *text = malloc(1000);
  if (fgets(text, 1000, file) == NULL) {
    free(text);
    perror("Error reading from file");
    text = NULL;
  }
  fclose(file);
  return text;
}

int main() {
  const char *filename = "file.txt";
  const char *text = "Hello, World!";

  if (write_text_to_file(filename, text)) {
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
