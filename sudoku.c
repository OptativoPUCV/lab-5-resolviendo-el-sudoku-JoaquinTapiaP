#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
    int sudo[9][9];
} Node;

Node* createNode(){
    Node* n=(Node*) malloc(sizeof(Node));
    return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
    Node* n = createNode();
    FILE* file = fopen (file_name, "r");
    int i , j;
    for (i = 0; i < 9; i++){
        for(j = 0;j<9;j++){
            if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
        }
    } 

    fclose (file);
    return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++)
            printf("%d ", n->sudo[i][j]);
        printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
    /*int seen[10];
    for (int i = 0; i < 9; i++) {
        for (int k = 0; k < 9; k++) {
            seen[k] = 0;
        }
        for (int j = 0; j < 9; j++) {
            int num = n->sudo[i][j];
            if (num != 0) {
                if (seen[num]) return 0;
                seen[num] = 1;
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int k = 0; k < 9; k++) {
            seen[k] = 0;
        }
        for (int j = 0; j < 9; j++) {
            int num = n->sudo[j][i];
            if (num != 0) {
                if (seen[num]) return 0;
                seen[num] = 1;
            }
        }
    }

    for (int fila = 0; fila < 9; fila += 3) {
        for (int colum = 0; colum < 9; colum += 3) {
            int seen[10];
            for (int i = fila; i < fila + 3; i++){
                for (int j = colum; j < colum + 3; j++){
                    int num = n->sudo[i][j];
                    if (num != 0) {  
                        if (seen[num]) return 0;
                        seen[num] = 1;
                    }
                }
            }
        }
    }*/

    int seen[10];

    for (int i = 0; i < 9; i++) {
        for (int k = 0; k < 9; k++) {
            seen[k] = 0;
        }
        for (int j = 0; j < 9; j++) {
            int num = n->sudo[i][j];
            if (num && seen[num]){
                return 0;
            }
            seen[num] = 1;
            int h = 3 * (i/3) + (j/3);
            int p; 
            for (p = 0; p < 9; p++){
                int i = 3 * (h / 3) + (h / 3) ;
                int j = 3 * (h % 3) + (h % 3) ;
                printf("%d ",n->sudo[i][j]);
                if(p % 3 == 2) 
                    printf("\n");
            }
            
        }

    }
    return 1;
}


List* get_adj_nodes(Node* n) {
    List* list = createList();  // Crear una lista para almacenar los nodos adyacentes

    // Recorremos todas las celdas del Sudoku
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            // Excluimos la celda misma (n->sudo[row][col])
            if (n->sudo[row][col] == 0) {  // Solo consideramos las celdas no vacías
                for (int val = 1; val < 9; val++) {
                    Node* newNode = copy(n);
                    newNode->sudo[row][col] = val;

                    if (is_valid(newNode)){
                        pushBack(list, newNode);
                    }
                    else 
                        free(newNode);
                }
                  // Agregamos a la lista
            }
        }
    }

    return list;  // Devolvemos la lista con los nodos adyacentes
}



int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
    return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/