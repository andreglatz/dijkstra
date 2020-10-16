#include <time.h>
#include <stdlib.h>
#include "bool.h"

typedef struct sAdj {
  int destino;
  double peso;
  struct sAdj *proximo;
} ADJACENCIA;


typedef struct sVertex {
  int info;
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

GRAFO *criarGrafo(int quantidadeVertices) {
  GRAFO *grafo = (GRAFO *) malloc(sizeof(GRAFO));
  grafo->qtdeVertices = quantidadeVertices;

  grafo->vertices = (VERTICE *) malloc(quantidadeVertices * sizeof(VERTICE));

  for (int i = 0; i < quantidadeVertices; ++i) {
    grafo->vertices[i].cabeca = NULL;
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

void gerarArestasAleatorias(GRAFO *grafo) {
  int qtdeArestas  = quantidadeArestas(grafo, 50);
  int qtdeVertices = grafo->qtdeVertices;

  srand(time(NULL));

  int verticeOrigem = 0;
  int verticeDestino = 0;

  for (int i = 0; i < qtdeArestas; ++i) {
    verticeOrigem  = rand() % qtdeVertices;
    verticeDestino = rand() % qtdeVertices;

    ADJACENCIA *listaAdjacencia = grafo->vertices[verticeOrigem].cabeca;

    if (verticeOrigem != verticeDestino && !buscarAdjacencia(listaAdjacencia, verticeDestino)) {
      criarArestas(grafo, verticeOrigem, verticeDestino, 2.0);
    } else {
      --i;
    }
  }
}

void imprimirGrafo(GRAFO *grafo);
