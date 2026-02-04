#include<stdio.h>
#include<stdlib.h>
int main()
{
  int v1, v2, v3, og1, og2, og3,temp;
  scanf("%d %d %d",&v1,&v2,&v3);
 og1=v1;
 og2=v2;
 og3=v3;


 if(v1>v2){
    temp=v1;
    v1=v2;
    v2=temp;
 }
 if(v2>v3){
    temp=v2;
    v2=v3;
    v3=temp;
 }
if(v1>v2){
    temp = v1;
    v1=v2;
    v2=temp;
}
 printf("%d\n", v1);
 printf("%d\n",v2);
 printf("%d\n",v3);

 printf("\n");

printf("%d\n",og1);
printf("%d\n",og2);
printf("%d\n",og3);
    return 0;
}
