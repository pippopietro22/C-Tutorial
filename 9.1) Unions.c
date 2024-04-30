#include<stdio.h>
#include<stdlib.h>
    //Creo una union per guardare ad un'unica cella di memoria in diversi modi
    union intParts{
        int intPart;
        char bytes[sizeof(int)];
    };

    int main(){
        union intParts parts;   //Dichiaro la mia variabile
        int intParts;            //Dichiaro un intero

        //Associo un valore
        printf("Inserisci un intero, maggiore di 255 (1 byte): ");
        scanf("%i", &intParts);

        parts.intPart = intParts;

        //Stampo la mia cella di memoria
        printf("1) Il mio int è: %i\n e i miei byte sono: [%i, %i, %i, %i]\n",
                parts.intPart, parts.bytes[0], parts.bytes[1], parts.bytes[2], parts.bytes[3]);


        printf("\n"); //Lascio uno spazio


        //Si può anche scrivere
        printf("2) Il mio int è: %i\n e i miei bytes sono: [%i, %i, %i, %i]\n",
                intParts, *((char*)&intParts+0),*((char*)&intParts+1),*((char*)&intParts+2),*((char*)&intParts+3));


        printf("\n"); //Lascio uno spazio


        //Oppure ancora

        printf("3) Il mio int è: %i\n e i miei bytes sono: [%i, %i, %i, %i]\n",
                intParts, ((char*)&intParts)[0],((char*)&intParts)[1],((char*)&intParts)[2],((char*)&intParts)[3]);

        return 0;
    }