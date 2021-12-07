#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
  FILE *fp;
  char *lineptr = NULL;
  size_t n = 0;
  ssize_t n_char_read;

  int h_pos;
  int depth;
  int unit;
  char *token;
  const char spacer[2] = " \n";
  int cmp;

  fp = fopen(PUZZLE_INPUT, "r");
  if (fp == NULL)
  {
    perror("Error could not open " PUZZLE_INPUT);
    exit(EXIT_FAILURE);
  }

  h_pos = 0;
  depth = 0;
  while ((n_char_read = getline(&lineptr, &n, fp)) != -1)
  {
    token = strtok(lineptr, spacer);
    unit = atoi(strtok(NULL, spacer));

    if ((cmp = strcmp(token, "forward")) == 0)
    {
      h_pos += unit;
      continue;
    }

    if ((cmp = strcmp(token, "down")) == 0)
    {
      depth += unit;
      continue;
    }

    if ((cmp = strcmp(token, "up")) == 0)
    {
      depth -= unit;
      continue;
    }
  }

  printf("%d\n", h_pos * depth);
  
  fclose(fp);
  if (lineptr)
  {
    free(lineptr);
  }

  return EXIT_SUCCESS;
}
