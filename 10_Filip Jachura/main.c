#include <stdio.h>
#include <stdlib.h>

#include "vector.c"

int main(void)
{
    vector v;
    vector_init(&v);
    vector_pushback(&v,1);
    vector_pushback(&v,2);
    vector_pushback(&v,3);
    vector_pushback(&v,4);
    vector_pushback(&v,5);
    vector_insert(&v,3,12);
    printf("Pojemnosc: %d\n",vector_capacity(&v));
    printf("Ilosc elementow: %d\n",vector_size(&v));
    printf("Czy pusty: %d\n",vector_empty(&v));
    for (int i = 0; i < vector_size(&v); i++)
        printf("%d ", vector_at(&v, i));
    printf("\n");
    printf("Odwracam \n");
    vector_reverse(&v);
    for (int i = 0; i < vector_size(&v); i++)
        printf("%d ", vector_at(&v, i));
    printf("\n");
    vector_delete(&v, 3);
    vector_delete(&v, 2);
    printf("Usunalem elementy z indeksem 2 i 3\n");
     for (int i = 0; i < vector_size(&v); i++)
        printf("%d ", vector_at(&v, i));
    printf("\n");

    vector_free(&v);

    return 0;
}
