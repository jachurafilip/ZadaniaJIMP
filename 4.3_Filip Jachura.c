#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int losujLiczbe()
{
    return rand()%9;
}

void stworzTablice(int tab[],int rozmiar)
{
  for (int i=0; i<rozmiar; i++)
  {
    tab[i]=1;
  }
  int a=losujLiczbe();
  tab[a]+=1;
}

void wybierzKulki(int tab[], int ile)
{
  int tmp;
  printf("Podaj %d numerow kulek, ktore chcesz zwazyc (z przedzialu 0-8): \n",ile);
  for (int i=0; i<ile; i++)
  {
    scanf("%d",&tmp);

    while(tmp>8)
    {
      printf("Podaj liczbe z przedzialu 0-8\n");
      scanf("%d",&tmp);
    }
    tab[i]=tmp;
  }
}
void Wazenie1(int kulki[], int mojeKulki[])
{
  int lewa = kulki[mojeKulki[0]]+kulki[mojeKulki[1]]+kulki[mojeKulki[2]];
  int prawa = kulki[mojeKulki[3]]+kulki[mojeKulki[4]]+kulki[mojeKulki[5]];

  if(lewa==prawa)
  {
    printf("Kulki %d, %d i %d waza tyle samo co %d, %d i %d\n",mojeKulki[0],mojeKulki[1],mojeKulki[2],mojeKulki[3],mojeKulki[4],mojeKulki[5]);
  }

  else if(lewa>prawa)
  {
    printf("Kulki %d, %d i %d sa ciezsze niz %d, %d i %d\n",mojeKulki[0],mojeKulki[1],mojeKulki[2],mojeKulki[3],mojeKulki[4],mojeKulki[5]);
  }

  else
  {
    printf("Kulki %d, %d i %d sa lzejsze niz %d, %d i %d\n",mojeKulki[0],mojeKulki[1],mojeKulki[2],mojeKulki[3],mojeKulki[4],mojeKulki[5]);
  }
}
void Wazenie2(int kulki[], int mojeKulki[])
{
  int lewa = kulki[mojeKulki[0]];
  int prawa = kulki[mojeKulki[1]];

  if (lewa==prawa)
  {
    printf("Kulki %d i %d waza tyle samo\n",mojeKulki[0],mojeKulki[1]);
  }
  else if (lewa>prawa)
  {
    printf("Kulka %d jest ciezsza od %d\n",mojeKulki[0],mojeKulki[1]);
  }
  else
  {
    printf("Kulka %d jest lzejsza od %d\n",mojeKulki[0],mojeKulki[1]);
  }
}
int tabMax(int tab[], int dlugosc)
{
  int max,indeks;
  for (int i =0; i<dlugosc; i++)
  {
    if(tab[i]>max)
    {
      max = tab[i];
      indeks = i;
    }
  }
  return indeks;
}

int main(void)
{
  srand(time(NULL));

  int kulki[9];
  stworzTablice(kulki,sizeof(kulki)/sizeof(kulki[0]));

  int wybraneKulki1[6];
  wybierzKulki(wybraneKulki1,sizeof(wybraneKulki1)/sizeof(wybraneKulki1[0]));
  Wazenie1(kulki,wybraneKulki1);

  int wybraneKulki2[2];
  wybierzKulki(wybraneKulki2,sizeof(wybraneKulki2)/sizeof(wybraneKulki2[0]));
  Wazenie2(kulki,wybraneKulki2);

  printf("Podaj ktora kulka jest najciezsza:\n");
  int najciezsza;
  scanf("%d",&najciezsza);

  if(najciezsza == tabMax(kulki,9))
  {
      printf("Dobra robota, zgadles, ktora kulka jest najciezsza!");
  }
  else
  {
      printf("Niestety, nie udalo Ci sie zgadnac");
  }
  return 0;
}
