/*
file name:
  thread_join.c
run as:
  ./run thread_join.c
*/

#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/file.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define MAX_TRY 1000000

int shared = 0;

void *child_thread_main(void *arg) {
  pthread_t tid = pthread_self();
  printf("child thread id: %ld\n", tid);

  for (int i = 0; i < MAX_TRY; i++) {
    shared++;
  }
  for (int i = 0; i < MAX_TRY; i++) {
    shared--;
  }

  printf("[%s] child thread exiting\n", (char *)arg);
  return NULL;
}

int main(int argc, char **argv) {
  pthread_t child_thread[2];
  printf("main thread id: %ld\n", pthread_self());
  int ret =
      pthread_create(&child_thread[0], NULL, child_thread_main, "runner1");
  if (ret != 0) {
    perror("Error: pthread_create() <1> failed: \n");
    exit(1);
  }
  int ret2 =
      pthread_create(&child_thread[1], NULL, child_thread_main, "runner2");
  if (ret2 != 0) {
    perror("Error: pthread_create() <2> failed: \n");
    exit(1);
  }

  // wait for child threads to finish
  pthread_join(child_thread[0], NULL);
  pthread_join(child_thread[1], NULL);

  printf("shared: %d\n", shared);

  printf("main thread ended!!!\n");
  return 0;
}
