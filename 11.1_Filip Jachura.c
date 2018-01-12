#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void zapisz(char* plik, int size, int* tab)
{
  FILE *fp;
    if ((fp=fopen(plik, "w"))==NULL) 
    {
      printf ("Nie mogę otworzyć pliku %s do zapisu!\n",plik);
    }
    else
    {
      for (int i=0; i<size;i++)
      {
        fprintf(fp,"%d ",tab[i]);
      }
    }
  fclose (fp);
}

int main(int argc, char **argv)
{
  srand(time(0));
	
  char* size = argv[1];
  char* plik = argv[2];
  int n = atoi(size);
  if (n<1)
  {
     printf("Wprowadzono niepoprawne dane.");
     return 0;
  }
  int* tab;
  tab = (int*) malloc(n*sizeof(int));
  for (int i=0; i<n;i++)
  {
    tab[i] = rand()%1000;
  }

  zapisz(plik,n,tab);
  
  free(tab);
  return 0;
}

