/*************************/
/* Matt Hunter CS241.001 */
/* Lab 3: getbits        */
/*************************/

#include <stdio.h>

unsigned long readUL(void);

int main (void)
{
  unsigned long x; /* from getbits function, K&R 2.9 */
  int p; /* also K&R 2.9 */
  int n; /* ditto */

  x = readUL();
  p = (int) readUL();
  n = (int) readUL();
  
  printf("getbits(x=%lu, p=%d, n=%d) = ???\n", x, p, n);

  return 0;
}

unsigned long readUL(void)
/* Function to read in characters and turn continuous strings of */
/* digits into unsigned long */
{
  unsigned long number = 0;
  char c;
  int stopFlag = 0;
  
  while (stopFlag != 1)
    {
      c = getchar();
      if ( c >= '0' && c <= '9')
        {
          number *= 10;
          number += c - '0';
        }

      /* Something other than a digit read, so stop reading input */
      else stopFlag = 1;
    }
  return number;
}
