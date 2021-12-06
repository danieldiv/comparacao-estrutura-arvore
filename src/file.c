#include "file.h"

/**
 * @brief Gera um numero aleatorio double entre 1 e 100000
 * 
 */
double get_random() { return (1 + (double)rand() / (double)RAND_MAX *100000); }

/**
 * @brief cria 6 arquivos.txt de (1000, 10000, 1000000) valores para insersao
 * e (5000, 10000, 100000) valores para pesquisa.
 * Sendo estes valores aleatorios do tipo double
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

/**
 * @brief realiza a criacao de um arquivo
 * @param nome nome utilizado para o arquivo criado
 * @param max quantidade de valores aleatorios para criar
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

/**
 * @brief Realiza a leitura de um arquivo e salva os valores nas arvores
 * 
 * @param raizS ponteiro da arvore simples
 * @param raizAVL ponteiro da arvore AVL
 * @param raizRB ponteiro da arvore red black
 * @param tamanho valor do arquivo de entrada a ser aberto
 */
void readFileInput(TreeS **raizS, TreeAVL **raizAVL, TreeRB **raizRB, int tam, double *tS, double *tAVL, double *tRB) {
	FILE *fileS, *fileAVL, *fileRB;

	clock_t time;

	char linha[100];
	char text[20];
	char *result;

	int cont = 0;

	sprintf(text, "%d", tam);
	strcpy(linha, PATH_INPUT);
	strcat(linha, strcat(text, ".txt"));

	fileS = fopen(linha, "r");
	fileAVL = fopen(linha, "r");
	fileRB = fopen(linha, "r");

	if(fileS == NULL) {
		printf("Erro ao abrir arquivo de entrada\n");
		return;
	} else {
		Record r;
		
		time = clock();

		while(!feof(fileS)) {
			result = fgets(linha, 100, fileS);

			if(result) {
				r.key = atof(linha);

				insertItemS(raizS, r);

				cont++;
			}
		}
		*tS = ((clock() - time) / (double)CLOCKS_PER_SEC); // 1

		time = clock();

		while(!feof(fileAVL)) {
			result = fgets(linha, 100, fileAVL);

			if(result) {
				r.key = atof(linha);

				insertItemAVL(raizAVL, r);

				cont++;
			}
		}
		*tAVL = ((clock() - time) / (double)CLOCKS_PER_SEC); // 2

		time = clock();

		while(!feof(fileRB)) {
			result = fgets(linha, 100, fileRB);

			if(result) {
				r.key = atof(linha);

				insertItemRB(raizRB, r);

				cont++;
			}
		}
		*tRB = ((clock() - time) / (double)CLOCKS_PER_SEC); // 3
	}
	printf("\n%d valores inseridos no total\n", cont);
	
	fclose(fileS);
	fclose(fileAVL);
	fclose(fileRB);
}

/**
 * @brief Realiza a leitura de um arquivo e faz a pesquisa
 * 
 * @param raizS ponteiro da arvore simples
 * @param raizAVL ponteiro da arvore AVL
 * @param raizRB ponteiro da arvore red black
 * @param tamanho valor do arquivo de entrada a ser aberto
 */
void readFileSearch(TreeS **raizS, TreeAVL **raizAVL, TreeRB **raizRB, int tam, double *tS, double *tAVL, double *tRB) {
	TreeS *aux1;
	TreeAVL *aux2;
	
	FILE *file;

	clock_t time;
	
	char linha[100];
	char text[20];
	char *result;

	double quantS, quantAVL, quantRB;
	int cont;

	cont = quantS = quantAVL = quantRB = 0;

	sprintf(text, "%d", tam);
	strcpy(linha, PATH_SEARCH);
	strcat(linha, strcat(text, ".txt"));

	file = fopen(linha, "r");

	if(file == NULL) {
		printf("Erro ao abrir arquivo de pesquisa\n");
		return;
	} else {
		Record r;
		
		while(!feof(file)) {
			result = fgets(linha, 100, file);

			if(result) {
				r.key = atof(linha);

				pesquisaS(raizS, &aux1, r, &quantS);
				pesquisaAVL(raizAVL, &aux2, r, &quantAVL);
				searchRB(*raizRB, r, &quantRB);

				cont++;
			}
		}
	}
	printf("\n%d valores pesquisados\n\n", cont);
	printf("(%.0lf) pesquisas realizadas arvore Simples\n", quantS);
	printf("(%.0lf) pesquisas realizadas arvore AVL\n", quantAVL);
	printf("(%.0lf) pesquisas realizadas arvore RB\n\n", quantRB);
	fclose(file);
}