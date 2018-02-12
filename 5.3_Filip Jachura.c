#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **stworzTablice2D(int wiersze, int kolumny)
{
  int ** array = (int **) malloc(kolumny * sizeof(int*));
  for (int i = 0; i < kolumny; i++)
  {
    array[i] = (int *) malloc(wiersze * sizeof(int));
  }
  return array;
}

void zniszczTablice2D(int** tab, int dlugosc)
{
  for (int i = 0; i < dlugosc; i++)
  {
    free(tab[i]);
  }
  free(*tab);
}

void wypelnij (int** macierz, int a, int b)
{
  for (int i =0; i < a; i++)
  {
    for (int j =0; j < b; j++)
    {
      macierz[i][j]=rand()%10;
    }
  }
}
void wypisz(int** macierz, int a, int b)
{
  for (int i =0; i < a; i++)
  {
    for (int j =0; j < b; j++)
    {
      if (macierz [i][j]  <10)
        printf("%d ", macierz[i][j]);
    }
    printf ("\n");
  }
}

int wyznacznik(int** macierz, int a, int b)
{
  int det=0;
  for (int i =0; i < a; i++)
  {
    int iloczynprawy = 1;
    int iloczynlewy = -1;

    for (int j=0; j < b; j++)
    {
      iloczynprawy = iloczynprawy * macierz[(i+j)%3][j];
      iloczynlewy = iloczynlewy * macierz[(i+j)%3][2-j];
    }
    det = det + iloczynlewy + iloczynprawy;
  }
  return det;
}

int main(void)
{
  srand(time(0));
  int wiersze = 3;
  int kolumny = 3;
  int**macierz = stworzTablice2D(wiersze,kolumny);
  wypelnij (macierz,wiersze,kolumny);
  wypisz (macierz,wiersze,kolumny);

  int w= wyznacznik(macierz,wiersze,kolumny);
  printf("Wyznacznik = %d\n", w);
  zniszczTablice2D(macierz,3);
  return 0;
}
