// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main(void) {
// 	FILE *file;
// 	char linha[10];
// 	char *result;

// 	// ==============================
// 	// ESCRITA
// 	// ==============================

// 	file = fopen("arquivo.txt", "w");

// 	fputs("456.551634\n", file);
// 	fputs("320.117525\n", file);
// 	fputs("74.682345\n", file);
// 	fputs("506.254504\n", file);

// 	char array[50];
// 	double num = 264.553233;

// 	sprintf(array, "%.6lf", num);
// 	strcat(array, "\n");

// 	fputs(array, file);

// 	fputs("275.001674\n", file);
// 	fputs("740.643421\n", file);


// 	fclose(file);

// 	// ==============================
// 	// LEITURA
// 	// ==============================
	
// 	file = fopen("arquivo.txt", "r");

// 	if(file == NULL)
// 		printf("Erro ao abrir\n");
// 	else {
// 		while(!feof(file)) {
// 			result = fgets(linha, 50, file);

// 			if(result)
// 				printf("%s", linha);
// 		}
// 	}
// 	fclose(file);

// 	return 0;
// }

// #include <stdio.h>
// #include <time.h>
// #include <stdlib.h>

// double get_random() { return ((double)rand() / (double)RAND_MAX *1000); }

// int main()
// {
//     clock_t tempo;
// 	tempo = clock();

//     double n = 0;
//     int cont = 0;
//     srand(time(NULL)); // randomize seed

//     for(int i=0; i < 100; i++) {
//         n = get_random(); // call the function to get a different value of n every time
//         printf("%f\n", n);  // print your number

//     }
//     printf("\n\nTempo: %f",(clock() - tempo) / (double)CLOCKS_PER_SEC);

//     return 0;
// }

#include "treeRedblack.h"

int main() {

	system("clear");

	Tree *raiz;
	Record r;

	raiz = createTree();

	int vetor[] = {11,2,14,1,7,15,5,8,4};
	// int vetor[] = {8,4,15,2,6,5,12,13};
	// int vetor[] = {10,2,7,5,3,9,16,4,11,1,6,23,14};
	// int vetor[] = {78,44,67,92,22,110,16,54,23,32,37};
	int tam = sizeof(vetor)/sizeof(vetor[0]);

	Tree *aux;

	for(int i=0; i < tam; i++) {
		r.key = vetor[i];
		insertItem(&raiz, &raiz, NULL, r);
	}

	printf("\nPRE ORDEN: { ");
	preordem(raiz);

	// printf("}\n\nCENTRAL: {\n");
	// central(raiz);

	printf("}\n\nPOS ORDEN: { ");
	posordem(raiz);
	printf("}\n");

	return EXIT_SUCCESS;
}