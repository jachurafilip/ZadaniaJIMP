#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<conio.h> //getch()  DZIAŁA TYLKO NA WINDOWSIE
int compare(const void* _a, const void* _b)
{
  int a = *(int*)_a;
  int b = *(int*)_b;
  return a-b;
}


void losuj(int* tab){
	for (int i=0; i<10; i++){
		*(tab+i)=rand()%100;
	}
}
void drukuj(int* tab){
	printf("[");
	for (int i=0; i<10; i++){
		printf("%d ", *(tab+i));
	}
	printf("]\n");
}
float srednia(int* tab){
	int suma=0;
	for (int i=0; i<10;i++){
		suma+=*(tab+i);
	}
	return suma/10.0;
}
float mediana(int* tab){
  int kopia[10];
  for (int i=0;i<10;i++)
  {
    kopia[i]=*(tab+i);
  }
	qsort(kopia,10,sizeof(int),compare);
		return (kopia[4]+kopia[5])/2.0;
}
int min(int* tab){
	int min=tab[0];
	for(int i=1;i<10;i++){
		if (min>tab[i])
			min=tab[i];
	}
	return min;
}
int max(int* tab){
	int maks=tab[0];
	for(int i=1;i<10;i++){
		if (maks<tab[i])
			maks=tab[i];
	}
	return maks;
}

void program()
{
  int tab[10];
	int c;
	while (c!=54)
  {

		printf("\
Menu\n\
1. Losuj\n\
2. Wyswietl\n\
3. Policz srednia\n\
4. Policz mediane\n\
5. Znajdz element maksymalny i minimalny\n\
6. Zakoncz program\n");
		c = getch();
		while(c<49 && c>54)
    {
      printf("Wcisnij poprawny klawisz(1-6)\n");
      c = getch();
    }
		switch (c)
		{
		case '1':
			losuj(tab);
			printf("Wylosowano tablice.\n");
		break;
		case '2':
			drukuj(tab);
		break;
		case '3':
			printf("Srednia wynosi %f\n", srednia(tab));
		break;
		case '4':
			printf("Mediana wynosi %f\n", mediana(tab));
		break;
		case '5':
			printf("Min = %d, Max = %d\n", min(tab), max(tab));
			break;
		}
	}
}

int main()
{
	srand(time(NULL));
	program();
}
