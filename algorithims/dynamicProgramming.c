#include <stdio.h>
#include <stdlib.h>

#define MAXN 92
#define UNKNOWN -1
long f[MAXN + 1];

long fib_ultimate(int n){
  int i;
  long back2 = 0, back1 = 1;
  long next;

  if (n == 0) {
    return 0;
  }

  for (i = 2; i <= n; i++) {
    next = back1 + back2;
    back2 = back1;
    back1 = next;
  }
  return back1;
}

long fib_dp(int n){
  int i;
  f[0] = 0;  /* counter */
  f[1] = 1;  /* array for caching values */

  for (i = 2; i <= n; i++) {
    f[i] = f[i - 1] + f[i - 2];
  }
  return f[n];
}

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
  printf("with cache %ld\n", fib_ultimate(920));

  return 0;
}
