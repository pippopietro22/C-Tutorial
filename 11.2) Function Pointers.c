#include<stdio.h>
#include<stdlib.h>
    //Definisco un array già riempito
    int intarray[5] = {10,20,30,40,50};

    //Definisco la funzione "compare che mi da valori positivi/negativi/nulli" a seconda dei valori che gli passo
    int compare (const void* a, const void* b){
        return (*(int*)a - *(int*)b);
    }

    int main(){
        //Definisco un puntatore alla mia funzione
        int (*cmg)(const void*,const void*);
        cmg = &compare;

        //Chiamo la funzione "qsort" per riordinare il mio array
        qsort(intarray, sizeof(intarray)/sizeof(*intarray), sizeof(int), cmg);  //La funzione mette in ordine i nostri elementi secondo la funzione "compare" che gli passiamo
                                                                                //base: Array di numeri da riordinare
                                                                                //num:  Numero di elementi da riordinare
                                                                                //size: Dimensione (in byte) di ogni elemento da rioridare
                                                                                //compare: Funzione che passiamo.
        //Stampo i valori del mio array
        for (int i = 0; i < 5; i++){
            printf("%d \t", intarray[i]);
        }

        printf("\n");

        return 0;
    }
