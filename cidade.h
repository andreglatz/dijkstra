#include <string.h>

typedef struct sCoods {
  double x;
  double y;
} COORDENADAS;

typedef struct sCidade {
    char nome[50];
    COORDENADAS coords;
} CIDADE;

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
