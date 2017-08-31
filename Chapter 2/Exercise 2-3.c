#include <stdio.h>

#define MAXLENGTH 8

int getline(char line[], int maxlength);
int htoi(char s[]);

int main()
{
    int len; /* current line length */
    char line[MAXLENGTH]; /* current input line */

    while ((len = getline(line, MAXLENGTH)) > 0){
        printf("Equivalent integer value is: %d\n\n", htoi(line));
    }

    return 0;

}

int getline(char s[], int lim)
{
    printf("Please input a valid hexadecimal number \n");
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

int htoi(char s[])
{
    int n;
    int i, c, digit;
    
    n = 0;
    for (i = 0; s[i] != '\0'; ++i) {    /*to read the contents of the intput*/
        c = s[i];
        
        if (i == 0 && c == '0' && (s[1] == 'x' || s[1] == 'X')) {
            i = 1;
            continue;
        }
        
        if (s[i] >= '0' && s[i] <= '9')
            digit = s[i] - '0';
        else if (s[i]>='a' && s[i]<='f')
            digit = s[i]-'a'+ 10;
        else if (s[i]>='A' && s[i]<='F')
            digit = s[i]-'A'+ 10;
        else {
            break;
        }
        
        n = (16*n) + digit;
    }
     return n;
}