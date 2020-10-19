#ifndef ARQUIVO_H_INCLUDED
#define ARQUIVO_H_INCLUDED

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "cidade.h"

typedef struct sArqDij {
  int quantidade;
  CIDADE *cidades;
} ARQDIJ;

char** strSplit(char* str, const char *delim);
FILE *abrirArquivo(char *nomeArquivo);
ARQDIJ *obterCidades(char *nomeArquivo);

#endif // ARQUIVO_H_INCLUDED
