#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
  double area, altura, raio, v, d;
  const double pi = 3.14;

  while(scanf("%lf %lf" ,&v,&d) == 2){
    raio = d/2.0;
    area = pi * raio * raio;
    altura = v/ area;
    printf(" ALTURA = %.2lf\n", altura);
    printf("AREA = %.2lf\n", area);
  }

    return 0;
}
