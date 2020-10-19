#ifndef SCREEN_H
#define SCREEN_H

#ifdef _WIN32
  #include <windows.h>
#else
  #include <stdio.h>
#endif

#include "arquivo.h"
#include "grafo.h"
#include "dijkstra.h"

void clrscr();

void movexy(int x, int y);

void limparBuffer();

int menu();

void listarCidades(ARQDIJ *arqdij);

void menuDefinirRota(int *origem, int *destino);

void imprimirGrafo(GRAFO *grafo);

void imprimirCaminhosDijkstra(GRAFO *grafo, DIJKSTRA *d, int destino);

#endif // SCREEN_H
