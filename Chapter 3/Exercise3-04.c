#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
    int number;     /* to test the program */
    char s[MAXLINE];
    
    number = -2093;
    
    itoa(number, s);
    printf("The integer %d, is converted to string %s. \n", number, s);

    return 0;
}

void itoa(int n, char s[])
{
    int i, sign;
    
    sign = n;   /* store sign */
    
    i = 0;
    do {        /* generate digits in reverse order */
        s[i++] = ((sign < 0) ? -(n % 10) : (n % 10)) + '0';  /* get next digit */
    } while (n /= 10);    /* delete it */
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