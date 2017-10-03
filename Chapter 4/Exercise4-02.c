#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100 /* maximum input line length */

int getline(char line[], int max);
double atof(char c[]);

int main()
{
    char line[MAXLINE];

    printf("Please enter some floating number and press enter. \n\n");
    
    while (getline(line, MAXLINE) == 0)
        ;
    printf("The number is: %lf \n", atof(line)) ;
    return 0;
}

/* getline: get line into s, return length */
int getline(char s[], int lim)
{
    int c, i;
    
    i =0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if ( c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* atof: convert a string s to double */
double atof(char s[])
{
    double val, power;
    int i, sign, esign, expo, epower;

    for (i=0; isspace(s[i]); i++)   /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    
    if (s[i] == 'e' || s[i] == 'E')\
        i++;
    esign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (expo = 0; isdigit(s[i]); i++){
        expo = 10.0 * expo + (s[i] - '0');
    }
    epower = 1;
    while (expo-- > 0)
            epower *= 10;
    if( esign == -1)
        return sign * (val / power) / epower;
    else
    
        return sign * (val / power) * epower;
}
