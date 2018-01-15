#ifndef VECTOR_H__
#define VECTOR_H__
#define VECTOR_INIT_CAPACITY 4


typedef struct vector_ {
    int* data;
    int capacity;
    int total;
} vector;
void swap(int*, int*);
void vector_init(vector*);
int vector_size(vector *);
int vector_capacity(vector *);
int vector_empty(vector *);
static void vector_reserve(vector *,int);
void vector_pushback(vector *, int);
void vector_insert(vector *, int, int);
void vector_delete(vector*,int);
int vector_at(vector *, int);
void vector_reverse(vector *);
void vector_free(vector*);

#endif
