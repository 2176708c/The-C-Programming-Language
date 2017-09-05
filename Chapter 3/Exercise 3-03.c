#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int lim);
void expand(char s1[], char s2[]);

int main()
{
    char s1[MAXLINE];
    char s2[MAXLINE];
    
    printf("Please enter some text. \n");
    
    while (getline(s1, MAXLINE) == 0)
        ;
    
    expand(s1, s2);
    printf("Expanded result is: \n%s\n", s2);
    
    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i, l;

    for (i = 0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }   
    s[i] = '\0';

    return i;
}

void expand(char s1[], char s2[])
{
    int i, j;
    char c;
    i = j = 0;
    
    while ((c=s1[i++]) != '\0') {   /* get a character from s1 */
        if (s1[i] == '-' && s1[i+1] >= c){
            i++;
            while (c < s1[i])   /* expand */
                s2[j++] = c++;
        } else {
            s2[j++] = c;
        }
    }
    s2[j] = '\0';
}