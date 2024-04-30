#include<stdio.h>
    //Creo una struttura di tipo person
    typedef struct{
        int age;
        char*name;
    }person;

    //La funzione compleanno, attraverso un puntatore a struttura, incrementa l'età di 1
    void birthday(person*a){
        a->age +=1;
        //(*a).age +=1;
    }

    int main(){
        //Dichiaro la variabile di tipo person
        person myperson;

        //Si chiede di inserire l'età di una persona
        printf("Quanti anni hai?");
        scanf("%d",&myperson.age);

        //Si utilizza la funzione birthday per aumentare l'età di 1
        birthday(&myperson);

        //Si stampa il risultato finale
        printf("Compiuti gli anni, avrai %d anni!\n",myperson.age);

        return 0;
    }