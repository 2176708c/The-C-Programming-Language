
#include <stdio.h>
#include <limits.h>
#include <float.h>

int
main (void)
{
  printf ("Range of signed char is from %d to %d.\n", SCHAR_MIN, SCHAR_MAX);
  printf ("Range of unsigned char is from %u to %u.\n\n", 0, UCHAR_MAX);

  printf ("Range of signed short int is from %hd to %hd.\n", SHRT_MIN, SHRT_MAX);
  printf ("Range of unsigned short int is from %hu to %hu.\n\n", 0, USHRT_MAX);

  printf ("Range of signed int is from %d to %d.\n", INT_MIN, INT_MAX);
  printf ("Range of unsigned int is from %u to %u.\n\n", 0, UINT_MAX);

  printf ("Range of signed long int is from %ld to %ld.\n", LONG_MIN, LONG_MAX);
  printf ("Range of unsigned long int is from %lu to %lu.\n\n", 0, ULONG_MAX);
  
  printf("Minimum range of float variable: %.10e\n", FLT_MIN);
  printf("Maximum range of float variable: %.10e\n\n", FLT_MAX);
  printf("Minimum range of double variable: %.10e\n", DBL_MIN);
  printf("Maximum range of double variable: %.10e\n\n", DBL_MAX);
  printf("Minimum range of long double variable: %.10Le\n", LDBL_MIN);
  printf("Maximum range of long double variable: %.10Le\n", LDBL_MAX);


  return 0;
}
