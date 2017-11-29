#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int ***stworzTablice3D(int wiersze, int kolumny, int poziomy)
{
int *** array = (int ***)malloc(poziomy*sizeof(int**));
for (int i = 0; i< poziomy; i++)
    {
    array[i] = (int **) malloc(kolumny*sizeof(int *));
    for (int j = 0; j < kolumny; j++)
        {
        array[i][j] = (int *)malloc(wiersze*sizeof(int));
        }
    }
return array;
}
int **stworzTablice2D(int wiersze, int kolumny)
{
int ** array = (int **)malloc(kolumny*sizeof(int*));
for (int i = 0; i< kolumny; i++)
    {
    array[i] = (int *) malloc(wiersze*sizeof(int));
    }
return array;
}
void uzupelnijMacierz(int** macierz)
{

    macierz[0][0]=rand()%200-100;
    macierz[0][1]=rand()%200-100;
    macierz[1][0]=rand()%200-100;
    macierz[1][1]=rand()%200-100;
}
void zamien2Dna3D(int***tab, int**macierz1, int**macierz2)
{
    tab[0]=macierz1;
    tab[1]=macierz2;
}
void destroy3DArray(int*** arr)
{
    free(**arr);
    free(*arr);
    free(arr);
}
void destroy2DArray(int** arr)
{
    free(*arr);
    free(arr);
}
int **pomnozMacierze(int*** macierz)
{
    int** macierz1 = stworzTablice2D(2,2);
    int** macierz2 = stworzTablice2D(2,2);
    macierz1=macierz[0];
    macierz2=macierz[1];
    int**wynik = stworzTablice2D(2,2);
    int suma=0;
    for (int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {   suma =0;
            for(int k=0; k<2; k++)
            {
                suma+=macierz1[i][k]*macierz2[k][j];
            }
            wynik[i][j]=suma;
        }
    }
    return wynik;
}
void wyswietlMacierz(int**macierz, int rozmiar)
{
    for (int i=0; i<rozmiar;i++)
    {
        for(int j=0;j<rozmiar;j++)
        {
            printf("%d ",macierz[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    srand(time(0));
    int*** arr = stworzTablice3D(2,2,2);
    int** macierz1 = stworzTablice2D(2,2);
    int** macierz2 = stworzTablice2D(2,2);

    uzupelnijMacierz(macierz1);
    uzupelnijMacierz(macierz2);

    zamien2Dna3D(arr,macierz1,macierz2);
    int**mnozenie = pomnozMacierze(arr);

    printf("Macierz 1: \n");
    wyswietlMacierz(macierz1,2);

    printf("Macierz 2: \n");
    wyswietlMacierz(macierz2,2);

    printf("Wynik: \n");
    wyswietlMacierz(mnozenie,2);

    destroy2DArray(macierz1);
    destroy2DArray(macierz2);
    destroy3DArray(arr);
    return 0;

}
