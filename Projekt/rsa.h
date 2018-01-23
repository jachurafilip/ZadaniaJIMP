#ifndef RSA_H_
#define RSA_H_

void getMessage(char*);
void convertTextToHex(char*, char*);
void convertHexToText(char*, char*);
void encrypt(mpz_t, const mpz_t,const mpz_t,const mpz_t);
void decrypt(mpz_t, const mpz_t,const mpz_t,const mpz_t);

#endif
