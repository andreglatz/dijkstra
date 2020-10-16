#include <time.h>
#include <stdlib.h>
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

ADJACENCIA *criarVerticeAdjacente(int destino, double peso)  {
  ADJACENCIA *vertice = (ADJACENCIA *) malloc(sizeof(ADJACENCIA));
  vertice->proximo = NULL;
  vertice->destino = destino;
  vertice->peso    = peso;

  return vertice;
}

GRAFO *criarGrafo(int quantidadeVertices, CIDADE *cidades) {
  GRAFO *grafo = (GRAFO *) malloc(sizeof(GRAFO));
  grafo->qtdeVertices = quantidadeVertices;

  grafo->vertices = (VERTICE *) malloc(quantidadeVertices * sizeof(VERTICE));

  for (int i = 0; i < quantidadeVertices; ++i) {
    grafo->vertices[i].cabeca = NULL;
    grafo->vertices[i].cidade = cidades[i];
  }

  return grafo;
}

bool criarArestas(GRAFO *grafo, int origem, int destino, double peso)  {

  if (!grafo) {
      return false;
  }

  if ((destino < 0) || (destino >= grafo->qtdeVertices)) {
    return false;
  }

  if ((origem < 0) || (origem >= grafo->qtdeVertices)) {
    return false;
  }

  ADJACENCIA *verticeAdjacente = criarVerticeAdjacente(destino, peso);

  verticeAdjacente->proximo = grafo->vertices[origem].cabeca;
  grafo->vertices[origem].cabeca = verticeAdjacente;
  grafo->qtdeArestas++;
}

int quantidadeArestas(GRAFO *grafo, char porcentagem) {

  int qtdeVertices = grafo->qtdeVertices * (grafo->qtdeVertices - 1);
  float porcentagemFinal =  (float) porcentagem / 100;

  return qtdeVertices * porcentagemFinal;
}

bool buscarAdjacencia(ADJACENCIA *listaAdjacencia, int vertice) {

  ADJACENCIA *aux = listaAdjacencia;

  while (aux) {
    if (aux->destino == vertice)
      return true;

    aux = aux->proximo;
  }

  return false;
}

double distanciaEuclidiana(COORDENADAS coordsInicial, COORDENADAS coordsFinal) {
  double x = coordsFinal.x - coordsInicial.x;
  double y = coordsFinal.y - coordsInicial.y;

  return sqrt(pow(x, 2) + pow(y, 2));
}

void gerarArestasAleatorias(GRAFO *grafo) {
  int qtdeArestas  = quantidadeArestas(grafo, 50);
  int qtdeVertices = grafo->qtdeVertices;

  srand(time(NULL));

  int origem = 0;
  int destino = 0;

  for (int i = 0; i < qtdeArestas; ++i) {
    origem  = rand() % qtdeVertices;
    destino = rand() % qtdeVertices;

    ADJACENCIA *listaAdjacencia = grafo->vertices[origem].cabeca;

    if (origem != destino && !buscarAdjacencia(listaAdjacencia, destino)) {

      VERTICE verticeOrigem  = grafo->vertices[origem];
      VERTICE verticeDestino = grafo->vertices[destino];

      double distancia = distanciaEuclidiana(verticeOrigem.cidade.coords, verticeDestino.cidade.coords);
      criarArestas(grafo, origem, destino, distancia);

    } else { --i; }
  }
}

void imprimirGrafo(GRAFO *grafo);
