    #include <stdio.h>

    void f1(int var){
        printf("this is f1 and var is: %d\n", var);
    }

    void f2(int var){
        printf("this is f2 and var is: %d\n", var);
    }

    void f3(int var){
        printf("this is f3 and var is: %d\n", var);
    }

    int main(){
        //Creo un array di puntatori a funzioni
        void (*cmg[3])(int);

        //Associo ad ogni puntatore una funzione
        cmg[0] = &f1;
        cmg[1] = &f2;
        cmg[2] = &f3;

        //Chiamo in un ciclo tutte le funzioni con "i" come argomento
        for(int i = 0; i < 3; i++){
            (cmg[i])(i);
        }

    return 0;
    }