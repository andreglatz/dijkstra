#include "arquivo.h"

char** strSplit(char* str, const char *delim)
{
  char **palavras = (char **) malloc(sizeof(char*));
  char *token = strtok(str, delim);

  int i = 0;
  while(token) {
    palavras[i] = token;

    i++;
    palavras = (char **) realloc(palavras, ((i + 1) * sizeof(char *)));

    token = strtok(NULL, delim);
  }

  palavras[i] = NULL;
  return palavras;
}

FILE *abrirArquivo(char *nomeArquivo) {
  FILE *arquivo = fopen(nomeArquivo, "r");

  if (!arquivo) {
    printf("ERRO! Nao foi possivel abrir o arquivo!\n");
    return NULL;
  } else {
    return arquivo;
  }
}

ARQDIJ *obterCidades(char *nomeArquivo) {

  FILE *arquivo = abrirArquivo(nomeArquivo);
  char **palavras;
  int quantidade;
  fscanf(arquivo, "%d", &quantidade);

  CIDADE *cidades = (CIDADE *) malloc(quantidade * sizeof(CIDADE));

  char info[75];
  fgets(info, sizeof(info), arquivo);

  for (int i = 0; i < quantidade; i++) {
    info[75];
    fgets(info, sizeof(info), arquivo);

    palavras = strSplit(info, ";");

    strcpy(cidades[i].nome, palavras[0]);

    cidades[i].coords.x = atof(palavras[1]);
    cidades[i].coords.y = atof(palavras[2]);

  }

  fclose(arquivo);

  ARQDIJ *arqdij = (ARQDIJ *) malloc(sizeof(ARQDIJ));
  arqdij->quantidade = quantidade;
  arqdij->cidades = cidades;

  return arqdij;
}
