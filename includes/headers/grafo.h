#ifndef GRAFO_H
#define GRAFO_H

#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "bool.h"
#include "cidade.h"

typedef struct sAdj {
  int destino;
  double peso;
  struct sAdj *proximo;
} ADJACENCIA;


typedef struct sVertex {
  CIDADE cidade;
  ADJACENCIA *cabeca;
} VERTICE;

typedef struct sGraph {
  int qtdeVertices;
  int qtdeArestas;
  VERTICE *vertices;
} GRAFO;

ADJACENCIA *criarVerticeAdjacente(int destino, double peso);

GRAFO *criarGrafo(int quantidadeVertices, CIDADE *cidades);

bool criarArestas(GRAFO *grafo, int origem, int destino, double peso);

int quantidadeArestas(GRAFO *grafo, char porcentagem);

bool buscarAdjacencia(ADJACENCIA *listaAdjacencia, int vertice);

double distanciaEuclidiana(COORDENADAS coordsInicial, COORDENADAS coordsFinal);

int tamanhoLista(ADJACENCIA *listaAdj);

void gerarArestasAleatorias(GRAFO *grafo);


#endif // GRAFO_H
