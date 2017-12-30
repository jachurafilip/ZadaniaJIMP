#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double delta(double a, double b, double c)
{
  return b*b-4*a*c;
}

void liczPierwiaski(double a, double b, double c)
{
  if(delta(a,b,c)<0)
    {
      printf("Nie ma pierwiastkow rzeczywistych");
    }
    else if(delta(a,b,c) == 0)
    {
      double pierwiastek=-b/(2*a);
      printf("Jedynym pierwiastkiem rownania jest liczba %lf",pierwiastek);
    }
    else
    {
      double pierwiastek1=(-b+pow(delta(a,b,c),0.5))/(2*a);
      double pierwiastek2=(-b-pow(delta(a,b,c),0.5))/(2*a);

      printf("Istnieja dwa piewiastki: %lf i %lf",pierwiastek1,pierwiastek2);
    }
}

int main()
{
    double a,b,c;
    printf("Podaj wspolczynniki: \na=");
    scanf("%lf",&a);
    while(a==0)
    {
      printf("Rownanie nie jest kwadratowe. Podaj a rozne od 0:\n");
      scanf("%lf",&a);
    }
    printf("b=");
    scanf("%lf",&b);
    printf("c=");
    scanf("%lf",&c);
    liczPierwiaski(a,b,c);
    return 0;
}

