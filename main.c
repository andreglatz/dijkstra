#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "dijkstra.h"

void imprimirGrafo(GRAFO *grafo) {

  for (int i = 0; i < grafo->qtdeVertices; ++i) {
    printf("\nV 0%d", i);

    CIDADE cidade = grafo->vertices[i].cidade;
    printf("\nCIDADE: %s | X: %f | Y: %f", cidade.nome, cidade.coords.x, cidade.coords.y);

    ADJACENCIA *listaAdjacencia = grafo->vertices[i].cabeca;

    printf("\nInicio");
    while (listaAdjacencia) {
      printf(" -> %d | %f", listaAdjacencia->destino, listaAdjacencia->peso);
      listaAdjacencia = listaAdjacencia->proximo;
    }
  }
}

void imprimirCaminhosDijkstra(GRAFO *grafo, DIJKSTRA *d) {

  for (int i = 1; i < grafo->qtdeVertices; ++i){
    printf("\nD(v0 -> v%d) = %f\n", i, d->distancias[i]);

    int *caminho = (int *) malloc(sizeof(int));
    caminho[0] = i;

    int max = 1;
    int aux = i;

    while (d->pred[aux] > -1) {
      caminho = (int *) realloc(caminho, ((max + 1) * sizeof(int)));
      caminho[max] = d->pred[aux];
      aux = d->pred[aux];
      max++;
    }

    for(int j = max-1; j >= 0; j--) {
      printf(" -> %d", caminho[j]);
    }
  }

}

int main(void) {
  int quantidadeVertices = 7;

  CIDADE *cidades = criarCidades(quantidadeVertices);
  GRAFO *grafo = criarGrafo(quantidadeVertices, cidades);

  gerarArestasAleatorias(grafo);
  DIJKSTRA *d = dijkstra(grafo, 0);

  imprimirCaminhosDijkstra(grafo, d);
	imprimirGrafo(grafo);

  return 0;
}
