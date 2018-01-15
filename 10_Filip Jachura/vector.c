#include "vector.h"

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void vector_init(vector *v)
{
    v->capacity = VECTOR_INIT_CAPACITY;
    v->total = 0;
    v->data = malloc(sizeof(int) * v->capacity);
}

int vector_size(vector *v)
{
    return v->total;
}

int vector_capacity(vector *v)
{
  return v->capacity;
}

int vector_empty(vector *v)
{
  if (v->total==0)
    return 1;
  return 0;
}

static void vector_reserve(vector *v, int capacity)
{
    printf("vector capacity changed from %d to %d\n", v->capacity, capacity);

    int *data = realloc(v->data, sizeof(void *) * capacity);
    if (data)
    {
        v->data = data;
        v->capacity = capacity;
    }
}

void vector_pushback(vector *v, int item)
{
    if (v->capacity == v->total)
        vector_reserve(v, v->capacity * 2);
    v->data[v->total++] = item;
}

void vector_insert(vector *v, int index, int data)
{
    if (index >= 0 && index < v->total+1)
    {
      if (v->capacity == v->total)
        vector_reserve(v, v->capacity * 2);
      v->total++;
      for (int i=v->total-1;i>index;i--)
      {
        v->data[i]=v->data[i-1];
        v->data[i-1]=0;
      }
      v->data[index] = data;
    }
}

void vector_delete(vector *v, int index)
{
    if (index < 0 || index >= v->total)
        return;

    v->data[index] = 0;

    for (int i = index; i < v->total - 1; i++) {
        v->data[i] = v->data[i + 1];
        v->data[i + 1] = 0;
    }

    v->total--;
}

int vector_at(vector *v, int index)
{
    if (index >= 0 && index < v->total)
        return v->data[index];
    return -1;
}

void vector_reverse(vector *v)
{
 int first =0;
 int last = v->total-1;
 while (first < last)
  {
        swap(&v->data[first++], &v->data[last--]);
  }
}

void vector_free(vector *v)
{
    free(v->data);
}
