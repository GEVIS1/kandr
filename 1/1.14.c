#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

/* Write a program to print a histogram of the frequencies of different
characters in its input. */

#define ASCII_START 0x20
#define ASCII_END 0x7E
#define MAX_CHARACTER_COUNT 10
#define VERTICAL_HIST_HEIGHT 10
#define VERTICAL_CHAR   "|"
#define HORIZONTAL_CHAR "-"
#define ANSI_COLUMN_MOVE_FORWARD  "\033[%dC"
#define ANSI_COLUMN_MOVE_BACKWARD "\033[%dD"
#define ANSI_ROW_MOVE_UP   "\033[%dA"
#define ANSI_ROW_MOVE_DOWN "\033[%dB"

main() {
    int character_count_size = ASCII_END - ASCII_START;
    int cc[character_count_size];
    char cv[character_count_size];
    char c;
    int i;

    printf("Paste or write some text then send EOL/^Z:\n");

    for (i = 0; i < character_count_size; ++i) {
        cc[i] = 0;
        cv[i] = 0;
    }
  
    int charsinput = 0;
    while ((c = getchar()) != EOF) {
        if (ASCII_START <= c && c <= ASCII_END) {
            int ci = c - ASCII_START;
            cv[ci] = c;
            cc[ci]++;
            charsinput++;
        }
    }

    if (charsinput < MAX_CHARACTER_COUNT) {
        fprintf(stderr, "Error: Not enough characters input. Exiting.\n");
        return -1;
    }
   
    int sorted = 0;
    while (!sorted) {
        int max = INT_MIN;
        int swaps = 0;
        for (i = 0; i < character_count_size - 1; ++i) {
            int a = i;
            int b = i + 1;
            if (cc[a] > cc[b]) {
                int count = cc[a];
                char chr = cv[a];
                cc[a] = cc[b];
                cv[a] = cv[b];
                cc[b] = count;
                cv[b] = chr;
                swaps++;
            }
        }
        if (swaps == 0) {
            sorted = 1;
        }
    }

    printf("Horizontal character counts:\n");
    int j;
    for (i = character_count_size - 1; i > character_count_size - 11; --i) {
        int spot = abs(i - character_count_size);
        printf("%d char: %c ", spot, cv[i]);
        for (j = 0; j < cc[i]; ++j) {
            printf(HORIZONTAL_CHAR);
        }
        putchar('\n');
    
    }

    printf("\nVertical character counts:\n");
    for (i = 0; i < VERTICAL_HIST_HEIGHT; i++) 
        printf("\n");
        
    for (i = character_count_size - 1; i > character_count_size - 11; --i) {
        printf(ANSI_COLUMN_MOVE_FORWARD, 3);
        printf("%c", cv[i]);
        printf(ANSI_COLUMN_MOVE_BACKWARD, 1);
        printf(ANSI_ROW_MOVE_UP, VERTICAL_HIST_HEIGHT);
        for (j = VERTICAL_HIST_HEIGHT; j > 0; --j) {
            if (cc[i] >= j) {
                printf(VERTICAL_CHAR);
                printf(ANSI_COLUMN_MOVE_BACKWARD, 1);
            }
            printf(ANSI_ROW_MOVE_DOWN, 1);
        }
    }
}