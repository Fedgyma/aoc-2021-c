#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))

void pbin(const char *s, uint16_t n)
{
  printf("%s ", s);
  for (int i = 4; i > -1; i--)
  {
    
    printf("%u", 0 != CHECK_BIT(n, i));
  }
  printf("\n");
}

int getmostsig12(uint16_t **array, uint16_t *pos, uint16_t *flag, size_t *nmemb, uint16_t *bitmask)
{
  uint16_t most_significant = 0;
  uint16_t *new_array = (uint16_t *)malloc(*nmemb * sizeof(uint16_t)); 
  size_t new_size = 0;

  if (*pos == 0)
  {
    return 0;
  }

 

  *bitmask = *bitmask >> 1;
  *bitmask = *bitmask + (1 << 4);
 


  printf("%u\n", *nmemb);
  
  for(size_t a = 0;a < *nmemb;a++)
  {
    if (*(*array + a) & *pos)
    {
      most_significant += 1;
      if (*nmemb == 2)
      {
        most_significant += 1;
      }
    }
  }

  if(most_significant > (*nmemb / 2))
  {
    *flag = *flag + *pos;
  } 

  for(size_t b = 0;b < *nmemb;b++)
  {
    pbin("flag", *flag);
    pbin("pos", *pos);
    pbin("array", *(*array + b));
    if ((*bitmask & *(*array + b)) == *flag)
    {
      *(new_array + new_size) = *(*array + b);
      new_size += 1;
    }
  }

  *pos = *pos >> 1;
  *nmemb = new_size; 
  free(*array);
  *array = new_array;
  return 1;
}

int main(void)
{
  FILE *fp;
  char *lineptr = NULL;
  size_t n = 0;
  ssize_t n_char_read;
 
  int life_support_rating;
  uint16_t oxygen_generator_rating;
  int co2_scrubber_rating;
  
  int ch;
  size_t line_count;

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

  printf("%u\n", 1 << 4);
  uint16_t flag = 0;
  size_t nmemb = line_count;
  uint16_t bitmask = 0;
  uint16_t pos = 1 << 4;
  while (getmostsig12(&numbers, &pos, &flag, &nmemb, &bitmask)) {}
  oxygen_generator_rating = *numbers;
  /*
  int a;
  int count = line_count;
  int shift = 11;
  int s = 11;
  for (int b = 0x800;b > 0 ;b = b >> 1)
  {
    printf("%u ", (numbers[0] & b) >> s);
    s -= 1;
  }
  printf("\n");


  for (int a = 0x800;a > 0; a = a >> 1)
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
    
    shift -= 1;
  }

  for (int d = 0;d < count;d++)
  {
    if (numbers[d] != ~0)
    {
      printf("%u\n", numbers[d]);
    } 
  } 
 
  if (numbers)
  {
    free(numbers);
  }

  */
  fclose(fp);
  if (lineptr)
  {
    free(lineptr);
  }

  return EXIT_SUCCESS;
}
