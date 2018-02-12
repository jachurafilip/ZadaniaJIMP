#include <stdio.h>

int porownaj (int czas1 [], int czas2 [],int rozmiar)
{
  for (int i = 0; i < rozmiar; i++)
  {
    if (czas1[i] > czas2[i])
      return 1;
    if (czas1[i] < czas2[i])
      return -1;
  }
  return 0;
}

int sprawdzCzas(int czas[])
{
  if (czas[0] > 23 || czas[0] < 0)
    return 0;
  if (czas[1]>59 || czas[1] < 0)
    return 0;
  if (czas[2]>59 || czas[2]<0)
    return 0;
  return 1;
}

void podajCzas(int czas[])
{
  printf("Podaj godzine\n");
  scanf ("%d%d%d", czas, czas+1,czas+2);
}

int main(void)
{
  int rozmiar = 3;
  int czas1[rozmiar];
  int czas2[rozmiar];

  podajCzas(czas1);
  podajCzas(czas2);

  if(!(sprawdzCzas(czas1) && sprawdzCzas(czas2)))
  {
    printf ("Nieprawidlowy format. Uzyj hh:mm:ss\n");
    return 0;
  }

  if (porownaj (czas1, czas2, rozmiar) == 1)
  {
    printf("Pierwsza wprowadzona godzina jest pozniejsza niz druga");
  }
  else if (porownaj(czas1, czas2, rozmiar) == 0)
  {
    printf("Godziny sa identyczne");
  }
  else
  {
    printf("Druga wprowadzona godzina jest pozniejsza niz pierwsza");
  }
  return 0;
}
