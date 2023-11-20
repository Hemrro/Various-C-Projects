#include <stdio.>

typedef struct hallgato{ char nev[10]; int bor;}hallgato;

void feglalfeltolt(halgato **h, int *eszam){
    char fajlNev[20], ch;
    FILE *fp;
    printf("Fajlnev: "); scanf("%s", fajlnev);
    fp = fopen(fajlnev, "r");

    while((ch= fgetc(fp)) != EOF){
        if(ch=='\n'){(*eszam)++; }
    }
    *h = malloc(*eszam * siveof(hallgato));

    rewind(fp);

    for(i = 0 ; i < *eszam; i++){
        fscanf(fp, "%s%d", (*h)[i].nev, &(*h)[i].bor);
    }
    fclose(fp);
}

void listazo(hallgato *h, int esz){
int i;
    for(i = 0 ; i < *esz; i++){
        printf("%s\t%d\n", h[i].nev, h[i].bor);
    }
}

int main(){

    hallgato *hallgatok;
   /* FILE *fp = fopen("tesztfajl.txt", "a");
    fptrintf(fp, "uga\r69\nbuga\t20\nhan\t420\n");
    fflush(fp);
    fclose(fp);*/

    int elemszam = 0;
    feglalfeltolt(&halgatok, &elemszam);
    listazo(hallgatok , elemszam);



