#include<stdio.h>

/* Write a program to print a histogram of the lengths of words in its input. */

#define IN  1
#define OUT 2
#define MAX_WORD_LENGTH 10
#define VERTICAL_HIST_HEIGHT 10
#define VERTICAL_CHAR   "|"
#define HORIZONTAL_CHAR "-"
#define ANSI_COLUMN_MOVE_FORWARD  "\033[%dC"
#define ANSI_COLUMN_MOVE_BACKWARD "\033[%dD"
#define ANSI_ROW_MOVE_UP   "\033[%dA"
#define ANSI_ROW_MOVE_DOWN "\033[%dB"

main() {
    int wl[MAX_WORD_LENGTH];
    char c;
    int cw;
    int cwl;
    int i;

    printf("Paste or write some text then send EOL/^Z:\n");

    cwl = 0;
    cw = OUT;
    for (i = 0; i < MAX_WORD_LENGTH; ++i)
        wl[i] = 0;
  
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            cw = OUT;
        } else {
            cw = IN;
            cwl++;
        }

        if (cw == OUT) {
            if (cwl > 0 && cwl < MAX_WORD_LENGTH) {
                wl[cwl]++;
            }
            cwl = 0;
        }
    }

    printf("Horizontal word lengths:\n");
    int j;
    for (i = 1; i < MAX_WORD_LENGTH; ++i) {
        printf("%d char: %4d ", i, wl[i]);
        for (j = 0; j < wl[i]; ++j) {
            printf(HORIZONTAL_CHAR);
        }
        putchar('\n');
    
    }

    printf("\nVertical word lengths:\n");
    for (i = 0; i < VERTICAL_HIST_HEIGHT; i++) 
        printf("\n");
        
    for (i = 1; i < MAX_WORD_LENGTH; ++i) {
        printf(ANSI_COLUMN_MOVE_FORWARD, 3);
        printf("%d", i);
        printf(ANSI_COLUMN_MOVE_BACKWARD, 1);
        printf(ANSI_ROW_MOVE_UP, VERTICAL_HIST_HEIGHT);
        for (j = VERTICAL_HIST_HEIGHT; j > 0; --j) {
            if (wl[i] >= j) {
                printf(VERTICAL_CHAR);
                printf(ANSI_COLUMN_MOVE_BACKWARD, 1);
            }
            printf(ANSI_ROW_MOVE_DOWN, 1);
        }
    }
}