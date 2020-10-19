#include "screen.h"

#ifdef _WIN32
  #include <windows.h>

void clrscr()
{
  HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  SetConsoleCursorPosition( hStdOut, homeCoords );
}

void movexy(int x, int y) {
  COORD c;
  c.X = x - 1;
  c.Y = y - 1;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}

#else
  #include <stdio.h>
  #define clrscr() printf("\e[1;1H\e[2J")
  void movexy(int x, int y)
  {
    printf("%c[%d;%df",0x1B,y,x);
  }
#endif

void limparBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {}
}

int menu() {

  int opcao;
  clrscr();
  printf("1 - Imprimir Grafo\n");
  printf("2 - Listar Cidades\n");
  printf("3 - Definir Rota\n");
  printf("4 - Sair\n");

  printf("\n-> ");
  scanf("%d", &opcao);
  limparBuffer();

  return opcao;
}

void listarCidades(ARQDIJ *arqdij) {

  CIDADE *cidades = arqdij->cidades;

  clrscr();
  printf("TOTAL DE CIDADES: %d\n", arqdij->quantidade);

  for (int i = 0; i < arqdij->quantidade; i++) {
    printf("\n (%d) | %s \n X: %f | Y: %f\n", i, cidades[i].nome, cidades[i].coords.x, cidades[i].coords.y);
  }

  getchar();
}

void menuDefinirRota(int *origem, int *destino) {

  clrscr();

  printf("\nInforme o numero da cidade");

  printf("\n\nOrigem: ");
  printf("\nDestino: ");

  movexy(9, 4);
  scanf("%d", origem);
  limparBuffer();


  movexy(10, 5);
  scanf("%d", destino);
  limparBuffer();
}

void imprimirGrafo(GRAFO *grafo) {

  clrscr();
  for (int i = 0; i < grafo->qtdeVertices; ++i) {
    printf("\n\n\nV 0%d", i);

    CIDADE cidade = grafo->vertices[i].cidade;
    printf("\nCIDADE: %s | X: %f | Y: %f", cidade.nome, cidade.coords.x, cidade.coords.y);

    ADJACENCIA *listaAdjacencia = grafo->vertices[i].cabeca;

    printf("\nInicio");
    while (listaAdjacencia) {
      printf(" -> %d | %f", listaAdjacencia->destino, listaAdjacencia->peso);
      listaAdjacencia = listaAdjacencia->proximo;
    }
  }

  getchar();
}

void imprimirCaminhosDijkstra(GRAFO *grafo, DIJKSTRA *d, int destino) {

  int *caminho = (int *) malloc(sizeof(int));
  caminho[0] = destino;

  int max = 1;
  int aux = destino;

  while (d->pred[aux] > -1) {
    caminho = (int *) realloc(caminho, ((max + 1) * sizeof(int)));
    caminho[max] = d->pred[aux];
    aux = d->pred[aux];
    max++;
  }

  for(int j = max-1; j >= 0; j--) {
    int nV = caminho[j];
    char *cidade = grafo->vertices[nV].cidade.nome;

    printf(" -> %s", cidade);
  }
}
