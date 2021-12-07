#include "aoc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{

  int h_pos;
  int depth;
  int unit;
  char *token;
  const char spacer[2] = " \n";
  int cmp;
  int aim;
  open_file("puzzle_input");

  aim = 0;
  h_pos = 0;
  depth = 0;
  while ((getline_from_file()) != -1)
  {
    token = strtok(lineptr, spacer);
    unit = atoi(strtok(NULL, spacer));

    if ((cmp = strcmp(token, "forward")) == 0)
    {
      h_pos += unit;
      depth += aim * unit;
      continue;
    }

    if ((cmp = strcmp(token, "down")) == 0)
    {
      aim += unit;
      continue;
    }

    if ((cmp = strcmp(token, "up")) == 0)
    {
      aim -= unit;
      continue;
    }
  }

  printf("%d\n", h_pos * depth);
  clean();


  return EXIT_SUCCESS;
}
