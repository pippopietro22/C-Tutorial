#include<stdio.h>
#include<stdlib.h>  //Si inserisce questa libreria per l'allocazione dinamica
    //Inizializzo un puntatore array bidimensionale
    int **tri;
    int nrow;   //Numero di colonne del mio array 
    int i,j;    //Inizializzo dei contatori di cicli 

    int main(){
        //Inserisco il numero di righe che voglio stampare del triangolo di Pascal
        printf("Quante riche di triangolo di Pascal vuoi? ");
        scanf("%d",&nrow);

        //Alloco memoria
        tri=(int**)malloc(nrow*sizeof(int*));

        if (tri == NULL) {                      //Controllo che tri sia stato allocato correttamente
        printf("Memoria non disponibile\n");
        return 1; //Se non viene allocato correttamente, da errore
        }

        for(i = 0; i < nrow; i++){                  //Alloco il numero di colonne per ogni riga
            tri[i]=(int*)malloc((i+2)*sizeof(int));
        }

        //Setto a zero il triangolo
        for(i = 0; i < nrow; i++){
            for(j = 0; j < (i+2); j++){
                tri[i][j]=0;
            }
        }

        //Inizializzo il riempimento
        tri[0][0]=1;

        for(i = 1; i < nrow; i++){
            tri[i][0]=1;

            for(j = 1; j < (i+2); j++){
                tri[i][j]=tri[i-1][j-1]+tri[i-1][j];
            }
        }

        //Stampo il triangolo
        for(i = 0; i < nrow; i++){
            for(j = 0; j < (i+1); j++){
                printf("%d ",tri[i][j]);
            }
            printf("\n");
        }

        //Libero la memeoria
        for(i=0;i<nrow;i++){
            free(tri[i]);
        }

        free(tri);

        return 0;
    }