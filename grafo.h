typedef struct sAdj {
  int destino;
  struct sAdj *proximo;
} ADJACENCIA;


typedef struct sVertex {
  int info;
  ADJACENCIA *cabeca;
} VERTICE;

typedef struct sGraph {
  int quantidadeVertices;
  int quantidadeArestas;
  VERTICE *vertices;
} GRAFO;

VERTICE *criarVerticeAdjacente(int destino);
GRAFO *criarGrafo(int quantidadeVertices);
void criarArestas(GRAFO *grafo, int origem, int destino);
void imprimirGrafo(GRAFO *grafo);
