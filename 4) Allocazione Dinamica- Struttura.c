#include<stdio.h>
#include<stdlib.h> //si inserisce questa libreria per l'allocazione dinamica
    //Creo una struttura di tipo person
    typedef struct{
        int age;
        char*name;
    }person;

    int main(){
        //creo un puntatore person e lo alloco in modo che abbia le giuste dimensioni
        //(person*) serve per (ri-)definire il tipo person
        //Sizeof è una specie di funzione che da le dimensioni di un struttura "person"
        person*myperson=(person*)malloc(sizeof(person));

        //inserisco i relativi dati
        myperson->age=20;               //con i puntatori a struttura, quando do un valore, uso questa sintassi
        myperson->name="John_Ruth";     //NON myperson.age=20 

        //Stampo i dati
        printf("Ciao, sono %s e ho %d anni!\n",myperson->name, myperson->age); //Anche quando scrivo i campi uso questa sintassi myperson->age/name

        free(myperson);

        return 0;
    }