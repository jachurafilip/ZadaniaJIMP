#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wypelnij (int macierz [3][3])
{
  for (int i =0; i<3; i++)
  {
    for (int j =0; j<3; j++)
    {
      macierz[i][j]=rand()%10;
    }
  }
}
void wypisz(int macierz[3][3])
{
  for (int i =0; i<3; i++)
  {
    for (int j =0; j<3; j++)
    {
      if (macierz [i][j]<10)
        printf("%d ", macierz[i][j]);
    }
    printf ("\n");
  }
}

int wyznacznik(int macierz[3][3])
{
  int a=0;
  for (int i =0; i<3; i++)
  {
    int iloczynprawy=1;
    int iloczynlewy=-1;

    for (int j=0; j<3; j++)
    {
      iloczynprawy *=macierz[(i+j)%3][j];
      iloczynlewy *=macierz[(i+j)%3][2-j];
    }
    a+= iloczynlewy+iloczynprawy;
  }
  return a;
}
int main(void)
{
  srand(time(0));

  int macierz [3][3];
  wypelnij (macierz);
  wypisz (macierz);

  int w= wyznacznik(macierz);
  printf("Wyznacznik = %d\n", w);

  return 0;
}
