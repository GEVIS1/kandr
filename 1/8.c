#include<stdio.h>

main() {
    int c, blank, nl, tab;

    blank = nl = tab = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++blank;
        if (c == '\n')
            ++nl;
        if (c == '\t')
            ++tab;
    }

    printf("%d blank(s), %d new line(s), %d tab(s)", blank, nl, tab);
}