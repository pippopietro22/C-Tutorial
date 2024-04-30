#include<stdio.h>
#include<stdlib.h>

    //Definisco la struttura di un nodo
    typedef struct node{
        int val;                //Valore all'interno del nodo
        struct node*next;       //Puntatore al nodo successivo
    }node_t;


    //Creo una funzione che stampa tutti i valori dei nodi 
    void print_list(node_t* head){          //Come argomento, gli do il mio nodo
        
        node_t* current = head;     //Creo un puntatore ausigliario che tenga conto della cella che sto leggendo

        //Itero finche non becco la cella finale
        while(current != NULL){
            //Se non sono alla fine, stampo il valore
            printf("%d\n",current->val);
            
            //Passo poi al nodo successivo
            current = current->next;
        }
    }


    //Creo una funzione che aggiunga un nodo alla fine dela mia catena
    void push_last(node_t*head, int val){

        //Creo un puntatore che scorra i nodi fino ad arrivare alla fine
        node_t* current = head;

        //Vado fino all'ultima posizione
        while(current->next != NULL){
            current = current->next;
        }

        //Adesso aggiungo il nodo successivo
        current->next = (node_t*)malloc(sizeof(node_t));
        current->next->val = val;
        current->next->next = NULL;
    }


    //Creo una funzione che aggiunge un nodo all'inizio della mia serie
    void push_first(node_t** head, int val){

        //Creo il nuovo nodo e lo alloco
        node_t* new_node = (node_t*)malloc(sizeof(node_t));

        //Passo il nuovo valore al nodo
        new_node->val = val;
        new_node->next = *head;         //Imposto la vecchia serie di nodi come "successivo" al nuovo nodo

        //Il nuovo nodo diventa "Ufficialmente" il primo
        *head = new_node;               
    }


    //Creo una funzione che elimina il primo nodo
    int pop_first(node_t** head){
        int retval = -1;            //creo un intero che mi dica se mi da errore o meno

        //Creo un puntatore ausigliario
        node_t*next_node = NULL;

        //Se la mia serie di nodi è nulla allora la funzione si ferma
        if(*head == NULL){
            return -1;
        }
    
        //Passo al puntatore ausigliario tutta la serie dal secondo nodo in poi
        next_node = (*head)->next;
        retval = next_node->val;    //passo al mio intero il valore del secondo nodo (che diventerà primo)

        //Libero tutta la mia serie iniziale
        free(*head);
        *head = next_node;      // per poi passarli di nuovo tutti i valori tranne il primo

        return retval;
    }


    //Creo una funzione che elimini l'ultimo nodo della mia serie
    int pop_last(node_t* head){

        node_t* current = head;   
        int retval;             //Indicatore

        //Controllo che non ci sia un unico nodo
        if (head->next == NULL){
            retval = head->val;
            free(head);
            return retval;
        }
          
        //Vado fino al penultimo elemento (che diventerà ultimo)  
        while (head->next->next != NULL){                  //Controllo semmpre 2 elementi davanti a me
            current = current->next;
        }

        //Adesso rimuovo l'ultimo nodo
        retval = current->next->val;    //Ma prima salvo il valore
        free(current->next);
        current->next = NULL;

        return retval;
    }


    //Creo una funzione che elimina un nodo interno alla serie
    int pop_in_index (node_t**head, int n){

        int retval = -1;  //Dichiaro variabili

        node_t* current = *head;    //Dichiaro il puntatore che mi tiene il nodo correnteù
        node_t* temp_node = NULL;    //Dichiaro il nodo temporaneo dove salvare il nodo da eliminare

        //Se il nodo da eliminare è il primo:
        if (n == 0){
            return pop_first(head);
        }

        //Vado al nodo precedente a quello da rimuovere
        for(int i = 0; i < n; i++){
            if (current->next != NULL){
                current = current->next;
            }
        }

        //Se il nodo da rimuovere non c'è:
        if (current->next == NULL){
            return -1;
        }

        //Salvo il nodo da eliminare su quello temporaneo
        temp_node = current->next;
        retval = temp_node->val;    //Salvo il valore del nodo da eliminare

        //Passo tutti i nodi successivi a quello da eliminare al next di quello corrente
        current->next = temp_node->next;

        //Libero il nodo temporaneo
        free(temp_node);

        return retval;
    }


    int main(){
        //Dichiaro il puntatore di tipo nodo
        node_t* head = NULL;

        //Alloco la dimensione del mio nodo
        head = (node_t*)malloc(sizeof(node_t));

        //Controllo se il nodo è terminato (VA FATTO SEMPRE)
        if (head == NULL){
            return 0;
        }

        //Assegno un valore al mio nodo
        head->val = 1;
        head->next = NULL;      //se metto che il puntatore al nodo successivo è NULL allora è terminato


        
        //Se voglio continuare, alloco il puntatore del mio nodo
        head->next = (node_t*)malloc(sizeof(node_t));
        
        //Assegno un valore al secondo puntatore
        head->next->val = 2;
        head->next->next = NULL;                   //Ad un certo punto mi romperò il cazzo e chiudero i nodi con NULL

        return 0;
    }