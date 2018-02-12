#include <stdio.h>

float srednia(int* pocz, int* kon)
{
  float suma = 0;
  int waga = 0;
  for (int i = 0; i < (kon - pocz); i++)
  {
    suma += (*(pocz+i)*i);
    waga += i;

  return suma / waga;
}

int main()
{
  int tab[]={3,5,6,3,4,5,1,2,4,7,6};

  int rozmiar = (sizeof(tab) / sizeof(tab[0]));
  float avg = srednia(tab, tab + rozmiar);
  printf("%f",avg);
  return 0;
}
