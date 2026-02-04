#include <stdio.h>

int main()
{
int seg, hr=0, min=0;
printf("Digite determinado tempo em segundos: ");
scanf("%d",&seg);
hr = seg / 3600;
seg = seg % 3600;
min = seg / 60;
seg = seg % 60;
printf("%d :%d :%d", hr, min, seg);


return 0;
}

