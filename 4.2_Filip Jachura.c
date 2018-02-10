#include <stdio.h>

#define ZAKRES_MIN 1
#define ZAKRES_MAX 10

void zgadnij (int n)
{
  printf ("Twoja liczba to: ");
  if (n > 5)
    {
      if (n > 7)
      {
        if (n > 9)
          printf ("10");
        else if (n > 8)
          printf ("9");
        else
          printf ("8");
      }
      else if (n > 6)
        printf ("7");
      else
        printf ("6");
    }
  else if (n > 2)
    {
      if (n > 4)
        printf ("5");
      else if (n > 3)
        printf ("4");
      else
        printf ("3");
    }
  else if (n > 1)
    printf ("2");
  else
    printf ("1");
  printf ("\n");
}

int sprawdz (int n)
{
  while (n < ZAKRES_MIN || n > ZAKRES_MAX)
    {
      printf ("Podaj liczbe z zakresu [%d,%d]: \n",ZAKRES_MIN,ZAKRES_MAX);
      scanf ("%d", &n);
    }
  return n;
}

int main (void)
{
  int n = sprawdz (n);
  zgadnij (n);
  return 0;
}
