#include <stdio.h>
#include <stdlib.h>
    //Definiszo il mio Binary Tree
    typedef struct node{
        int val;
        struct node * left;
        struct node * right;
    } node_t;


    //Pre-Dichiaro le mie funzioni
    void insert(node_t * tree,int val);
    void printDFS(node_t * current);


    int main(){
        node_t * test_list = (node_t *) malloc(sizeof(node_t)); //Dichiaro un Binary Tree

        //Setto il nodo iniziale
        test_list->val = 0;
        test_list->left = NULL;
        test_list->right = NULL;

        //Riempio con un set di dati
        insert(test_list,5);
        insert(test_list,8);
        insert(test_list,4);
        insert(test_list,3);

        //Stampo il mio albero in Pre-Order
        printDFS(test_list);
        printf("\n");

        return 0;
    }


    //Definisco funzione per insermineto dati
    void insert(node_t * tree, int val){

        //Inserisco in posizione vuto
        if (tree->val == 0){
            tree->val = val;
        }else{

            //Scelgo la posizione
            if (val < tree->val){
                
                //A sinistra
                if (tree->left != NULL){        //Controllo che sia libera, altrimenti reitero
                    insert(tree->left, val);
                }else{
                    tree->left = (node_t *) malloc(sizeof(node_t));     //Se è libera procedo
                    tree->left->val = val;
                    tree->left->left = NULL;
                    tree->left->right = NULL;
                }
            }else{
                
                //A destra
                if (tree->right != NULL){       //Controllo che sia libera, altrimenti reitero
                    insert(tree->right,val);
                }else{
                    tree->right = (node_t *) malloc(sizeof(node_t));    //Se è libera procedo
                    tree->right->val = val;
                    tree->right->left = NULL;
                    tree->right->right = NULL;
                }
            }
        }
    }


    //Definisco una funzione per stampare un albero (Pre-Order)
    void printDFS(node_t * current){

        //Controllo se il primo nodo è vuoto
        if (current == NULL){
            return;
        }else{
            printf("%d ", current->val);    //Sennò stampo
        }

        if (current->left != NULL)   printDFS(current->left);
        if (current->right != NULL)  printDFS(current->right);
    }