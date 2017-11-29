#include <stdio.h>

void zgadnij (int n){
	printf("Twoja liczba to: ");
	if (n>5){
		if (n>7){
			if (n>9){
				printf("10");
			}
				else if (n>8){
			       		printf("9");
				}
				else printf("8");
		}
		else if (n>6){
				printf("7");
			}
			else printf("6");
	}
		else if (n>2){
			if (n>4){
				printf("5");
			}
			else if (n>3){
			       		printf("4");
				}
				else printf("3");
		}
		else if (n>1){
				printf("2");
			}
			else printf("1");
	printf ("\n");
}
int sprawdz (int n){
	if (n>10){
		n=n%10;
		printf("Twoja liczba by³a wieksza niz 10. Twoja nowa liczba to ostatnia cyfra starej");
	}
	else if (n==0){
		n+=1;
		printf("Twoja liczba byla rowna 0. Zamienilem ja na 1");
	}
	else if (n<0){
		n=(-n)%10;
		printf("Twoja liczba by³a ujemna. Twoja nowa liczba to ostatnia cyfra starej");
	}
	return n;
}

int main (){
	int n=0;
	printf("Podaj liczbe z zakresu [1,10]: \n");
	scanf("%d", &n);
	n=sprawdz (n);
	zgadnij (n);
}




