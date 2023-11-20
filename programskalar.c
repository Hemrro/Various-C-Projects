#include<stdio.h>
#include <math.h>

int skalar();
int filter();
int korszamit();
int szamologep();



int main(){

int option;

printf("1: skalar szorzas\n2: korterulet szamitas\n3: szamologep\n"); scanf("%d", &option);


    switch(option){
    case 1 : skalar(); break;
    case 2 : korszamit(); break;
    case 3 : szamologep(); break;
    default: printf("fu");
}
system("pause");
return 0;
}


int filter(){
int szam, limit=0;
do{
    scanf("%d", &szam);
    if(szam<=limit){printf("nagyobb kell mint %d\n", limit);}
}while(szam<=limit);
return szam;
}

int skalar(){
int sKszam, i, temp=1; printf("szam:");
scanf("%d", &sKszam);
sKszam=filter();
    for(i=1;i<=sKszam;i++){
        temp= temp*i;
    }
    printf("skalar: %d", temp);
return temp;
}

int korszamit(){
double i, h, sugar, terulet, pontossag = 0.01;
        printf("a kor sugara:"); scanf("%f\n", &sugar);
sugar=filter();
    for(i=0;i<sugar;i=i+pontossag){                     //az eslõ számot nem veszi figyelembe valamiért
            h = sqrt(((sugar*sugar)-(i*i)));
            terulet = terulet + h * pontossag;
    }
    terulet = terulet * 4;
    printf("a kor terulete %f\n", terulet);
return terulet;
}

int szamologep(){
    char szamopc;
    double szam1, szam2;

    printf("Valasszon muveletet: (+, -, *, /) :");
    while ((getchar()) != '\n');
    scanf("%c", &szamopc);
    printf("Irjon be ket szamot\t");
    scanf("%1f %1f", &szam1, &szam2);


    switch(szamopc){
    case '+' :
        printf("%.11f + %.11f = %.11f", szam1, szam2, szam1+szam2);
        break;
    case '-' :
        printf("%.11f - %.11f = %.11f", szam1, szam2, szam1-szam2);
        break;
    case '*' :
        printf("%.11f * %.11f = %.11f", szam1, szam2, szam1*szam2);
        break;
    case '/' :
        printf("%.11f / %.11f = %.11f", szam1, szam2, szam1/szam2);
        break;
    default : printf("fu");

    }
return 0;
}












//while ((getchar()) != '\n');
