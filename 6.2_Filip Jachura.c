#include<stdio.h>
#include<time.h>

const int dni[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

void rysuj(int miesiac, int dzienmies, int dzientyg)
{
  int format=(dzientyg-dzienmies+49)%7;
  printf("PON WTO SRO CZW PIA SOB NIE\n");
  for (int i=0; i<format;i++)
  {
    printf("    ");
  }
  for (int i =1; i<=dni[miesiac];i++)
  {
    if(i<10)
    {
      printf(" ");
    }
    printf("%d  ",i);
    if ((i+format)%7==0)
    {
      printf("\n");
    }
  }
}

int main()
{
  time_t sekundy;
  struct tm czas;
  time(&sekundy);
  localtime_s(&czas,&sekundy);
  char tytul[20];
  strftime(tytul,20,"%B %Y", &czas);
  printf("\t%s\n",tytul);
  rysuj(czas.tm_mon+1,czas.tm_mday,czas.tm_wday%7);
}
