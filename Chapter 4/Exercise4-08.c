#include <stdio.h>

int getch(void);
void ungetch(int);

char buf = 0;       /* next free position in buf */

int main()
{
    int c;
    
    c = '*';
    
    ungetch(c);
    
    while ((c = getch()) != EOF)
        putchar(c);
    
    return 0;
}

int getch(void) /* get a (possibly pushed back) character */
{
    int c;
    
    
    if (buf != 0)
        c = buf;
    else
        c = getchar();
    buf = 0;
    return c;
}

void ungetch(int c) /* push a character back into input */
{
    if (bufp != 0)
        printf("ungetch: too many characters\n");
    else
        buf = c;
}
