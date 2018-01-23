#include <gmp.h>
#include <string.h>
#include "rsa.h"

void getMessage(char* message)
{
	do
	{
		printf("Podaj wiadomosc do zaszyfrowania (bez spacji, do 11 znakow) : ");
		scanf("%s",message);
	} while (strlen(message)>11);
}

void convertTextToHex(char* text, char* hexText)
{
	int lenght = strlen(text);
	int number=0;
	int tmp=0;
	int j =0;
	for (int i =0; i<lenght; i++)
	{
		number = text[i];
		tmp = number%16;
		
		if (tmp<10)
			tmp+=48;
		else
			tmp+=87;
		hexText[j+1]=tmp;
		tmp = number/16;
		if (tmp<10)
			tmp+=48;
		else
			tmp+=55;
		hexText[j]=tmp;
		j+=2;
	}
}

void convertHexToText(char* text, char* hexText)
{
	char liczba;
	int j=0;
	int lenght = strlen(hexText);
	for (int i = 0; i<lenght; i+=2)
	{
		liczba = 0;
		if (hexText[i]<65)
			liczba+= (hexText[i]-48)*16;
		else
			liczba+=(hexText[i]-87)*16;
		if (hexText[i+1]<65)
			liczba+= (hexText[i+1]-48);
		else
			liczba+=(hexText[i+1]-87);
		text[j] = liczba;
		j++;
	}
}

void encrypt(mpz_t encrypted, const mpz_t message, const mpz_t e, const mpz_t n)
{
  mpz_powm(encrypted, message, e, n);
}


void decrypt(mpz_t original, const mpz_t encrypted, const mpz_t d, const mpz_t n)
{
  mpz_powm(original, encrypted, d, n);
}
