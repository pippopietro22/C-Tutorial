#include<stdio.h>
    //Creo una funzione a caso solo per chiamarla con un puntatore
    void Funzione (int arg){
        printf("Questa è la mia funzione inutile e il numero è: %d\n", arg);
    }

    int main (){    
        //Provo a chiamare la mia funzione per vedere se va bene;
        Funzione(6);

        void (*pf)(int);      //Ho definito un puntatore "pf" di tipo void e gli ho associato un argomento intero

        //Associo al mio puntatore la funzione
        pf = &Funzione;

        //Chiamo adesso la mia funzione attraverso il puntatore
        (pf)(5);

        return 0;
    }