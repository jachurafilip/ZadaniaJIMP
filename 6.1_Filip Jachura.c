#include <stdio.h>
void wypiszASCII()
{
  char i = 0;
  for (int j = 0; j < 256; j++)
  {
    printf("%c\t", i);
    printf("%d\n",j);
    i++;
  }
}

int main()
{
  wypiszASCII();
	return 0;
}
