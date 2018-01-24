#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "rsa.c"
#define MAX_SIZE 2048	


int main(void)
{
	gmp_randstate_t state; //uruchamiamy maszynę losujaca
	gmp_randinit_mt(state);

	mpz_t p, p_1,q ,q_1 ,lambda ,e ,n ,d; //inicjacja zmiennych potrzebnych do algorytmu RSA
	mpz_inits(p ,q ,q_1 ,p_1 ,lambda ,e ,n ,d ,NULL);

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

	char* text = (char*) calloc (MAX_SIZE/8, sizeof(char));
	getMessage(text);
	char* hex = (char*) calloc (MAX_SIZE/4,sizeof(char));
	convertTextToHex(text, hex); //konwertujemy wiadomosc do systemu hex

	mpz_t encrypted, decrypted, message;
	mpz_inits(encrypted, decrypted, message, NULL);
	mpz_set_str(message, hex, 16); //przekazujemy wiadomosc do zmiennej message
	printf("%s",hex);
	free(hex);
  	free(text);

	encrypt(encrypted, message, e, n); //encrypted - to wiadomosc zaszyfrowana szyfrem RSA
	decrypt(decrypted, encrypted, d, n);

	gmp_printf("Orygnalne: %Zd\n",message);
	gmp_printf("Zaszyfrowane: %Zd\n",encrypted);
	gmp_printf("Po deszyfracji: %Zd\n",decrypted);

	char* wynik = (char*) calloc (MAX_SIZE,sizeof(char));
	mpz_get_str(wynik, 16, decrypted); 
	char* odkodowane = (char*) calloc(MAX_SIZE, sizeof(char));
	convertHexToText(odkodowane, wynik);

	printf("Twoja wiadomosc to: %s",odkodowane);
	free(wynik);
	free(odkodowane);
	mpz_clears(e, d, n, encrypted, decrypted, message, NULL);
	return 0;
}	
