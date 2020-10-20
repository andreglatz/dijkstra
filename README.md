# DIJKSTRA

O algoritmo de Dijkstra tem como objetivo definir o menor caminho entre dois pontos com base no peso das arestas de um grafo.

Através dos estudos do curso de estrutura de dados do **Instituto Federal de São Paulo - Campus Campos do Jordão**, ministrado pelo professor **Marques de Sousa**. A aplicação proposta tem por objetivo ler um arquivo que contém, em sua primeira linha, o número de cidades a ser considerada e nas demais linhas o nome das cidades e seus pontos X e Y de um plano 2D.

Para esta aplicação foi utilizado o compilador GCC (9.3.0) e as demais bibliotecas:

- stdlib
- stdio
- math
- time
- windows
- limits

Além de bibliotecas criadas específicamente para este trabalho como:

- arquivo (manipulação de arquivo voltade para leitura de cidades)

- bool (definição do tipo boolean em C)

- cidade (definição da estrutura de cidade e coordenadas)

- grafo (definição de grafo voltada para cidades)

- dijkstra (definição do algoritmo de Dijkstra utilizando a lib grafo)

- screen (realiza funções de posicionamento do cursor e limpeza de console, além de menus para aplicação)

## Execução

Para executar a aplicação é necessário clonar o repositório:

`git clone https://github.com/andreglatz/dijkstra.git`

Em seguida é preciso compilar o software. Deixo como sugestão compilar com o seguinte comando, pois nele é atribuída todas as libs necessárias para a execução:

`gcc main.c -I ./includes/headers -L ./includes/libs -larquivo -ldijkstra -lgrafo -lscreen -lm -o dijkstra_cidades`

---

### Contatos

Linkedin: https://www.linkedin.com/in/andreglatz/ <br>
E-mail: andreglatz@outlook.com
