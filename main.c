#include <stdio.h>
#include <math.h>
#include "grafo.h"

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

CIDADE *criarCidades(int qtdeVertices) {

  CIDADE *cidades = (CIDADE *) malloc(qtdeVertices * sizeof(CIDADE));

  for (int i = 0; i < qtdeVertices; ++i) {

    char cidade[50] = "CIDADE ";
    cidade[7] = i + 65;
    strcpy(cidades[i].nome, cidade);

    double x = i * 0.5 + 2;
    double y = i * 0.7 + 2;

    cidades[i].coords.x = x <= 0 ? x + 0.01 : x;
    cidades[i].coords.y = y <= 0 ? y + 0.01 : y;
  }

  return cidades;
}

int main(void) {
  int quantidadeVertices = 7;
  CIDADE *cidades = criarCidades(quantidadeVertices);

  GRAFO *grafo = criarGrafo(quantidadeVertices, cidades);

  gerarArestasAleatorias(grafo);

	imprimirGrafo(grafo);

  return 0;
}
