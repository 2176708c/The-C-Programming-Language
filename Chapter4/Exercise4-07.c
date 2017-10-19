#include <stdio.h>
#include <string.h>

#define MAXLINE 100

int getch(void);
void ungetch(int);
void ungets(char []);

int main()
{
    char line[MAXLINE];
    int len, c;
    
    while ((len = getline(line, MAXLINE)) == 0)
        ;
    
    ungets(line);
    while ((c = getch()) != EOF)
        putchar(c);
    
    return 0;
}


int getline(char s[], int lim)
{
    int c, i;
    
    for (i = 0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    s[i] = '\0';
    
    return i;
}

#define BUFSIZE 100

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void ungets(char s[])
{
    int i = strlen(s);
    
    while (i > 0)
        ungetch(s[--i]);
}
