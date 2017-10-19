#include <stdio.h>

int main()
{
    int lastc, c;
    
    for (lastc=0; (c=getchar()) != EOF; lastc=c){
        if(c==' ' && lastc==' ')
            ;
        else putchar(c);
    }
}



