#include <stdio.h>
#include <stdlib.h>

#define MAXN 92
#define UNKNOWN -1
long f[MAXN + 1];

long fib_c(int n){
  if(f[n] == UNKNOWN){
      f[n] = fib_c(n - 1) + fib_c(n - 2);
    }

  return f[n];
}
long fib_c_driver(int n){
  int i;
  f[0] = 0;
  f[1] = 1;
  for (i = 2; i <= n; i++) {
    f[i] = UNKNOWN;
  }
  return fib_c(n);
}

long fib(int n){
 
  
  if (n <= 1) {
    return n;
  } else {
    return fib(n - 1) + fib(n - 2);
  }
}


int main(int argc, char const *argv[])
{
  printf("with cache %ld\n", fib_c_driver(50));

  return 0;
}
