#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <limits.h>
#include "grafo.h"

typedef struct sDijkstra {
  double *distancias;
  int *pred;
} DIJKSTRA;

void inicializarDijkstra(GRAFO *grafo, double *distancia, int *pred, int vI);

void relaxarAdjacentes(GRAFO *grafo, double *distancia, int *pred, int vertice, int verticeAdj);

bool existeAberto(GRAFO *grafo, bool *aberto);

int menorDist(GRAFO *grafo, bool *aberto, double *distancia);

DIJKSTRA *dijkstra(GRAFO *grafo, int verticeInicial);


#endif // DIJKSTRA_H
