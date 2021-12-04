#include "file.h"

double get_random() { return ((double)rand() / (double)RAND_MAX *1000); }

/*
	Funcao: randoValue, cria 6 arquivos.txt de (1000, 10000, 1000000) valores para insersao
	e (5000, 10000, 100000) valores para pesquisa. Sendo estes valores aleatorios do tipo double
*/
void randomValue() {
	char nome[100];

	srand(time(NULL));
	printf("Inicializando arquivos de entrada (1000, 10000, 1000000) e pesquisa (5000, 10000, 100000)...\n");

	strcpy(nome, "src/files/input1000.txt");
	writeFile(nome, 1000);
	strcpy(nome, "src/files/input10000.txt");
	writeFile(nome, 10000);
	strcpy(nome, "src/files/input1000000.txt");
	writeFile(nome, 1000000);

	srand(time(NULL));

    strcpy(nome, "src/files/search5000.txt");
	writeFile(nome, 5000);
	strcpy(nome, "src/files/search10000.txt");
	writeFile(nome, 10000);
	strcpy(nome, "src/files/search100000.txt");
	writeFile(nome, 100000);
}

/*
	Funcao: writeFile, realiza a criacao de um arquivo
	@param nome: nome utilizado para o arquivo criado
	@param max: quantidade de valores aleatorios para criar
*/
void writeFile(char *nome, int max) {
	FILE *file;
	char array[100];
	char *result;

	double n = 0;
    int cont = 0;

	file = fopen(nome, "w");

    for(int i=0; i < max; i++) {
        n = get_random();
		sprintf(array, "%.6lf", n);
		strcat(array, "\n");
		fputs(array, file);
    }
	fclose(file);
}

/*
	Funcao: readFile, realiza a leitura de um arquivo e salva os valores nas arvores
	@param nome: nome do arquivo para ser lido
*/
void readFile(TreeS **raizS, TreeAVL **raizAVL, TreeRB **raizRB, char *nome) {
	FILE *file;
	char linha[100];
	char *result;
	int cont = 0;

	file = fopen(nome, "r");

	if(file == NULL) {
		printf("Erro ao abrir\n");
		return;
	} else {
		Record r;

		
		while(!feof(file)) {
			result = fgets(linha, 100, file);

			if(result) {
				r.key = atof(linha);

				insertItemS(raizS, r);
				insertItemAVL(raizAVL, r);
				insertItemRB(raizRB, NULL, raizRB, r);

				cont++;
				printf("%d\n", cont);
			}
		}
	}
	fclose(file);
}