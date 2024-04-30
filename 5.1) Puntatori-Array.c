#include<stdio.h>
#include<stdlib.h>  //si inserisce questa libreria per l'allocazione dinamica
    char vocali[]={'A','E','I','O','U'};
    char *pvoc=vocali;

    int main(){
        //stampo gli indirizzi
        for(int i=0;i<5;i++){
            printf("&vocali{%d}: %p, pvoc+%d: %p, vocali+%d:%p\n",i,&vocali[i],i,pvoc+i,i,vocali+i);
        }

        //stampo il contenuto
        for(int i=0;i<5;i++){
            printf("vocali[%d]: %c, *(pvoc+%d): %c, *(vocali+%d):%c\n",i,vocali[i],i,*(pvoc+i),i,*(vocali+i));
        }

        return 0;
    }