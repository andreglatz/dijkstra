#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"
#include "arquivo.h"
#include "screen.h"


void definirRota(GRAFO *grafo) {
  int origem, destino;

  menuDefinirRota(&origem, &destino);

  printf("\nORIGEM: (%d) %s | DESTINO: (%d) %s\n\n", origem, grafo->vertices[origem].cidade.nome,
         destino, grafo->vertices[destino].cidade.nome);

  if (origem != destino) {
    DIJKSTRA *dij = dijkstra(grafo, origem);

    if (dij->distancias[destino] == (INT_MAX / 2)) {
      printf("Nao existe rota para essa cidade.");
    } else {
      imprimirCaminhosDijkstra(grafo, dij, destino);
    }

    getchar();
  }
}

int main(void) {

  ARQDIJ *arqdij = obterCidades("cidades.dij");
  GRAFO *grafo = criarGrafo(arqdij->quantidade, arqdij->cidades);
  gerarArestasAleatorias(grafo);

  CIDADE *cidades = arqdij->cidades;

  int opcao = 0;
  do {

    opcao = menu();

    switch (opcao) {
      case 1:
        imprimirGrafo(grafo);
        break;
      case 2:
        listarCidades(arqdij);
        break;
      case 3:
        definirRota(grafo);
        break;
    }

  } while(opcao != 4);

  return 0;
}
