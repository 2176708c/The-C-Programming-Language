#include <stdio.h>

#define MAX_LENGTH 15
#define IN 1
#define OUT 0

int main()
{
    int c, state;
    int word_length[MAX_LENGTH + 1];
    int l;
    int i, j;
    unsigned int max_count;

    for (i = 0; i <= MAX_LENGTH; ++i)
        word_length[i] = 0;

    state = OUT;
    while ((c=getchar()) != EOF) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (state == OUT) {
                l = 0;
                state = IN;
            }
            ++l;
        } else {
            if (state == IN) {
                if (l <= MAX_LENGTH)
                    ++word_length[l - 1];
                else
                    ++word_length[MAX_LENGTH];
                state = OUT;
            }
        }
    }

    printf(" length | graph\n");
    for (i = 0; i <= MAX_LENGTH; ++i) {
        if (i != MAX_LENGTH)
            printf("     %2d | ", i + 1);
        else
            printf("    >%2d | ", MAX_LENGTH);
        for (j = 0; j < word_length[i]; ++j)
            putchar('+');
        putchar('\n');
    }

    printf(" ------");
    for (i = 0; i <= MAX_LENGTH; ++i)
        printf("---");
    printf("--\n");

    printf("       ");
    for (i = 0; i < MAX_LENGTH;)
        printf(" %2u", ++i);
    printf(" >%2u", MAX_LENGTH);
    printf("\n");

}