#include<stdio.h>
    //Creo una struttura "person"
    struct person{
        int age;
        char*name;
    };

    int main(){
        //Dichiaro una variabile "person"
        struct person myperson;

        //Attribuisco a questa variabile dei valori
        myperson.age=22;
        myperson.name="Jimmy Olsen";

        //Stampo i valori della variabile
        printf("Hi, I'm %s and I'm %d\n",myperson.name,myperson.age);

        return 0;
    }