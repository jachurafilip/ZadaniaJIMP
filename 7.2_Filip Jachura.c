#include <stdio.h>

void drukuj(char* tekst, int* tab)
{
  printf("Wynik dzialania funkcji printf+scanf: \n");
  int i = 0;
  while(*tekst)
  {
    if(*tekst == '%')
    {
      tekst++;
      if(*tekst == 'd')
      {
        printf("%d", *tab+i);
        tab++;
        tekst++;
      }
      else
      {
        tekst--;
        printf("%c", *tekst);
        tekst++;
      }
    }
    printf("%c", *tekst);
    tekst++;

  }
}

void wpisz(char* tekst)
{
  char* kopia = tekst;
  int a[100];
  int i = 0;
  while(*tekst)
  {
    if(*tekst == '%')
    {
      tekst++;
      if(*tekst == 'd')
      {
        scanf("%d", &a[i]);
        i++;
        tekst++;
      }
      else
      {
        tekst--;
        printf("%c", *tekst);
        tekst++;
      }
    }
    printf("%c", *tekst);
    tekst++;

  }
  printf("\n\n\n");
  drukuj(kopia, a);
}

int main()
{
  wpisz("Dlugosc pierwszego boku: %d\nDlugosc drugiego boku: %d");
  return 0;
}
