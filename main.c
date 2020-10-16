#include <stdio.h>
#include "grafo.h"

void imprimirGrafo(GRAFO *grafo) {

  for (int i = 0; i < grafo->qtdeVertices; ++i) {
    printf("\nV 0%d", i);

    ADJACENCIA *listaAdjacencia = grafo->vertices[i].cabeca;

    printf("\nInicio");
    while (listaAdjacencia) {
      //printf(" -> %d | %f", listaAdjacencia->destino, listaAdjacencia->peso);
      printf(" -> %d", listaAdjacencia->destino);
      listaAdjacencia = listaAdjacencia->proximo;
    }
  }
}

int main(void) {
  int quantidadeVertices = 7;
  GRAFO *grafo = criarGrafo(quantidadeVertices);

  gerarArestasAleatorias(grafo);

	imprimirGrafo(grafo);

  return 0;
}
