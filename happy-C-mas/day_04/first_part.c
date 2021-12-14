#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


#define ROW_LENGTH 5
#define _ROW (ROW_LENGTH * ROW_LENGTH)
#define row_sz ((_ROW) * sizeof(uint16_t))

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

  n_char_read = getline(&lineptr, &n, fp);

  size_t cma_cnt = 0;
  for(int i = 0; i < n_char_read; i++)
    {
      if (*(lineptr + i) == ',')
        cma_cnt++;
    }

  char *s = ",";
  cma_cnt++;

  int32_t *nums = calloc(cma_cnt, sizeof(int32_t));

  char *token;

  token = strtok(lineptr, s);

  // feed *nums with integers separated by commas in line 1;
  for(size_t i = 0;(token != NULL) && (i < cma_cnt); i++)
    {
      *(nums + i) = atoi(token);
      token = strtok(NULL, s);
    }

  s = " ";

  int32_t *boards = malloc(25 * sizeof(int32_t));
  int32_t *tmp_boards = NULL;
  memset(boards, 0, 25 * sizeof(int32_t));

  // get rid of the first empty line;
  n_char_read = getline(&lineptr, &n, fp);

  size_t boards_sz;
  for (boards_sz = 0;(n_char_read = getline(&lineptr, &n, fp)) != -1;)
    {
      if (n_char_read > 1)
        {

          token = strtok(lineptr, s);

          // feed *boards with integers separated by blanks;
          for(size_t b = 0;(token != NULL); b++)
            {
              *(boards + boards_sz + b) = atoi(token);
              token = strtok(NULL, s);
            }

          boards_sz += 5;

        }

      if (n_char_read == 1) // line is empty so realloc boards;
        {
          tmp_boards = realloc(boards, (boards_sz + 25) * sizeof(int32_t));
          // no memset, every membs get assigned;
          if (tmp_boards == NULL)
            exit(EXIT_FAILURE);
                    
          boards = tmp_boards; 
        }
    }

  fclose(fp);

  if (lineptr)
    free(lineptr);


  printf("boards size: %lu;\n", boards_sz);
  for (size_t c = 0; c < boards_sz;)
    {
      for (int d = 0; d < 5; d++)
        {
          printf("%d ", *(boards + c + d));
        }
      c += 5;

      printf("\n");
      if (c % 25 == 0)
        printf("\n");

    }
  
  if (boards)
    free(boards);

  if (nums)
    free(nums);

  return EXIT_SUCCESS;
}
