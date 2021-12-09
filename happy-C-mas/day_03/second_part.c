#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



int main(void)
{
  FILE *fp;
  char *lineptr = NULL;
  size_t n = 0;
  ssize_t n_char_read;
 
  int life_support_rating;
  int goxygen_generator_rating;
  int co2_scrubber_rating;
  
  int ch;
  int line_count;

  fp = fopen(PUZZLE_INPUT, "r");
  if (fp == NULL) 
  {
    perror("Error could not open" PUZZLE_INPUT);
    exit(EXIT_FAILURE);
  }

  line_count = 0;
  size_t capacity = 10;
  uint16_t *numbers = (uint16_t *)malloc(capacity*sizeof(uint16_t));  

  while ((n_char_read = getline(&lineptr, &n, fp)) != -1)
  {    
//    retry_realloc:
    uint16_t *tmp_numbers;
    if (line_count == capacity)
    {
      capacity *= 2;
      tmp_numbers = (uint16_t *) realloc(numbers, capacity*sizeof(uint16_t));
//      if (tmp_numbers == NULL)
//      {
//        goto retry_realloc;
//      }
    }
    
    if (tmp_numbers)
    {
      numbers = tmp_numbers;
    }
//    numbers[line_count] = 1; fuck off


    for (int i = 0;i < 12;i++)
    {
      numbers[line_count] = numbers[line_count] << 1;
      if (lineptr[i] == '1')
      {
        numbers[line_count] += 1;
      }
    }

    line_count += 1;
  }

//  for (int c = 0;c < line_count; c++)
//  {
//    if(numbers[c] != 1)
//    {
//      printf("fuck off\n");
//    }
//  }
  int a;
  int count = line_count;
  int shift = 11;
  for (int a = 4095;a > 0;)
  {
  
    int most_significant = 0;
     
    for (int b = 0;b < count;b++)
    {
      if ((numbers[b] & a) >> shift)
      {
        most_significant += 1;
      }
    }
    most_significant = most_significant > (count / 2);
    for (int c = 0;c < count;c++)
    {
      
      if (!(most_significant == ((numbers[c] & a) >> shift)))
      {
       numbers[c] = ~0;
      }
    } 
    
    a = a >> 1;
    shift -= 1;
  }

  for (int d = 0;d < count;d++)
  {
    if (numbers[d] < ~0)
    {
      //printf("%u\n", numbers[d]);
    } 
  } 
 
  if (numbers)
  {
    free(numbers);
  }

  fclose(fp);
  if (lineptr)
  {
    free(lineptr);
  }

  return EXIT_SUCCESS;
}
