#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int maxline);
void reverse(char rline[]);

/* print the longest input line */
int main(void)
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = getline(line, MAXLINE)) > 0){
        reverse(line);
        printf("%s\n", line);
    }

    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }   
    s[i] = '\0';

    return i;
}

/* reverse: reverses a line and returns it */
void reverse(char rs[])
{
    int i,j;
    char temp;
    
    for (i = 0; rs[i] != '\0'; ++i)
        ;
    --i;
    
    if (rs[i] == '\n')
        --i;
    
    j = 0;
    
    while (j<i)
    {
        temp = rs[j];
        rs[j] = rs[i];
        rs[i] = temp;
        --i;
        ++j;
    }
}
