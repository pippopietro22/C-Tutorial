#include<stdio.h>
    //creo una funzione che moltiplichi 2 numeri per ricorsione
    unsigned int multiply(unsigned int x, unsigned int y){          //unsigned tratta solo numeri positivi
        if (x == 0){
            return 0;
        }else{
            if (y == 0){
                return 0;
            }else{
                if (x == 1){
                    return y;
                }else{
                    if (y == 1){
                        return x;       //Definisco tutti i casi per x,y = 1 o 0
                    }else{
                        return y + multiply(x-1,y);     //Adesso moltiplico per ricorsione
                    }                                   //Ovvero, sommo y (x volte)
                }
            }
        }
    }

    int main(){
        //Dichiaro 'a' e 'b' che sono da moltiplicare, 'c' è il risultato
        int a,b,c;

        //Faccio inserire i numeri da moltiplicare
        printf("Inserisci i numeri da moltiplicare (positivi): ");
        scanf("%d%d",&a,&b);

        //Eseguo la funzione multiply
        c = multiply(a,b);

        //Stampo il risultato
        printf("il risultato è: %d\n",c);

        return 0;
    }