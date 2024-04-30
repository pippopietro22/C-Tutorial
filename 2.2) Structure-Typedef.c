#include<stdio.h>
    //Definisco una struttura "Persona"
    typedef struct{
        int age;
        char *name;
    }person;

    int main(){
        //Creo una variabile Persona
        person myperson;

        //Attribuisco dei dati a questa variabile
        myperson.age=22;
        myperson.name="Jimmy_Hogan";

        //Stampo in una frase gli attributi della variabile di tipo "Person"
        printf("Hy, I'm %s and I'm %d",myperson.name,myperson.age);

        return 0;
    }