#include<stdio.h>
    int intarray[5] = {10,20,30,40,50};     //Definisco un array già riempito
    int* pointer = &intarray[2];            //Definisco un puntatore al terzo elemento del mio array
    int* parray[3];                         //Definisco un array di puntatori che deve memorizzare gli ultimi 3 indirizzi del mio array

    int main(){
        //Creo un ciclo per salvare gli ultimi 3 indirizzi
        int i;
        for(i = 0; i < 3; i++){
            parray[i] = pointer;    //Passo i valori degli indirizzi al mio array di puntatori
            pointer++;              //"pointer" passa alla cella successiva dell'array
        }

        //Riporto "pointer" alla terza cella dell'array
        pointer -=3;

        //Creo un ciclo per vedere se ho salvato correttamente gli indirizzi delle celle
        for(i = 0; i < 3; i++){
            //Utilizzo un "if" che mi dice iterativamente se il processo ha avuto successo o meno;
            if(parray[i] == pointer){
                printf("Matched!\n");
            }else{
                printf("Faild!\n");
            }

            //"pointer" passa alla cella successiva dell'array
            pointer++;
        }

        return 0;
    }