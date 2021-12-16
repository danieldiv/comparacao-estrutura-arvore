# comparacao-estrutura-arvore
Comparação das estruturas tipo arvore

## Valores aleatórios

- Para gerar valores aleatórios utilize o método randomValue do arquivo file.c, será gerado valores aleatórios para inserção das arvores. A quantidade de valores varia entre, 1000, 100000 e 1000000.

- Para a pesquisa são gerados valores aleatórios entre 5000, 10000 e 100000 valores. Nos arquivos atuais de pesquisa foram modificados alguns destes valores para permitir a existência de valores repetidos, validos e não validos.

## Menu

![Scrennshot](src/img/menu-opcao-principal.png)

- Ao inicializar o programa, terá quatro opções:
    - 0 -> Finaliza o programa
    - 1 -> Mostra as opções para o tamanho da entrada
    - 2 -> Mostra as opções para o tamanho da pesquisa
    - 3 -> Inicializa uma arvore teste com 9 valores: {11,2,14,1,7,15,5,8,4} e exclui o elemento 8 da arvore RB

![Scrennshot](src/img/menu-opcao-entrada.png)

- Ao selecionar uma determinada entrada, será inserido os valores nas 3 arvores disponíveis. Caso a opção seja 0 ou diferente das 3 possíveis, não será inserido valores na arvore e manterá o que já tinha salvo caso exista.

![Scrennshot](src/img/menu-opcao-pesquisa.png)

- Estando com as arvores preenchidas pelas entradas disponíveis ou pelo arquivo teste, será possível realizar três pesquisas, quer terá como resultado a quantidade de pesquisa e tempo utilizado por cada arvore.

## Informações

> S - Simples

> AVL - AVL

> RB - RedBlack
