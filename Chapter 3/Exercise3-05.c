#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
    int number, b;     /* to test the program */
    char s[MAXLINE];
    
    number = -2093;
    b = 16;
    
    itob(number, s, b);
    printf("The integer %d, is converted to string: %s. \n", number, s);
    printf("%s in base %d \n", s, b);

    return 0;
}

void itob(int n, char s[], int b)
{
    int i, sign, r;
    
    if ((sign = n) < 0);   /* record sign */
        n = -n;
    
    i = 0;
    do {        /* generate digits in reverse order */
        r = n % b;
        s[i++] = (r > 9 ? (r + 'A' - 10) : (r + '0'));  /* get next digit */
    } while (n /= b);    /* delete it */
    if (sign < 0)
        s[i++] = '-';
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
