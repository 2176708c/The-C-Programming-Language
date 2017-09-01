#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int lim);
void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main()
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */
    char s1[MAXLINE];
    char s2[MAXLINE];
    
    printf("Please enter some text. \n\n");
    
    while ((len = getline(line, MAXLINE)) == 0)
        ;
        
    escape(s1, line);
    printf("Escape function result: \n%s\n", s1);
        
    unescape(s2, s1);
    printf("Unescape function result: \n%s\n", s2);
    

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

void escape(char s[], char t[])
{
    int i, j;
    j = 0;
    
    for (i = 0; t[i] != '\0'; ++i){
        switch (t[i]) { /* all cases from table 2.5.2 in Appendix A */
            case '\n':
                s[j++] =  '\\';
                s[j++] =  'n';
                break;
            case '\t':
                s[j++] =  '\\';
                s[j++] =  't';
                break;
            case '\v':
                s[j++] =  '\\';
                s[j++] =  'v';
                break;
            case '\b':
                s[j++] =  '\\';
                s[j++] =  'b';
                break;
            case '\r':
                s[j++] =  '\\';
                s[j++] =  'r';
                break;
            case '\f':
                s[j++] =  '\\';
                s[j++] =  'f';
                break;
            case '\a':
                s[j++] =  '\\';
                s[j++] =  'a';
                break;
            case '\\':
                s[j++] =  '\\';
                s[j++] =  '\\';
                break;
            case '\?':
                s[j++] =  '\\';
                s[j++] =  '\?';
                break;
            case '\'':
                s[j++] =  '\\';
                s[j++] =  '\'';
                break;
            case '\"':
                s[j++] =  '\\';
                s[j++] =  '\"';
                break;
            default:
                s[j++] =  t[i];
                break;
        }
    }
}

void unescape(char s[], char t[])
{
    int i, j;
    j = 0;
    
    for (i = 0; t[i] != '\0'; ++i){
        if (t[i] == '\\'){
            switch (t[++i]) { /* all cases from table 2.5.2 in Appendix A */
                case 'n':
                    s[j++] =  '\n';
                    break;
                case 't':
                    s[j++] =  '\t';
                    break;
                case 'v':
                    s[j++] =  '\v';
                    break;
                case 'b':
                    s[j++] =  '\b';
                    break;
                case 'r':
                    s[j++] =  '\r';
                    break;
                case 'f':
                    s[j++] =  '\f';
                    break;
                case 'a':
                    s[j++] =  '\a';
                    break;
                case '\\':
                    s[j++] =  '\\';
                    break;
                case '\?':
                    s[j++] =  '\?';
                    break;
                case '\'':
                    s[j++] =  '\'';
                    break;
                case '\"':
                    s[j++] =  '\"';
                    break;
            }
        } else {
                s[j++] =  t[i];
        }
    }
}