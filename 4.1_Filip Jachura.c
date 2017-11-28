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
        printf("Jedynym pierwiastkiem rownania jest liczba %lf",-b/2*a);
    }
    else
    {
        printf("Istnieja dwa piewiastki: %lf i %lf",(-b+pow(delta(a,b,c),0.5))/(2*a),(-b-pow(delta(a,b,c),0.5))/(2*a));
    }
}

int main()
{
    double a,b,c;
    printf("Podaj wspolczynniki: \na=");
    scanf("%lf",&a);
    printf("b=");
    scanf("%lf",&b);
    printf("c=");
    scanf("%lf",&c);
    liczPierwiaski(a,b,c);
    return 0;
}

