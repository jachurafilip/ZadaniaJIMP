#include <stdio.h>

int porownaj (int czas1 [3], int czas2 [3]){
	for (int i=0; i<3; i++){
		if (czas1[i]>czas2[i])
			return 1;
		if (czas1[i]<czas2[i])
			return -1;
	}
	return 0;
}
int sprawdzCzas(int czas[3]){
	if (czas[0]>23||czas[0]<0)
		return 0;
	if (czas[1]>59||czas[1]<0)
		return 0;
	if (czas[2]>59||czas[2]<0)
		return 0;
	return 1;
}

int main(void){
	int czas1 [3];
	int czas2 [3];
	printf("Podaj pierwsza godzine\n");
	scanf ("%d%d%d", czas1, czas1+1,czas1+2);
	printf("Podaj druga godzine\n");
	scanf ("%d%d%d", czas2, czas2+1, czas2+2);
	if(!(sprawdzCzas(czas1)&&sprawdzCzas(czas2))){
		printf ("Nieprawidlowy format. Uzyj hh:mm:ss\n");
		return 0;
	}
	if (porownaj (czas1, czas2)==1)
    {
        printf("Pierwsza wprowadzona godzina jest pozniejsza niz druga");
    }
    else if (porownaj(czas1,czas2)==0)
    {
        printf("Godziny sa identyczne");
    }
    else
    {
        printf("Druga wprowadzona godzina jest pozniejsza niz pierwsza");
    }
    return 0;
}
