#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double StopnieNaRadiany(double kat)
{
    return kat * M_PI/180;
}

double RadianyNaStopnie(double kat)
{
    return kat * 180/M_PI;
}

void wybierz(char c)
{
  double kat;
  switch(c)
  {
  case 's':
      printf("Podaj ile stopni ma kat\n");
      scanf("%lf",&kat);
      printf("Kat ma %lf radianow",StopnieNaRadiany(kat));
      break;
  case 'r':
      printf("Podaj ile radianow ma kat\n");
      scanf("%lf",&kat);
      printf("Kat ma %lf stopni",RadianyNaStopnie(kat));
      break;
  default:
      printf("Wprowadzono bledne dane");
  }
}

int main()
{
    char c;
    printf("Podaj jak chcesz zamieniac:\n\"
           "s - Stopnie na radiany \n\"
           "r - Radiany na stopnie\n");
    scanf("%c",&c);
    wybierz(c);
    return 0;
}
