#include <stdio.h>
#include <math.h>

int strlens(char* str);

int main(void)
{
  
  printf("%d\n", strlens("Hello All!!!"));
  return 0;
}
int strlens(char * s)
{
  int n;
  for (n = 0; *s != '\0'; s++)
  {
    printf("this is s: %s\n", s);
    n++;
  }
  return n;
}
