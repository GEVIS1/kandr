#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */
#define MAXLINES 100    /* maximum input lines stored */
#define MINLINE 80      /* minimum input line size */

/* Write a program to print all input lines that are longer than 80 characters. 
*/

int main()
{
    int len;            /* current line length */
    int count;          /* number of lines found */
    char line[MAXLINE];     /* current line stored here */
    char lines[MAXLINES][MAXLINE];     /* all lines longer than MINLINE */

    count = 0;
    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (len > MINLINE) {
            copy(lines, line, count++);
        }
    }

    int i;
    for (i=0; i < count; ++i)
    {
        printf("%s", lines[i]);
    }

    return 0;
}

/* getline:  read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy:  copy 'from' into 'to'; assume to is big enough */
void copy(char to[][MAXLINE], char from[], int index)
{
        int i;

        i = 0;
        while ((to[index][i] = from[i]) != '\0')
            ++i;
}

// /* initarray: initialize the array for storing the lines */
// void initarray(char arr[][], int len)
// {
//     for (i=0; i<len-1; ++i)
//     {
//         arr[i][j] =
//     }
// }