#include<stdio.h>
#include<time.h>

int dni[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int przestepny(int rok)
{
  if(rok%4 == 0)
  {
    if(rok%100 == 0)
    {
      if (rok%400 == 0)
        return 1;
      return 0;
    }
    return 0;
    }
    return 1;
}
void rysuj(int rok, int miesiac, int dzienmies, int dzientyg)
{
  int format=(dzientyg-dzienmies+49)%7;
  printf("PON WTO SRO CZW PIA SOB NIE\n");
  for (int i=0; i<format;i++)
  {
    printf("    ");
  }
  for (int i =1; i<=dni[miesiac];i++)
  {
    if(przestepny(rok))
    {
      dni[2]+=1;
    }
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
  rysuj(czas.tm_year, czas.tm_mon+1,czas.tm_mday,czas.tm_wday%7);
}
