#include <stdio.h>
#include <stdlib.h>

double CelsjuszDoFarenheit(double temp) 
{
  return temp * 1.8 + 32;
}

double FarenheitDoCelsjusz(double temp) 
{
  return (temp - 32) / 1.8;
}

void wybierz(char c) 
{
  double temp;
  printf("Podaj temperature:\n");
  scanf("%lf", & temp);
  switch (c) 
  {
    case 'c':
      printf("%lf", CelsjuszDoFarenheit(temp));
      break;
    case 'f':
      printf("%lf", FarenheitDoCelsjusz(temp));
      break;
    default:
      printf("Wprowadziles zle dane");
  }
}

int main() 
{
  printf("Podaj jak chcesz zamienic:\n"
         "c - Celsjusz na Farenheit \n"
         "f - Farenheit na Celsjusz \n");
    
  char stopnie = getchar();
  wybierz(stopnie);
  return 0;
}
