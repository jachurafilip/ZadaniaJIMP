#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(const void* _a, const void* _b)
{
  int a = *(int*)_a;
  int b = *(int*)_b;
  
  return a-b;
}

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

int readAndSort(char* plik, int*tab)
{
	FILE *dane;
	if ((dane=fopen(plik, "r"))==NULL) 
  	{
     	printf ("Nie mogę otworzyć pliku %s do odczytu!\n",plik);
     	exit(1);
  	}
    	int i =0;
    	while(1)
    	{
       	if(feof(dane))
       	{
					break;
	 		 	}
       	fscanf(dane,"%d",&tab[i]);
       	i++;
    	}
   fclose (dane);
   int rozmiar = i-1;
   qsort(tab,rozmiar,sizeof(tab[0]),compare);
   return rozmiar;
}

int main(int argc, char **argv)
{
  char* from = argv[1];
  char* to = argv[2];
  
  int* tab;
  tab = (int*) malloc(1000*sizeof(int));
	int rozmiar = readAndSort(from,tab);
  
    if (argc==3) //jesli zostal podany trzeci argument (plik do zapisu)
    {
    	zapisz(to, rozmiar, tab);
    }
    else
    {
      for (int j=0; j<rozmiar;j++)
      {
        printf("%d ",tab[j]);
      }
    }
   free(tab);

  return 0;
}
