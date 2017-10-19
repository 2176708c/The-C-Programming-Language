#include <stdio.h>
#include <time.h>

int binsearch_old(int x, int v[], int n);
int binsearch_new(int x, int v[], int n);

int main(void)
{
    int x = 9, n = 11;
    int v[11] = {1, 2, 3, 4, 9, 11, 13, 15, 17, 20, 33};
    
    clock_t begin_old = clock();
    printf("Match at position: %d\n", binsearch_old(x, v, n));
    clock_t end_old = clock();
    unsigned long time_spent_old = (unsigned long)(end_old - begin_old);
    printf("Run-time for binsearch_old %lu clocks\n\n", time_spent_old);
    
    clock_t begin_new = clock();
    printf("Match at position: %d\n", binsearch_new(x, v, n));
    clock_t end_new = clock();
    unsigned long time_spent_new = (unsigned long)(end_new - begin_new);
    printf("Run-time for binsearch_new %lu clocks\n\n", time_spent_new);
    
    unsigned long time_diff = time_spent_old - time_spent_new;
    printf("Difference in run-time is %lu clocks\n", time_diff);
    
    return 0;
}

/* binarysearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch_old(int x, int v[], int n)
{
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    while  (low <= high){
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if ( x > v[mid])
            low = mid + 1;
        else    /* found match */
            return mid;
    }
    return -1;  /* no match */
}

int binsearch_new(int x, int v[], int n)
{
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    while  (low <= high){
        mid = (low + high) / 2;
        if (x <= v[mid])
            high = mid - 1;
        else
            low = mid + 1;

    }
    return (x == v[low]) ? low : -1;
}