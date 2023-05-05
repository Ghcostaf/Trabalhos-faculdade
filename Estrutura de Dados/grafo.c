#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTICES 1000

typedef struct {
    int matriz[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} GrafoMatriz;

typedef struct no {
    int vertice;
    struct no* prox;
} No;

typedef struct {
    No* lista[MAX_VERTICES];
    int num_vertices;
} GrafoLista;

No* novoNo(int v) {
    No* novo = (No*) malloc(sizeof(No));
    novo->vertice = v;
    novo->prox = NULL;
    return novo;
}

void adicionarArestaLista(GrafoLista* grafo, int origem, int destino) {
    No* novo = novoNo(destino);
    novo->prox = grafo->lista[origem];
    grafo->lista[origem] = novo;
}

void imprimirCaminhoBFS(int* antecessor, int s, int t) {
    if (s == t) {
        printf("%d ", s);
    } else if (antecessor[t] == -1) {
        printf("Não há caminho entre os vértices.");
    } else {
        imprimirCaminhoBFS(antecessor, s, antecessor[t]);
        printf("%d ", t);
    }
}

void BFSMatriz(GrafoMatriz* grafo, int s, int t) {
    int fila[MAX_VERTICES];
    bool visitado[MAX_VERTICES] = {false};
    int antecessor[MAX_VERTICES];
    int inicio = 0, fim = 0;

    for (int i = 0; i < grafo->num_vertices; i++) {
        antecessor[i] = -1;
    }

    visitado[s] = true;
    fila[fim++] = s;

    while (inicio != fim) {
      
        int vertice_atual = fila[inicio++];
        if (vertice_atual == t) {
            imprimirCaminhoBFS(antecessor, s, t);
            return;
        }

        for (int i = 0; i < grafo->num_vertices; i++) {
            if (grafo->matriz[vertice_atual][i] == 1 && !visitado[i]) {
                visitado[i] = true;
                antecessor[i] = vertice_atual;
                fila[fim++] = i;
            }
        }
    }
    imprimirCaminhoBFS(antecessor, s, t);
}

