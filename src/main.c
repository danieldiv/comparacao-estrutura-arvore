#include "file.h"

void insertAllTree(TreeS **raizS, TreeAVL **raizAVL, TreeRB **raizRB);
void printAllTree(TreeS *raizS, TreeAVL *raizAVL, TreeRB *raizRB);

struct tm *local;

int main() {
	system("clear");

	TreeS *raizS;
	TreeAVL *raizAVL;
	TreeRB *raizRB;

	raizS = createTreeS();
	raizAVL = createTreeAVL();
	raizRB = createTreeRB();

	// insertAllTree(&raizS, &raizAVL, &raizRB);
	// printAllTree(raizS, raizAVL, raizRB);

	
	clock_t tempo;
	tempo = clock();

	char nome[100];
	strcpy(nome, "src/files/input1000.txt");
	readFile(&raizS, &raizAVL, &raizRB, nome);

	// printAllTree(raizS, raizAVL, raizRB);
	printf("\nTempo: %f\n",(clock() - tempo) / (double)CLOCKS_PER_SEC);


    return EXIT_SUCCESS;
}

void insertAllTree(TreeS **raizS, TreeAVL **raizAVL, TreeRB **raizRB) {
	Record r;

	int vetor[] = {11,2,14,1,7,15,5,8,4};
	
	int tam = sizeof(vetor)/sizeof(vetor[0]);

	for(int i = 0; i < tam; i++) {
		r.key = vetor[i];

		insertItemS(raizS, r);
		insertItemAVL(raizAVL, r);
		insertItemRB(raizRB, NULL, raizRB, r);
	}
}

void printAllTree(TreeS*raizS, TreeAVL *raizAVL, TreeRB *raizRB) {
	printf("Arvore binaria simples\n");
	printf("\nPRE ORDEN: { ");
	preordemS(raizS);
	
	printf("}\nCENTRAL:   { ");
	centralS(raizS);
	
	printf("}\nPOS ORDEN: { ");
	posordemS(raizS);
	printf("}\n");

	printf("\nArvore binaria AVL\n");
	printf("\nPRE ORDEN: { ");
	preordemAVL(raizAVL);
	
	printf("}\nCENTRAL:   { ");
	centralAVL(raizAVL);
	
	printf("}\nPOS ORDEN: { ");
	posordemAVL(raizAVL);
	printf("}\n");

	printf("\nArvore binaria red blak\n");
	printf("\nPRE ORDEN: { ");
	preordemRB(raizRB);
	
	printf("}\nCENTRAL:   { ");
	centralRB(raizRB);
	
	printf("}\nPOS ORDEN: { ");
	posordemRB(raizRB);
	printf("}\n");
}