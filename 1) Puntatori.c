#include<stdio.h>
    // definisco una variabile (n) a 5 e il suo relativo puntatore
    int n=5;
    int *pointer_to_n=&n;

    int main(){
        //Stampo il valore iniziale di n
        printf("Valore iniziale: %d\n",n);
        
        //Incremento di uno il valore di n attraverso il puntatore
        *pointer_to_n +=1;

        //Stampo il valore incrementato di n
        printf("Valore incrementato di 1: %d\n", n);

        return 0;
    }