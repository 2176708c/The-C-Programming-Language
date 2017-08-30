#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int maxline);
int removetrail(char line[]);


/* print the longest input line */
int main(void)
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = getline(line, MAXLINE)) > 0){
        if (removetrail(line) > 0) {
            printf("%s\n", line);
        }
    }

    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
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

/* removetrail: removes trail blanks and tabs */
int removetrail(char s[])
{
    int i;
    
    for (i=0; s[i] != '\n'; ++i)
    ;
    --i; /* To consider raw line without \n */

  for(i >0; ((s[i] == ' ') || (s[i] =='\t'));--i)   
    ; /* Removing the Trailing Blanks and Tab Spaces */

  if( i >= 0) /* Non Empty Line */
  {
    ++i;
    s[i] = '\n';
    ++i;
    s[i] = '\0';
  }
  return i;
}