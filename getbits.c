/*************************/
/* Matt Hunter CS241.001 */
/* Lab 3: getbits        */
/*************************/

#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>

int xOverflow;            /* Flag to see if x is larger than 32 bits */
unsigned long readUL(void);
unsigned int getbits(unsigned int x, int p, int n);


int main (void)
{
  unsigned int x;   /* from getbits function, K&R 2.9 */
  int p;            /* ditto                          */
  int n;            /* ditto                          */

  while (TRUE) /* Keep looping until EOF in readUL calls exit(0) */
  {
    xOverflow = FALSE;
    x = readUL();
    p = (int) readUL();
    n = (int) readUL();
    
    /* Check various corner cases for error messages */
    if (xOverflow) printf("Error: value out of range\n");
    else if (p > 31) printf("Error: position out of range\n");
    else if (n > 31) printf("Error: number of bits out of range\n");
    else if (n > (p + 1) )
      {
        printf("Error: too many bits requested from position\n");
      }
    else /* Passed error checks, so print result */
      {
        printf("getbits(x=%u, p=%d, n=%d) = %u\n", x, p, n, getbits(x, p, n));
      }
  }
  
  return 0;
}

/* Function to read in characters and turn continuous strings of digits into
 * an unsigned long.  If input greater than 0xFFFFFFFF then set xOverflow
 */
unsigned long readUL(void)
{
  double number = 0;
  char c;
  int stopFlag = FALSE;
  
  while (stopFlag != TRUE)
    {
      c = getchar();

      if (c == EOF) exit(0); /* Read EOF, so exit program immediately */
      else if ( c >= '0' && c <= '9')
        {
          number *= 10;
          number += c - '0';
          if (number > 0xffffffff)
            {
              xOverflow = TRUE;
            }
        }

      /* Something other than a digit read, so stop reading input and return
       * This is more general than checking for ; delimited per spec 
       */
      else stopFlag = TRUE;
    }
  return number;
}

/* getbits:  get n bits from position p (from K&R section 2.9) */
unsigned int getbits(unsigned int x, int p, int n)
{
  return ( x >> (p + 1 - n) ) & ~(~0 << n);
}
