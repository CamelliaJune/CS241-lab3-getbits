/*************************/
/* Matt Hunter CS241.001 */
/* Lab 3: getbits        */
/*************************/

#include <stdio.h>

int main (void)
{
  int c; /* character from standard input */
  int x; /* from getbits function, K&R 2.9 */
  int p; /* also K&R 2.9 */
  int n; /* ditto */

  /* Read in chars until EOF */

  /* Read in x char by char until ';' encountered */
  x = getchar() - '0';
  while ( ( c =getchar() ) != ';' )
    {
      x *= 10;
      x += c - '0';
    }

  /* read in p char by char until ';' encountered */
  p = getchar() - '0';
  while ( ( c = getchar() ) != ';' )
    {
      p *= 10;
      p += c - '0';
    }

  /* read in n char by char until '\n' encountered */
  n = getchar() - '0';
  while ( ( c = getchar() ) != '\n' )
    {
      n *= 10;
      n += c - '0';
    }
  
  printf("getbits(x=%d, p=%d, n=%d)\n", x, p, n);

  return 0;
}
