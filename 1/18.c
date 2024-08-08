#include <stdio.h>
#define MAXLINE 1000
#define BLANK ' '
#define TAB '\t'

/* Write a program to remove trailing blanks and tabs from each line of input,
and to delete entirely blank lines. */

main()
{
    int len;
    char line[MAXLINE];

    int i;
    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (line[0] == '\n') {
            continue;
        }
        len = stripend(line, len);
        
        if (len <= 0)
            continue;

        printf("%s", line);
    }
}

/* getline:  read a line into s, return length, negative if EOF was read */
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

    if (c != EOF) {
        return i;
    } else {
        return -i;
    }
}

/* stripend:  remove any blanks or tabs from end of string, return new length */
int stripend(char s[], int lim)
{
    int i;
    int end = lim-1;

    if (s[end] == '\n' && !istaborblank(s, end-1)) {
        return lim;
    }

    for (i=end; i >= 0; --i)
    {
        if (istaborblank(s, i-1))
        {
            s[i] = '\0';
        }
        else
        {
            s[i] = '\n';
            break;
        }
    }

    return i;
}

/* istaborblank:  return 1 if tab or blank found, else 0 */
int istaborblank(char s[], int pos)
{
    return s[pos] == TAB || s[pos] == BLANK;
}
