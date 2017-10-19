#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, d, sing;
    
    while (isspace(c = getch()))    /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); /* it's not a number */
        return 0;
    }
    sing = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        d = c;
    if (!isdigit(c = getch())) {
        if (c != EOF)
            ungetch(c);     /* [ush back non-digit */
        ungetch(c);         /* push back sign char */
        return d;
    }
    
    for (*pn = 0 ; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}
