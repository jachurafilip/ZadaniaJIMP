#include <gmp.h>
#include <string.h>
#include "rsa.h"

#define MAX_SIZE 2048

void prepare(mpz_t n, mpz_t p, mpz_t p_1, mpz_t q, mpz_t q_1, mpz_t lambda, mpz_t e, mpz_t d)
{
	gmp_randstate_t state; //uruchamiamy maszynę losujaca
	gmp_randinit_mt(state);

	mpz_rrandomb(p, state, MAX_SIZE); 
	mpz_rrandomb(q, state, MAX_SIZE);
	mpz_nextprime(p, p);
	mpz_nextprime(q, q); //losowanie wartosci 1024 bitowych liczb pierwszych P, Q

	mpz_mul(n, p, q);
	mpz_sub_ui(p_1, p, 1);
	mpz_sub_ui(q_1, q, 1);
	mpz_lcm(lambda, p_1, q_1);
	mpz_add_ui(e, e, 65537);
	mpz_invert(d, e, lambda);
	mpz_clears(p, p_1, q, q_1, lambda, NULL); //ustalenie pozostalych wartosci i czyszczenie niepotrzebnych
}

char* getMessage()
{
	char* message = (char*) calloc (MAX_SIZE/8, sizeof(char));
	do
	{
		printf("Podaj wiadomosc do zaszyfrowania (bez spacji, do 63 znakow) : ");
		scanf("%s",message);
	} while (strlen(message) > 64);

	return message;
}

char* getHexText()
{
	char* text = getMessage();
	char* hex = convertTextToHex(text); //konwertujemy wiadomosc do systemu hex
	free (text);
	return hex;
}

char* convertTextToHex(char* text)
{
	char* hexText = (char*) calloc (MAX_SIZE/4, sizeof(char));
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
	return hexText;
}

char* convertHexToText(char* hexText)
{
	char* text = (char*) calloc (MAX_SIZE/8, sizeof(char));
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
	return text;
}

void encrypt(mpz_t encrypted, const mpz_t message, const mpz_t e, const mpz_t n)
{
  mpz_powm(encrypted, message, e, n);
}


void decrypt(mpz_t original, const mpz_t encrypted, const mpz_t d, const mpz_t n)
{
  mpz_powm(original, encrypted, d, n);
}

void RSA(mpz_t n, mpz_t e, mpz_t d, mpz_t message, mpz_t decrypted, mpz_t encrypted)
{
	encrypt(encrypted, message, e, n); //encrypted - to wiadomosc zaszyfrowana szyfrem RSA
	decrypt(decrypted, encrypted, d, n);

	gmp_printf("Orygnalne: %Zd\n",message);
	gmp_printf("Zaszyfrowane: %Zd\n",encrypted);
	gmp_printf("Po deszyfracji: %Zd\n",decrypted);
}

void printMessage(mpz_t decrypted)
{
	char* wynik = (char*) calloc (MAX_SIZE,sizeof(char));
	mpz_get_str(wynik, 16, decrypted); 

	char* odkodowane = convertHexToText(wynik);
	free(wynik);
	
	printf("Twoja wiadomosc to: %s",odkodowane);
	free(odkodowane);
}
