<h1 align="center"> Comparação das estruturas tipo árvore</h1>

Daniel Alves Sanches

Eng. Computação - 4º período - AEDS II

## Questões

- 3.1) - Qual das estruturas é mais rápida para pesquisa e porquê?

    - Analisando a tabela e os gráficos gerados com os tempos de pesquisa, a estrutura mais rápida e a arvore rubro negra, devido a estrutura estar melhor balanceada em relação as demais, que também e possível observar pela quantidade de pesquisa realizadas da estrutura rubro negra, sendo a menor em todos os casos.

- 3.2) - Há diferença de tempo das inserções, o que afeta cada estrutura em termos de mecanismo de manipulação / balanceamento?

    - O tempo de inserção da estrutura simples e rubro negra são praticamente idênticos, a estrutura simples insere rápido pois não existe nenhuma verificação de balanceamento, apenas a estrutura de arvore simples.

    - Na estrutura rubro negra possui o melhor tempo, devido ao seu balanceamento, que apesar de ser mais complexa a sua programação, o balanceamento de apenas uma rotação compensa o tempo na hora de inserir, pois na estrutura ordenada chega nas folhas mais rapidamente.

    - A estrutura AVL possui o pior tempo em relação a estrutura simples e rubro negra, isso ocorre devido ao seu balanceamento, que apesar de ajudar na pesquisa, consome um tempo extra para as rotações, sendo uma rotação simples ou uma rotação dupla, elevando muito o seu tempo de inserção

- 3.3) - Considerando as três bases de entrada, para quais você indica cada uma das estruturas e porquê?

    - Para utilização de uma pequena entrada de dados, a arvore simples consegue atender bem a sua inserção e pesquisa, mesmo que para uma pesquisa muito grande de dados o tempo e maior, ainda compensa pela simplicidade de implementação.

    - Quando a quantidade de dados começa a crescer, para melhorar a pesquisa, estruturas balanceadas são mais recomendadas, em todas as formas de pesquisa pela quantidade de entrada, a rubra sempre terá o tempo inferior de pesquisa, porem ela e mais elaborada de se implementar, o que traz a arvore AVL como uma solução temporária para as pesquisas.
    
    - Mas caso a quantidade de dados seja muito grande, o recomendado e a utilização da estrutura rubro negra, e também, estando com a estrutura rubro negra implementada, a utilização dela em todos os tipos de entradas e pesquisas se torna a melhor opção.

## Dados utilizados para análise

> Os tempos de inserção e pesquisa podem variar em cada maquina

> A quantidade de pesquisa será a mesma em qualquer maquina

<p align="center">
    <img src="src/img/entrada-A.jpeg" alt="teste" width="350"></img>
    <img src="src/img/entrada-B.jpeg" alt="teste" width="350"></img>
    <img src="src/img/1000-A.jpeg" alt="teste" width="350"></img>
    <img src="src/img/1000-B.jpeg" alt="teste" width="350"></img>
    <img src="src/img/10000-A.jpeg" alt="teste" width="350"></img>
    <img src="src/img/10000-B.jpeg" alt="teste"   width="350"></img>
    <img src="src/img/1000000-A.jpeg" alt="teste" width="350"></img>
    <img src="src/img/1000000-B.jpeg" alt="teste" width="350"></img>
</p>

### Tabela com os dados utilizados para a geração dos gráficos

|ARVORE|TAMANHO PESQUISA|TEMPO PESQUISA (s)|QUANTIDADE PESQUISA|TAMANHO ENTRADA|
|----|----|----|----|----|
Simples     |5000   |0,005353|65881|1000
AVL         |5000   |0,005170|56080|1000
Red Black   |5000   |0,004506|51190|1000
Simples     |10000  |0,010575|131054|1000
AVL         |10000  |0,010484|112184|1000
Red Black   |10000  |0,009176|102411|1000
Simples     |100000 |0,100983|1312248|1000
AVL         |100000 |0,095404|1122619|1000
Red Black   |100000 |0,085184|1025980|1000

ARVORE|TAMANHO PESQUISA|TEMPO PESQUISA (s)|QUANTIDADE PESQUISA|TAMANHO ENTRADA
|----|----|----|----|----|
Simples     |5000   |0,006292|90721|10000
AVL         |5000   |0,005825|72613|10000
Red Black   |5000   |0,005340|67726|10000
Simples     |10000  |0,014045|181474|10000
AVL         |10000  |0,011573|145378|10000
Red Black   |10000  |0,010877|135829|10000
Simples     |100000 |0,120410|1813343|10000
AVL         |100000 |0,116117|1454630|10000
Red Black   |100000 |0,094181|1358739|10000

|ARVORE|TAMANHO PESQUISA|TEMPO PESQUISA (s)|QUANTIDADE PESQUISA|TAMANHO ENTRADA|
|----|----|----|----|----|
Simples     |5000   |0,014582|133394|1000000
AVL         |5000   |0,012275|106245|1000000
Red Black   |5000   |0,010935|101358|1000000
Simples     |10000  |0,027925|267754|1000000
AVL         |10000  |0,022000|212643|1000000
Red Black   |10000  |0,020997|203079|1000000
Simples     |100000 |0,216585|2683614|1000000
AVL         |100000 |0,200959|2132835|1000000
Red Black   |100000 |0,180501|2035803|1000000

|ARVORE|TAMANHO ENTRADA|TEMPO INSERCAO (s)|
|----|----|----|
Simples     |1000   |0,001121
AVL         |1000   |0,001838
Red Black   |1000   |0,00118
Simples     |10000  |0,012425
AVL         |10000  |0,025016
Red Black   |10000  |0,012552
Simples     |1000000|2,116638
AVL         |1000000|4,007273
Red Black   |1000000|2,224072

### Referencias

- https://stackoverflow.com/questions/35117014/generating-a-random-uniformly-distributed-real-number-in-c

- http://linguagemc.com.br/arquivos-em-c-categoria-usando-arquivos/

- https://stackoverflow.com/questions/7462349/convert-double-value-to-a-char-array-in-c/18146858

- https://www.ic.unicamp.br/~francesquini/mc202/files/aula16-18.pdf

- https://stackoverflow.com/questions/10075294/converting-string-to-a-double-variable-in-c

- https://stackoverflow.com/questions/10797377/in-objective-c-what-utility-uses-brief-tag-in-comments

- https://developer.lsst.io/cpp/api-docs.html

- https://www.delftstack.com/pt/howto/c/how-to-convert-an-integer-to-a-string-in-c/

- https://github.com/GeorgePapageorgakis/red-black-tree

- https://qastack.com.br/programming/24383700/resize-image-in-the-wiki-of-github-using-markdown
