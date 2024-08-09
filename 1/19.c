#include <stdio.h>
#define MAXLINE 1000

/* Write a function *reverse(s)* that reverses the character string *s*.
Use it to write a program that reverses its input a line at a time. */

main()
{
    char line[MAXLINE];
    int eof;

    while(!(eof = getline(line, MAXLINE)))
    { 
        reverse(line);
        printf("%s", line);
    }
}

/* reverse:  reverses the input string*/
void reverse(char s[])
{
    int end = 0;
    int i = 0;
    char c;

    while(s[end] != '\0')
        end++;

    // move back past null and newline
    end -= 2;

    while(i < end/2 + 1)
    {
        c = s[end-i];
        s[end-i] = s[i];
        s[i] = c;
        i++;
    }
}

/* getline:  read a line into s, return 1 if eof was hit */
int getline(char s[], int lim)
{
    int c, i;
    int eof = 0;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    else if (c == EOF)
    {
        eof = 1;
    }
    s[i] = '\0';

    return eof;
}
