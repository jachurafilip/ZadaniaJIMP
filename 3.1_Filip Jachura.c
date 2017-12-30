//kompiluje sie z flaga -lm

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double poleProstokata(double a, double b)
{
    return a*b;
}

double poleTrojkata(double a, double h)
{
    return a*h/2;
}

double poleKola(double r)
{
    return r*r*M_PI;
}

void policz(char c)
{
    double a,b;
    switch(c)
    {
        case 'r':
            printf("Podaj dlugosci bokow");
            scanf("%lf %lf",&a,&b);
            if(a<0 || b<0)
            {
              printf("Bledne dane");
              break;
            }
            printf("Pole prostokata wynosi %lf",poleProstokata(a,b));
            break;
        case 's':
            printf("Podaj dlugosc boku");
            scanf("%lf",&a);
            if(a<0)
            {
              printf("Bledne dane");
              break;
            }
            printf("Pole kwadratu wynosi %lf",poleProstokata(a,a));
            break;
        case 't':
            printf("Podaj dlugosc boku i wysokosci");
            scanf("%lf %lf",&a,&b);
            if(a<0 || b<0)
            {
              printf("Bledne dane");
              break;
            }
            printf("Pole trojkata wynosi %lf",poleTrojkata(a,b));
            break;
        case 'c':
            printf("Podaj promien");
            scanf("%lf",&a);
            if(a<0)
            {
              printf("Bledne dane");
              break;
            }
            printf("Pole kola wynosi %lf",poleKola(a));
            break;
        default:
            printf("Wprowadzono bledne dane");
    }
}

int main()
{
   printf("Podaj jakiej figury pole chcesz obliczyc:\n"
         "r - prostokat \n"
         "s - kwadrat \n"
         "t - trojkat \n"
         "c - kolo\n");
    char c;
    scanf("%c",&c);
    policz(c);
}
