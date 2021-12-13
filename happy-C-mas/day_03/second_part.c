#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
  {
    FILE *fp;
    char *lineptr = NULL;
    size_t n = 0;
    ssize_t n_char_read;

    fp = fopen(PUZZLE_INPUT, "r");
    if (fp == NULL) 
      {
        perror("Error could not open" PUZZLE_INPUT);
        exit(EXIT_FAILURE);
      }

    uint16_t ln_cnt = 1000;
    uint16_t bit_cnt = 12;
    uint16_t *array = (uint16_t *)calloc(ln_cnt, sizeof(uint16_t));  
    uint16_t *rm_array = (uint16_t *)calloc(ln_cnt * 2, sizeof(uint16_t));

    ln_cnt = 0;

    while ((n_char_read = getline(&lineptr, &n, fp)) != -1)
      {
        for (int i = 0; i < bit_cnt; i++)
          {
            *(array + ln_cnt) <<= 1;
            if (*(lineptr + i) == '1')
              {
                *(array + ln_cnt) |= 1;
              }
          }
        ln_cnt++;
      }

    if (lineptr)
        free(lineptr);

    fclose(fp);

    uint16_t current;
    uint16_t co2;  
    uint16_t least;
    size_t l_ones;
    size_t l_zeros;
    uint16_t most;
    size_t m_ones;
    size_t m_zeros;
    size_t n_least = ln_cnt;
    size_t n_most = ln_cnt;
    uint16_t oxygen;  

    for (int i = bit_cnt - 1; i >= 0; i--)
      {
        least = 1;
        l_zeros = 0;
        l_ones = 0;
        l_zeros = 0;
        most = 0;
        m_ones = 0;
        m_zeros = 0;
        for (int b = 0; b < ln_cnt; b++)
          {
            current = 1 & (*(array + b) >> i);
            if (!*(rm_array + b))
              {
                if(current)
                    m_ones++;
                else
                    m_zeros++;
              }
            if (!*(rm_array + b + ln_cnt))
              {
                if(current)
                    l_ones++;
                else
                    l_zeros++;
              }
          }

        if(m_ones >= m_zeros)
            most = 1;
        
        if(l_ones >= l_zeros)
            least = 0;

        for (int c = 0; c < ln_cnt; c++)
          {
            current = 1 & (*(array + c) >> i);

            if (n_most > 1)
              {
                if (!*(rm_array + c))
                  {
                    if (current != most)
                      {
                        *(rm_array + c) = 1;
                        n_most--;
                      }
                    else
                      {
                        oxygen = *(array + c);
                      }
                  }
              }

            if (n_least > 1)
              {
                if (!*(rm_array + c + ln_cnt))
                  {
                    if (current != least)
                      {
                        *(rm_array + c + ln_cnt) = 1;
                        n_least--;
                      }
                    else
                      {
                        co2 = *(array + c);
                      }
                  }
              }
          }
      }
   

    if (array)
        free(array);

    if (rm_array)
        free(rm_array);

    printf("%u\n", oxygen * co2);

    return EXIT_SUCCESS;
  }
