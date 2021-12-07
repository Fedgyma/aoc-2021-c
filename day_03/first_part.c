#include "aoc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main(void)
{
  uint16_t b_gamma_rate = 0;
  uint16_t b_epsilon_rate;
  unsigned short gamma_rate[12] = {0};
  unsigned short data_count = 0;

  open_file("puzzle_input");

  while ((getline_from_file()) != -1)
  {
    data_count++;
    for (int c = 0;c < 12; c++)
    {
        if (lineptr[c] == '1')
          gamma_rate[c]++;
    }
  }

  for (int b = 0;b < 12; b++) {
      b_gamma_rate = b_gamma_rate * 2 + (*(gamma_rate+b) > (data_count / 2));
  }

  b_epsilon_rate = 0x0fff & ~b_gamma_rate;

  printf("%u\n", b_gamma_rate * b_epsilon_rate);

  clean();


  return EXIT_SUCCESS;
}
