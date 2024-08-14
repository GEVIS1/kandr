#include <stdio.h>

#define MAXLINE 1000

/* Write a program *detab* that replaces tabs in the input with the proper
number of blanks to space to the next tab stop. Assume a fixed set of tab stops,
say every *n* columns. Should *n* be a variable or a symbolic parameter? */

/* Answer: *n* should be a variable since the amount of blanks to a tab stop
will vary between users and program executions. One would want to be able to use
the program without having to change the symbolic constant in the source file
and recompile just to set a different number of spaces per tab. */



main(/* I would read *n* from stdin but that's not taught at this point */)
{
    int blanks = 4;
    char line[MAXLINE];
    int len;

    while((len = readline(line, MAXLINE)))
    {
        tabtoblank(line, len, 4);
        printf("%s", line);
    }
}

/* getline:  read a line into s, return length of line */
int readline(char s[], int lim)
{
    int i;
    char c;
    for (i=0; i<lim && (c = getchar())!=EOF && c!='\n'; i++)
    {
        s[i] = c;
    }
    
    if (c == '\n')
    {
        s[i++] = '\n';
    }
    s[i] = '\0';

    return i;
}

/* tabtoblank:  takes in a string and its length then changes every tab to n
blanks, then returns the new string length */
int tabtoblank(char s[], int lim, int n)
{
    int i, j, k;
    char ns[MAXLINE];
    for(i=0,j=0; i<lim; i++)
    {
        if (s[i] == '\t')
        {
            for (k=0; k<n; k++)
            {
                ns[j++] = ' ';
            }
        }
        else
        {
            ns[j++] = s[i];
        }
    }

    ns[j] = '\0';

    for (i=0; i<j; i++)
        s[i] = ns[i];

    return j;
}