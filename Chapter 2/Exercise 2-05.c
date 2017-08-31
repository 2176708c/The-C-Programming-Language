#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int maxline);
int any(char s1[], char s2[]);

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
    
    printf("The first location is at: %d\n", any(s1, s2));

    return 0;

}

int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    s[i] = '\0';

    return i;
}

int any(char s1[], char s2[])
{
    int i, j;
    for (i = 0; s2[i] != '\0'; ++i){
        for (j = 0; s1[j] != '\0'; ++j){
            if (s1[j] == s2[i]){ /* check if s2[i] is in s1*/
                return j;
            }
        }
    }
    return -1;
}