#ifndef _AOC_H_
#define _AOC_H_

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>

FILE * fp;
char * lineptr = NULL;
size_t n = 0;
ssize_t n_char_read;


#define open_file(file_name) (fp = fopen((file_name), "r"));\
  if (fp == NULL) { exit(EXIT_FAILURE); }

#define getline_from_file() (n_char_read = getline(&lineptr, &n, fp))

#define clean() fclose(fp);\
  if (lineptr)\
    free(lineptr)

#endif
