#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int maxline);
void squeeze(char s1[], char s2[]);

int main()
{
    int len; /* current line length */
    char s1[MAXLINE];
    char s2[MAXLINE];
    
    printf("Input string s1:\n");
    while ((len = getline(s1, MAXLINE)) == 0)
        ;

    printf("Input string s2:\n");
    while ((len = getline(s2, MAXLINE)) == 0)
        ;
    
    squeeze(s1, s2);
    printf("The result is: %s\n", s1);

    return 0;

}

int getline(char s[], int lim)
{
    int c, i, l;

    for (i = 0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i++] = c;
    }   
    s[i] = '\0';

    return i;
}

void squeeze(char s1[], char s2[])
{
    int i, j, k;
    for (i = 0; s2[i] != '\0'; i++){
        for (j = k = 0; s1[j] != '\0'; j++)
            if (s1[j] != s2[i]) /* check if s2[i] is in s1*/
                s1[k++] = s1[j];
        s1[k] = '\0';
    }
}