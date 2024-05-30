/*
 file name:
  file_stat.c
 run as:
  ./run file_stat.c
*/

#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char **argv) {
  struct stat statbuf;
  if (argc < 2) {
    dprintf(STDOUT_FILENO, "Usage: %s <file>\n", argv[0]);
    return 1;
  }

  // if (stat(argv[1], &statbuf)) {
  if (lstat(argv[1], &statbuf)) {
    dprintf(STDOUT_FILENO, "error no: %d\n", errno);
    perror("Error getting file status");
    return 1;
  }

  dprintf(STDOUT_FILENO, "File: %s\n", argv[1]);
  dprintf(STDOUT_FILENO, "Size: %ld\n", statbuf.st_size);
  dprintf(STDOUT_FILENO, "Blocks: %ld\n", statbuf.st_blocks);
  dprintf(STDOUT_FILENO, "Inode: %ld\n", statbuf.st_ino);
  dprintf(STDOUT_FILENO, "Links: %d\n", statbuf.st_nlink);
  dprintf(STDOUT_FILENO, "UID: %d\n", statbuf.st_uid);
  dprintf(STDOUT_FILENO, "GID: %d\n", statbuf.st_gid);
  dprintf(STDOUT_FILENO, "Mode: %o\n", statbuf.st_mode);
  dprintf(STDOUT_FILENO, "Access time: %ld\n", statbuf.st_atime);
  dprintf(STDOUT_FILENO, "Modification time: %ld\n", statbuf.st_mtime);
  dprintf(STDOUT_FILENO, "Change time: %ld\n", statbuf.st_ctime);

  if (S_ISDIR(statbuf.st_mode))
    dprintf(STDOUT_FILENO, "Type: Directory\n");
  else if (S_ISREG(statbuf.st_mode))
    dprintf(STDOUT_FILENO, "Type: Regular file\n");
  else if (S_ISLNK(statbuf.st_mode))
    dprintf(STDOUT_FILENO, "Type: Symbolic link\n");
  else if (S_ISCHR(statbuf.st_mode))
    dprintf(STDOUT_FILENO, "Type: Character device\n");
  else if (S_ISBLK(statbuf.st_mode))
    dprintf(STDOUT_FILENO, "Type: Block device\n");
  else if (S_ISFIFO(statbuf.st_mode))
    dprintf(STDOUT_FILENO, "Type: FIFO\n");
  else if (S_ISSOCK(statbuf.st_mode))
    dprintf(STDOUT_FILENO, "Type: Socket\n");
  else
    dprintf(STDOUT_FILENO, "Type: Unknown\n");

  return 0;
}
