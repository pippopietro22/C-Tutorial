#include<stdio.h>
    int intarray[5] = {10,20,30,40,50};     //Dichiaro un array di interi gia riempito

    int main (){
        int* intpointer = &intarray[3];       //Dichiaro un puntatore al quarto elemento del mio array

        //Creo un ciclo dove stampo i valori del mio array e gli indirizzi di cella
        int i;
        for(i = 0; i < 5; i++){
            printf("intarray[%d] = %d e l'indirizzo è: @ %p\n",i, intarray[i], &intarray[i]);
        }

        //Stampo il valore e l'indirizzo della quarta cella attraverso il mio puntatore
        printf("La quarta cella ha valore intarray[3] = %d e l'indirizzo è @ %p\n", *intpointer, intpointer);

        //Utilizzo le operazioni di incremento per stampare la quinta cella attraverso il puntatore
        intpointer++;           //Se scrivessi "intpointer--;" otterrei la terza cella (intarray[2])
                                //Vanno bene anche le operazioni "intpointer +=1;" o "intpointer -=1"
                                //Si può incrementare anche di numeri interi diversi da 1

        //Stampo ora il valore successivo
        printf("il valore della quinta cella è intarray[4] = %d e l'indirizzo è: @ %p\n", *intpointer, intpointer);

        //Stampo il vaolore e indirizzo della quinta cella attraverso l'array per confronto
        printf("il valore della quinta cella è intarray[4] = %d e l'indirizzo è: @ %p\n", intarray[4], &intarray[4]);

        return 0;
    }

    //NOTA: ogni volta che si shifta il puntatore di una posizione, l'indirizzo della cella varia di 4 posizioni. 
    //      Questo perché ogni intero è scritto utilizzando 4 byte. Se quindi si prova a shiftare di 2 posizioni,
    //      si otterrà una variazione dell'indirizzo di 8 byte.

    //NOTA: Si possono utilizzare anche operazioni di comparazione (<,>,==) che funzionano come per le variabili normali.