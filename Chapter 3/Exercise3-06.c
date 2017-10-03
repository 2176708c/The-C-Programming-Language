#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

void itoa(int n, char s[], int w);
void reverse(char s[]);

int main()
{
    int number, w;     /* to test the program */
    char s[MAXLINE];
    
    number = -2093;
    w = 10;
    
    itoa(number, s, w);
    printf("The integer %d, is converted to string: \n", number);
    printf("%s with minimum field width %d. \n", s, w);
    return 0;
}

void itoa(int n, char s[], int w)
{
    int i, sign;
    
    if ((sign = n) < 0);   /* record sign */
        n = -n;
    
    i = 0;
    do {        /* generate digits in reverse order */
        s[i++] = n % 10 +'0';  /* get next digit */
    } while ((n /= 10) > 0);    /* delete it */
    if (sign < 0)
        s[i++] = '-';
    
    while (i < w)
        s[i++] = ' ';

    s[i] = '\0';
    reverse(s);
}

/* reverse: reverses a line and returns it */
void reverse(char s[])
{
    int i,j;
    int temp;
    
    for (i = 0; s[i] != '\0'; ++i)
        ;
    --i;
    
    for (j = 0; j < i; ++j, --i){
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
    }
}