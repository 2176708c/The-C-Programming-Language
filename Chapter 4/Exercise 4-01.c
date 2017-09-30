#include <stdio.h>
#define MAXLINE 100 /* maximum input line length */

int getline(char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";    /* pattern to search for */

/* find all lines matching pattern */
int main()
{
    char line[MAXLINE];
    int found = 0 ;
    
    printf("Please enter some text and press Enter. \n\n");
    
    while (getline(line, MAXLINE) > 0)
        printf("The position is: %d \n", strrindex(line, pattern)) ;
    return found;
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

/* strindex: return index of t in s, -1 if none */
int strrindex(char s[], char t[])
{
    int i, j, k;

    i = strlen(s) -1; /* to skip the '\0' character */
    
    while (i >= 0){
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
        --i;
    }
    return -1;
}





