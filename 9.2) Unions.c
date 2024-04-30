#include<stdio.h>
#include<stdlib.h>
    //Creo una Union
    union Coins{
        struct{
            int quarter;
            int nickel;
            int dime;
            int penny;
        };

        int coins[4];
    };

    int main(){
        union Coins change;

        for(int i = 0; i < sizeof(change)/sizeof(int); i++){
            scanf("%i", change.coins+i);
        }

        printf("Ci  sono %i quarters, %i nickel, %i dime e %i penny.\n", change.quarter,change.nickel,change.dime,change.penny);

        return 0;
    }
