#include<stdio.h>
#include<stdlib.h>  //si inserisce questa libreria per l'allocazione dinamica
    //Inizializzo un puntatore che funge da array di char
    char*pvoc;
    int n=3;      //La variabile n impone la dimensione del nostro array

    int main(){
        //Si alloca la dimensione del nostro array
        pvoc=(char*)malloc(n*sizeof(char));

        //Ad ogni posizione si associa un char
        pvoc[0]='A';
        pvoc[1]='B';
        pvoc[2]='C';

        //Si stampa ogni char dell'array
        for(int i = 0; i < 3; i++){
            printf("pvoc[%d] = %c  ",i,pvoc[i]);
        }
        printf("\n");

        //Si libera la memoria
        free(pvoc);

        return 0;
    }