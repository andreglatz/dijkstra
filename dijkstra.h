#include "grafo.h"

typedef struct sDijkstra {
  double *distancias;
  int *pred;
} DIJKSTRA;

void inicializarDijkstra(GRAFO *grafo, double *distancia, int *pred, int vI) {
  for (int v = 0; v < grafo->qtdeVertices; v++) {
    distancia[v] = INT_MAX / 2;
    pred[v] = -1;
  }

  distancia[vI] = 0;

}

void relaxarAdjacentes(GRAFO *grafo, double *distancia, int *pred, int vertice, int verticeAdj) {
  ADJACENCIA *adj = grafo->vertices[vertice].cabeca;

  while (adj && adj->destino != verticeAdj)
    adj = adj->proximo;

  if (adj) {
    if (distancia[verticeAdj] > distancia[vertice] + adj->peso) {
      distancia[verticeAdj] = distancia[vertice] + adj->peso;
      pred[verticeAdj] = vertice;
    }
  }
}

bool existeAberto(GRAFO *grafo, bool *aberto) {

  for (int i = 0; i < grafo->qtdeVertices; ++i)
    if (aberto[i]) return true;

  return false;
}

int menorDist(GRAFO *grafo, bool *aberto, double *distancia) {

  int i;
  for (i = 0; i < grafo->qtdeVertices; ++i)
    if (aberto[i]) break;

  if (i == grafo->qtdeVertices) return -1;

  int menor = i;

  for (i = menor + i; i < grafo->qtdeVertices; ++i)
    if (aberto[i] && (distancia[menor] > distancia[i]))
      menor = i;

  return menor;
}


DIJKSTRA *dijkstra(GRAFO *grafo, int verticeInicial) {

  double *distancia = (double *) malloc((grafo->qtdeVertices * sizeof(double)));
  int *pred         = (int *) malloc((grafo->qtdeVertices * sizeof(int)));
  bool *aberto      = (bool *) malloc((grafo->qtdeVertices * sizeof(bool)));

  inicializarDijkstra(grafo, distancia, pred, verticeInicial);

  for (int i = 0; i < grafo->qtdeVertices; ++i)
    aberto[i] = true;

  while (existeAberto(grafo, aberto)) {
    int vMenorD = menorDist(grafo, aberto, distancia);
    aberto[vMenorD] = false;

    ADJACENCIA *adj = grafo->vertices[vMenorD].cabeca;

    while (adj) {
      relaxarAdjacentes(grafo, distancia, pred, vMenorD, adj->destino);
      adj = adj->proximo;
    }
  }

  DIJKSTRA *dijkstra   = (DIJKSTRA *) malloc(sizeof(DIJKSTRA));
  dijkstra->distancias = distancia;
  dijkstra->pred       = pred;

  return dijkstra;
}
