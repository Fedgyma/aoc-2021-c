#include "aoc.h"

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int prev_measurement;
  int curr_measurement;
  int measurement_that_are_larger_that_the_prev_measurement_count = 0;

  open_file("input_first_part");

  getline_from_file();
  prev_measurement = atoi(lineptr);
  printf("%d (N/A - no previous measurement)\n", atoi(lineptr));

  while ((getline_from_file()) != -1) {
    curr_measurement = atoi(lineptr);
    if (curr_measurement > prev_measurement)
      measurement_that_are_larger_that_the_prev_measurement_count++;
      printf("%d (increased)\n", atoi(lineptr));
    if (curr_measurement < prev_measurement)
      printf("%d (decreased)\n", atoi(lineptr));
    prev_measurement = curr_measurement;
  }

  clean();
  
  printf("%d measurements are larger than the previous measurement\n", measurement_that_are_larger_that_the_prev_measurement_count);

  return EXIT_SUCCESS;
}
