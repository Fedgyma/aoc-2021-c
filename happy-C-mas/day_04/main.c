#include <stdio.h>

#define NUMS_DRAWN_CAP 27
#define    BOARDS_COUNT 3
#define         ROW_CAP 5
#define      BOARDS_CAP (ROW_CAP * ROW_CAP * BOARDS_COUNT)
#define       COL_COUNT (ROW_CAP * BOARDS_COUNT)

#define  IN 1
#define OUT 0

typedef union {
        int square[ROW_CAP][ROW_CAP];
        int linear[BOARDS_CAP];
} Boards;


void getinputdelim (int *array, int delim)
{
        int c, state;
        int *p = array;

        state = OUT;
        while ((c = getchar()) != delim)
                switch (c) {
                case '0': case '1': case '2': case '3': case '4':
                case '5': case '6': case '7': case '8': case '9':
                        *p *= 10;
                        *p += (c - '0');
                        state = IN;
                        break;
                default:
                        if (state == IN)
                                ++p;
                        state = OUT;
                        break;
                }
}

void dump_nums_drawn(int *nums_drawn)
{
        for (int i = 0; i < NUMS_DRAWN_CAP; ++i)
                printf("%d ", nums_drawn[i]);
        putchar('\n');
}


void dump_boards(Boards boards)
{
        for (int i = 0; i < COL_COUNT; i++) {
                for (int j = 0; j < ROW_CAP; j++)
                        printf("%d ", boards.square[i][j]);
                putchar('\n');
                !((i + 1) % 5) ? putchar('\n') : 0;
        }

}

void part1(Boards boards, int *nums_drawn)
{
        int *p = nums_drawn;
        for (int i = 0; i < COL_COUNT; i++) {
                for (int j = 0; j < ROW_CAP; j++)
                        printf("%d ", boards.square[j][i]);
                putchar('\n');
                !((i + 1) % 5) ? putchar('\n') : 0;
        }

}

int main ()
{
        int nums_drawn[NUMS_DRAWN_CAP] = {0};
        
        Boards boards = {0};
        getinputdelim(nums_drawn, '\n');
        getinputdelim(boards.linear, EOF);
        dump_nums_drawn(nums_drawn);
        part1(boards);
        return 0;
}
