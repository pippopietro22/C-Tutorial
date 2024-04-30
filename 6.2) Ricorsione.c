#include<stdio.h>
    //Creo funzione "factorial" per ricorsione
    unsigned int factorial(unsigned int x){          //unsigned tratta solo numeri positivi
        if(x == 0){
            return 1;
        }else{
            if (x == 1){
                return 1;
            }else{
                return x*factorial(x-1);
            }
        }
    }


    int main(){
        //Diachiaro la variabile 'a' cui associero il numero interessato per "factorial". 'b' è il risultato
        int a,b;

        //Acquisisco il valore di 'a'
        printf("Inserisci il numero di cui vuoi calcolare il fattoriale (positivo): ");
        scanf("%d",&a);

        //Controllo che 'a' sia positivo
        if (a < 0){
            printf("Hai inserito un numero negativo!\n");
            return 1;
        }

        //Chiamo la funzione "factorial"
        b = factorial(a);

        //Stampo il risultato
        printf("%d! = %d\n",a,b);

        return 0;
    }