#include <stdio.h>

void getchars(int c);
void incomment(void);
void inquotes(int c);

int main()
{
    int c, i;
    printf("Enter some C code. \n");
    
    while ((c=getchar()) != EOF){
        getchars(c);
    }  
    return 0;
}

void getchars(int c)
{
    int d;
    
    if (c == '/')   /* check if it starts as a comment */
    {
        if ((d = getchar()) == '*')   /* check if it is a comment */
        {
            incomment();
        }
        else if ( d == '/')     /* maybe the comment starts here */
        {
            putchar(c);
            getchars(d);
        }
        else        /* not a comment for sure */
        {
            putchar(c);
            putchar(d);
        }
    }
    else if (c == '"' || c == '\'')  /* check if it is in quotes */
        inquotes(c);
    else    /* all other characters */
        putchar(c);
        
    return 0;
}

void incomment()
{
    int c, d;
    
    c = getchar();
    d = getchar();
    while (c != '*' && d != '/')
    {

        c = d;
        d = getchar();
    }
    
    return 0;
}

void inquotes(c)
{
    int d;
    putchar(c);
    
    while((d=getchar()) != c)
    {
        putchar(d);
        if(d = '\\')
            putchar(getchar());
    }
    putchar(d);
    
    return 0;
}