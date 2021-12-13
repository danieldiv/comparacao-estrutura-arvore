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
	// printf("Inicializando arquivo de entrada 1000000000...\n");
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

	// strcpy(nome, "src/files/input 1 000 000 000.txt");
	// writeFile(nome, 1000000000);
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
 * @param tS ponteiro para o tempo da arvore simples
 * @param tAVL ponteiro para o tempo da arvore AVL
 * @param tRB ponteiro para o tempo da arvore rubro negra
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

	int contadorRP = 0;

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
				insertItemRB(raizRB, r, &contadorRP, &cont);
			}
		}
		*tRB = ((clock() - time) / (double)CLOCKS_PER_SEC); // 3
	}
	printf("\n%d valores inseridos no total\n", cont);
	printf("\n%d valores repetidos\n", contadorRP);
	
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
 * @param tam valor do arquivo de entrada a ser aberto
 * @param tS ponteiro para o tempo da arvore simples
 * @param tAVL ponteiro para o tempo da arvore AVL
 * @param tRB ponteiro para o tempo da arvore rubro negra
 */
void readFileSearch(TreeS **raizS, TreeAVL **raizAVL, TreeRB **raizRB, int tam, double *tS, double *tAVL, double *tRB) {
	FILE *fileS, *fileAVL, *fileRB;
	TreeS *aux1;
	TreeAVL *aux2;

	clock_t time;

	char linha[100];
	char text[20];
	char *result;

	int cont;
	double quantS, quantAVL, quantRB;

	cont = quantS = quantAVL = quantRB = 0;
	
	sprintf(text, "%d", tam);
	strcpy(linha, PATH_SEARCH);
	strcat(linha, strcat(text, ".txt"));

	fileS = fopen(linha, "r");
	fileAVL = fopen(linha, "r");
	fileRB = fopen(linha, "r");

	if(fileS == NULL) {
		printf("Erro ao abrir arquivo de pesquisa\n");
		return;
	} else {
		Record r;
		
		time = clock();

		while(!feof(fileS)) {
			result = fgets(linha, 100, fileS);

			if(result) {
				r.key = atof(linha);
				pesquisaS(raizS, &aux1, r, &quantS);
				cont++;
			}
		}
		*tS = ((clock() - time) / (double)CLOCKS_PER_SEC); // 1

		time = clock();

		while(!feof(fileAVL)) {
			result = fgets(linha, 100, fileAVL);

			if(result) {
				r.key = atof(linha);
				pesquisaAVL(raizAVL, &aux2, r, &quantAVL);
				cont++;
			}
		}
		*tAVL = ((clock() - time) / (double)CLOCKS_PER_SEC); // 2

		time = clock();

		while(!feof(fileRB)) {
			result = fgets(linha, 100, fileRB);

			if(result) {
				r.key = atof(linha);
				searchRB(*raizRB, r, &quantRB);
				cont++;
			}
		}
		*tRB = ((clock() - time) / (double)CLOCKS_PER_SEC); // 3
	}
	fclose(fileS);
	fclose(fileAVL);
	fclose(fileRB);
	
	printf("\n%d valores pesquisados\n\n", cont);
	printf("(%.0lf) pesquisas realizadas arvore Simples\n", quantS);
	printf("(%.0lf) pesquisas realizadas arvore AVL\n", quantAVL);
	printf("(%.0lf) pesquisas realizadas arvore RB\n", quantRB);
}

// /**
//  * @brief Realiza a leitura de um arquivo de 1000000000 de entradas
//  * este metodo nao deve ser utilizado, consome muito recurso
//  * 
//  * @param raizRB ponteiro da arvore red black
//  * @param tempo ponteiro para o tempo de insercao
//  */
// void readFileInput1Bilhao(TreeRB **raizRB, double *tempo) {
// 	FILE *file, *newFile;

// 	clock_t time;

// 	char linha[100];
// 	char text[20];
// 	char *result;

// 	int cont = 0, contadorRP = 0;

// 	sprintf(text, "%d", 1000000000);
// 	strcpy(linha, PATH_INPUT);
// 	strcat(linha, strcat(text, ".txt"));

// 	file = fopen(linha, "r");
// 	newFile = fopen("src/files/saida.txt", "w");

// 	if(file == NULL) {
// 		printf("Erro ao abrir arquivo de entrada\n");
// 		return;
// 	} else {
// 		Record r;
// 		time = clock();

// 		while(!feof(file)) {
// 			result = fgets(linha, 100, file);

// 			if(result) {
// 				r.key = atof(linha);
// 				insertItemRBCorrecao(raizRB, r, &contadorRP, &cont);

// 				sprintf(linha, "%.6lf", r.key);
// 				strcat(linha, "\n");
// 				fputs(linha, newFile);
// 			}
// 		}
// 		*tempo = ((clock() - time) / (double)CLOCKS_PER_SEC);
// 	}
// 	printf("\n%d valores inseridos no total\n", cont);
// 	printf("\n%d valores repetidos\n", contadorRP);
	
// 	fclose(file);
// }