#include <stdio.h>
#include <stdlib.h>
int compare(const void** _a, const void** _b)
{
  int* a = *(int**)_a;
  int* b = *(int**)_b;

  int liczba1 = *a;
  int liczba2 = *b;
  return liczba1-liczba2;
}


int main()
{

    int tab[] = {1,3,5,7,9,2,4,6,8,10};
    int* wsk[10];
    for(int i=0; i<10;i++)
    {
      wsk[i]=&tab[i];
    }
    qsort(wsk,10,sizeof(int*),compare); //korzystam z funkcji qsort
    printf("Tablica wyswietlona bezposrednio: \n");
    for(int i=0; i<10;i++)
    {
      printf("%d ",tab[i]);
    }
    printf("\n");
    printf("Tablica wyswietlona poprzez posortowane wskazniki: \n");
    for(int k=0; k<10;k++)
    {
      printf("%d ",*wsk[k]);
    }

    return 0;
}
