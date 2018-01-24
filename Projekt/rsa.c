#include <gmp.h>
#include <string.h>
#include "rsa.h"

void getMessage(char* message)
{
	do
	{
		printf("Podaj wiadomosc do zaszyfrowania (bez spacji) : ");
		scanf("%s",message);
	} while (strlen(message) > 128);
}

void convertTextToHex(char* text, char* hexText)
{
	int lenght = strlen(text);
	int number = 0;
	int tmp = 0;
	for (int i = 0, j = 0; i < lenght; i++)
	{
		number = text[i];
		tmp = number % 16;
		
		if (tmp < 10)
			tmp += '0';
		else
			tmp += 'a' - 10;
		hexText[j+1] = tmp;
		tmp = number / 16;
		if (tmp < 10)
			tmp += '0';
		else
			tmp += 'a' - 10;
		hexText[j] = tmp;
		j += 2;
	}
}

void convertHexToText(char* text, char* hexText)
{
	char liczba;
	int lenght = strlen(hexText);
	for (int i = 0, j = 0; i < lenght; i += 2)
	{
		liczba = 0;
		if (hexText[i] < 'A')
			liczba += (hexText[i] - '0') * 16;
		else
			liczba +=(hexText[i] - 'a' + 10) * 16;
		if (hexText[i+1] < 'A')
			liczba += (hexText[i+1] - '0');
		else
			liczba += (hexText[i+1] - 'a' + 10);
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
