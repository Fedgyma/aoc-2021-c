#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  FILE *fp;
  char *lineptr = NULL;
  size_t n = 0;
  ssize_t n_char_read;

  int window[3];
  int prev_sum;
  int curr_sum;
  int sums_larger_than_the_previous_sum = 0;
  
  fd = fopen(PUZZLE_INPUT, "r");
  if (fd == NULL)
  {
    perror("Error could not open" PUZZLE_INPUT);
    exit(EXIT_FAILURE);
  }

  /* Aknowledge the first window */
  for (int i = 0;i < 3; i++)
  {
    n_char_read = getline(&lineptr, &n, fp);
    window[i] = atoi(lineptr);
  }

  prev_sum = window[0] + window[1] + window[2];
  printf("%d (N/A - no previous measurement)\n", prev_sum);
  window[0] = window[1]; window[1] = window [2]; // a, b, c => b, c, c

  while ((n_char_read = getline(&lineptr, &n, fp)) != -1)
  {
    window[2] = atoi(lineptr);
    curr_sum = window[0] + window[1] + window[2];

    if (curr_sum > prev_sum) {
      sums_larger_than_the_previous_sum++;
      printf("%d (increased)\n", curr_sum);
    }

    if (curr_sum < prev_sum)
      printf("%d (decreased)\n", curr_sum);

    if (curr_sum == prev_sum)
      printf("%d (no change)\n", curr_sum);

    prev_sum = curr_sum;
    window[0] = window[1]; window[1] = window [2];
  }

  fclose(fp);
  if (lineptr)
  {
    free(lineptr);
  }
  printf("%d sums are larger than the previous sum\n", sums_larger_than_the_previous_sum);

  return EXIT_SUCCESS;
}
