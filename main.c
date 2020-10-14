#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

GRAFO *criarGrafo(int quantidadeVertices){
  GRAFO *grafo = (GRAFO *) malloc(sizeof(GRAFO));
  grafo->quantidadeVertices = quantidadeVertices;

  grafo->vertices = (VERTICE *) malloc(quantidadeVertices * sizeof(VERTICE));

  for (int i = 0; i < quantidadeVertices; ++i) {
    grafo->vertices[i].cabeca = NULL;
  }

  return grafo;
}

VERTICE *criarVerticeAdjacente(int destino) {
  ADJACENCIA *vertice = (VERTICE *) malloc(sizeof(VERTICE));
  vertice->proximo = NULL;
  vertice->destino = destino;

  return vertice;
}


bool criarArestas(GRAFO *grafo, int origem, int destino) {

  if (!grafo) {
      return false;
  }

  if ((destino < 0) || (destino >= grafo->quantidadeVertices)) {
    return false;
  }

  if ((origem < 0) || (origem >= grafo->quantidadeVertices)) {
    return false;
  }

  ADJACENCIA *verticeAdjacente = criarVerticeAdjacente(destino);

  verticeAdjacente->proximo = grafo->vertices[origem].cabeca;
  grafo->vertices[origem].cabeca = verticeAdjacente;
  grafo->quantidadeArestas++;
}

void imprimirGrafo(GRAFO *grafo) {

  for (int i = 0; i < grafo->quantidadeVertices; ++i) {
    printf("\nV 0%d", i);

    ADJACENCIA *listaAdjacencia = grafo->vertices[i].cabeca;

    printf("\nInicio");
    while (listaAdjacencia) {
      printf(" -> %d", listaAdjacencia->destino);
      listaAdjacencia = listaAdjacencia->proximo;
    }
  }
}

int main(void) {
  int quantidadeVertices = 10;
  GRAFO *grafo = criarGrafo(quantidadeVertices);

	criarArestas(grafo, 0, 1);
	criarArestas(grafo, 0, 4);
	criarArestas(grafo, 1, 2);
	criarArestas(grafo, 1, 3);
	criarArestas(grafo, 1, 4);
	criarArestas(grafo, 2, 3);
	criarArestas(grafo, 3, 4);

	imprimirGrafo(grafo);

  return 0;
}
