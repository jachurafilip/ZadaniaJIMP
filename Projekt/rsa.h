#ifndef RSA_H_
#define RSA_H_
void prepare(mpz_t, mpz_t, mpz_t, mpz_t, mpz_t, mpz_t, mpz_t, mpz_t);

char* getMessage();
char* getHexText();
char* convertTextToHex(char*);
char* convertHexToText(char*);

void encrypt(mpz_t, const mpz_t, const mpz_t, const mpz_t);
void decrypt(mpz_t, const mpz_t, const mpz_t, const mpz_t);

void RSA(mpz_t, mpz_t, mpz_t, mpz_t, mpz_t, mpz_t);
void printMessage(mpz_t);

#endif
