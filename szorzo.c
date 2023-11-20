#include<stdio.h>

int szorzo();
int filter();
int ujra();
int maximum(int n);

int main(){
int a;
char again;
do{
a=szorzo();
a= maximum(a);
}while(ujra());
return 0;
}




int filter(){
    int temp, limit=0;
    do{
        scanf("%d", &temp);
        if(temp<=limit){printf("nagyobb kell mint %d!\n",limit);}
      }
        while(temp<= limit);
    return temp;
}

int szorzo(){
int i, j, sor, oszlop;
sor= filter();
oszlop=filter();
for(i=1;i<=sor;i++){
    for(j=1;j<=oszlop;j++){
printf("%d * %d = %d\t",i,j,i*j);
    }
    printf("\n");
 }
 return sor * oszlop;
}

int ujra(){
    char again;
printf("ujra? (i/n) ");
scanf(" %c", &again);
if(again=='i'){return 1;}
return 0;
}

int maximum(int n){
int i, max , szam;
printf("1. szam:"); scanf("%d", szam); max=szam;
for(i=2;i<=szam;i++){
 printf("%d szam:", i); scanf("%d", szam);
 if(szam>max){max=szam};
 return max;
}
}
