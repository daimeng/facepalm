#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void fold_to(char* s, int n, char* s2, int n2)
{
  int i = 0;
  while (i < n) {
    for (int ii = 0; ii < n2; ii++) {
      s2[ii] ^= s[i % n];
      i++;
    }
  }
}

void nxor(char *s, char *key, int n) {
  for (int i = 0; i < n; i++) {
    s[i] ^= key[i];
  }
}

int main(/*int argc, char **argv*/)
{
  char s[32] = {0};
  char q[] = {121, 111, 117, 114, 32, 102, 105, 114, 115, 116, 32, 110, 97, 109, 101, 0};
  printf("%s: ", q);
  fgets(s, 31, stdin);
  int l = strlen(s);

  char a[] = "  ";
  char b[] = "  ";
  char c[] = "         ";

  fold_to(s, l - 1, a, 2);
  nxor(a, "OC", 2);

  fold_to(s, l - 1, b, 2);
  nxor(b, "@_", 2);

  fold_to(s, l - 1, c, 9);
  nxor(c, "5$/,\"=(- ", 9);

  printf("%s %s %s\n", a, b, c);
  
  printf("%s: ", q);
  fgets(s, 31, stdin);

  char first[] = "   ";
  char second[] = "   ";

  char guess[] = {57,8,63};
  char what[] = {0,15,50};
  fold_to(s, strlen(s) - 1, first, 3);
  nxor(first, guess, 3);

  fold_to(s, strlen(s) - 1, second, 3);
  nxor(second, what, 3);

  printf("%s %s\n", first, second);
  return 0;
}
