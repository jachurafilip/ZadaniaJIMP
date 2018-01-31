#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "rsa.c"

#define MAX_SIZE 2048	



int main(void)
{
	mpz_t p, p_1, q, q_1 , lambda, e, n, d; //inicjacja zmiennych potrzebnych do algorytmu RSA
	mpz_inits(p, q, q_1, p_1, lambda, e, n, d, NULL);
	
	prepare(n, p, p_1, q, q_1, lambda, e, d);

	char* hex = getHexText();

	mpz_t encrypted, decrypted, message;
	mpz_inits(encrypted, decrypted, message, NULL);
	mpz_set_str(message, hex, 16); //przekazujemy wiadomosc do zmiennej message

	free(hex);

	RSA(n, e, d, message, decrypted, encrypted);
	printMessage(decrypted);
	mpz_clears(e, d, n, encrypted, decrypted, message, NULL);
	return 0;
}	
