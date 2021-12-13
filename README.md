# comparacao-estrutura-arvore
Comparacao das estruturas tipo arvore

## Valores aleatorios

- Para gerar valores aleatorios utilize o metodo randomValue do arquivo file.c, sera gerado valores aleatorios para insercao das arvores. A quantidade de valores varia entre, 1000, 100000 e 1000000.

- Para a pesquisa sao gerados valores aleatorios entre 5000, 10000 e 100000 valores. Nos arquivos atuais de pesquisa foram modificados alguns destes valores para permitir a existencia de valores repetidos, validos e nao validos.

## Menu

![Scrennshot](src/img/menu-opcao-principal.png)

- Ao inicializar o programa, tera quatro opcoes:
    - 0 -> Finaliza o programa
    - 1 -> Mostra as opcoes para o tamanho da entrada
    - 2 -> Mostra as opcoes para o tamanho da pesquisa
    - 3 -> Inicializa uma arvore teste com 9 valores: {11,2,14,1,7,15,5,8,4}

![Scrennshot](src/img/menu-opcao-entrada.png)

- Ao selecionar uma determinada entrada, sera inserido os valores nas 3 arvores disponiveis. Caso a opcao seja 0 ou diferente das 3 possiveis, nao sera inserido valores na arvore e mantera o que ja tinha salvo caso exista.

![Scrennshot](src/img/menu-opcao-pesquisa.png)

- Estando com as arvores prenchidas pelas entradas disponieis ou pelo arquivo teste, sera possivel realizar tres pesquisas, quer tera como resultado a quantidade de pesquisa e tempo utilizado por cada arvore.

## Informacoes

> S - Simples

> AVL - AVL

> RB - RedBlack