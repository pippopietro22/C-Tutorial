#include<stdio.h>
#include<stdlib.h>
    //Creo un tipo di nodo
    typedef struct node{
        int val;
        struct node* next;
    }node_t;


    //Creo una Funzione che elimini il primo nodo
    int pop_first(node_t**head){
        
        int retval = -1;    //Indicatore errore
        node_t* next_node = NULL;

        //Se i nodi sono tutti nulli
        if (*head == NULL){
            return -1;
        }

        //Salvo tutti i nodi successivi al primo
        next_node = (*head)->next;
        retval = next_node->val;

        //Libero tutta la serie iniziale
        free(*head);
        *head = next_node;  //Per poi passarli tutto il resto

        return retval;
    }


    //Creo una funzione che rimuove un nodo con un cerrto valore
    int remove_by_value (node_t**head, int val){  

        int retval = -1;        //Dichiaro indicatore di errore
        node_t* current = *head;    //Nodo corrente
        node_t* temp_node;      //Nodo temporaneo

        //Controllo se il primo nodo è vuoto
        if (current == NULL){
            return -1;
        }

        //Se il nodo da eliminare è il primo
        if (current->val == val){
            return pop_first(head);
        }

        //Scorro al nodo precedente al nodo con il valore che cerco
        while (current->next->val != val){
            
            //Controllo che il nodo successivo esista
            if(current->next == NULL){
                return -1;
            }
            
            //Passo al nodo successivo
            current = current->next;
        }

        //Salvo il nodo da eliminare in quello temporaneo
        temp_node = current->next;
        retval = temp_node->val;    //E salvo il valore del nodo da eliminare

        //Passo tutti i nodi successivi a quello da eliminare al next di quello corrente
        current->next = temp_node->next;

        //Libero il nodo temporaneo
        free(temp_node);

        return retval;
    }