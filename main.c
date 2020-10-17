#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "dijkstra.c"

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

int main(void) {
  int quantidadeVertices = 7;
  CIDADE *cidades = criarCidades(quantidadeVertices);

  GRAFO *grafo = criarGrafo(quantidadeVertices, cidades);

  gerarArestasAleatorias(grafo);

  double *r = dijkstra(grafo, 0);

  for (int i = 0; i < grafo->qtdeVertices; i++)
    printf("D(v0 -> v%d) = %f\n", i, r[i]);

	imprimirGrafo(grafo);

  return 0;
}
