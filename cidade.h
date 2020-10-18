#ifndef CIDADE_H
#define CIDADE_H

typedef struct sCoods {
  double x;
  double y;
} COORDENADAS;

typedef struct sCidade {
    char nome[50];
    COORDENADAS coords;
} CIDADE;

#endif // CIDADE_H
