#define _GNU_SOURCE

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

  FILE *fp;
  char *lineptr = NULL;
  size_t n = 0;
  ssize_t n_char_read;

  int prev_measurement;
  int curr_measurement;
  int measurement_that_are_larger_that_the_prev_measurement_count = 0;

  fp = fopen(PUZZLE_INPUT, "r");
  if (fp == NULL)
  {
    perror("Error opening file " PUZZLE_INPUT);
    exit(EXIT_FAILURE);
  }

  n_char_read = getline(&lineptr, &n, fp);
  prev_measurement = atoi(lineptr);
  printf("%d (N/A - no previous measurement)\n", prev_measurement);

  while ((n_char_read = getline(&lineptr, &n, fp)) != -1) {
    curr_measurement = atoi(lineptr);
    if (curr_measurement > prev_measurement) {
      measurement_that_are_larger_that_the_prev_measurement_count++;
      printf("%d (increased)\n", curr_measurement);
    }

    if (curr_measurement < prev_measurement)
      printf("%d (decreased)\n", curr_measurement);

    prev_measurement = curr_measurement;
  }

  fclose(fp);
  if (lineptr)
  {
    free(lineptr);
  }

  printf("%d measurements are larger than the previous measurement\n",
                measurement_that_are_larger_that_the_prev_measurement_count);

  return EXIT_SUCCESS;
}
