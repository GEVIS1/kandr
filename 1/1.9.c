#include<stdio.h>

main() {
    int c, blank;

    blank = 0;
    
    while ((c = getchar()) != EOF) {
        if (!blank) {
            if (c != ' ') {
                putchar(c);
            }
            if (c == ' ') {
                blank = 1;
            }
        }
        if (blank) {
            if (c != ' ') {
                printf(" %c", c);
                blank = 0;
            }
        }
    }
}