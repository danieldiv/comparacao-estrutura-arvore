#include "treeRB.h"

// int menu();
// void insertAllTree(TreeS **raizS, TreeAVL **raizAVL, TreeRB **raizRB);
// void printAllTree(TreeS *raizS, TreeAVL *raizAVL, TreeRB *raizRB);

int main() {
	system("clear");

    printf("hello world\n");

    TreeRB *raiz;

    inicializa(&raiz);

// 	int op;

// 	TreeS *raizS;
// 	TreeAVL *raizAVL;
// 	TreeRB *raizRB;

// 	raizS = createTreeS();
// 	raizAVL = createTreeAVL();
// 	raizRB = createTreeRB();

// 	do {
// 		system("clear");
// 		op = menu();

// 		switch(op) {
// 			case 1:
// 				clock_t tempo;
// 				tempo = clock();

// 				char nome[100];
// 				strcpy(nome, "src/files/input1000.txt");

// 				printf("inserindo dados ...\n");
// 				readFile(&raizS, &raizAVL, &raizRB, nome);
// 			break;
// 			case 2:
// 				// imprimir(raiz);
// 			break;
// 			case 3:
// 				insertAllTree(&raizS, &raizAVL, &raizRB);
// 				break;
// 			case 0:
// 				printf("O programa sera finalizado!\n");
// 				return EXIT_SUCCESS;
// 			default:
// 				printf("Opcao invalida!\n");
// 		}

// 		system("read -p \"\nPressione enter para continuar...\" continue");
// 	} while (op != 0);



// 	// insertAllTree(&raizS, &raizAVL, &raizRB);
// 	// printAllTree(raizS, raizAVL, raizRB);

	
// 	// clock_t tempo;
// 	// tempo = clock();

// 	// char nome[100];
// 	// strcpy(nome, "src/files/input1000.txt");

// 	// printf("inserindo dados ...\n");
// 	// readFile(&raizS, &raizAVL, &raizRB, nome);

	
	

// 	// printf("\nTempo: %f\n",(clock() - tempo) / (double)CLOCKS_PER_SEC);


    return EXIT_SUCCESS;
}

// int menu() {
// 	int op;

// 	printf("====================\n");
// 	printf("   MENU DE OPCOES\n");
// 	printf("====================\n\n");
	
// 	printf("1 - Incializar arvore\n");
// 	printf("2 - Pesquisar\n");
// 	printf("3 - Arvore teste\n");
// 	printf("0 - Sair\n\n");

// 	printf("Escolha uma opção: ");
// 	scanf("%d", &op);

// 	return op;
// }

// /**
//  * @brief Insere e imprime os valores (11,2,14,1,7,15,5,8,4) nas tres arvores
//  * 
//  * @param raizS ponteiro da arvore simples
//  * @param raizAVL ponteiro da arvore AVL
//  * @param raizRB ponteiro da arvore red black
//  */
// void insertAllTree(TreeS **raizS, TreeAVL **raizAVL, TreeRB **raizRB) {
// 	*raizS = createTreeS();
// 	*raizAVL = createTreeAVL();
// 	*raizRB = createTreeRB();

// 	Record r;

// 	int vetor[] = {11,2,14,1,7,15,5,8,4};
// 	// int vetor[] = {10,2,7,5,3,9,16,4,11,1,6,23,14};
	
// 	int tam = sizeof(vetor)/sizeof(vetor[0]);

// 	for(int i = 0; i < tam; i++) {
// 		r.key = vetor[i];

// 		insertItemS(raizS, r);
// 		insertItemAVL(raizAVL, r);
// 		insertItemRB(raizRB, NULL, raizRB, r);
// 	}
// 	printAllTree(*raizS, *raizAVL, *raizRB);
// }

// /**
//  * @brief Imprime os valores salvos nas tres arvores
//  * 
//  * @param raizS ponteiro da arvore simples
//  * @param raizAVL ponteiro da arvore AVL
//  * @param raizRB ponteiro da arvore red black
//  */
// void printAllTree(TreeS*raizS, TreeAVL *raizAVL, TreeRB *raizRB) {
// 	printf("Arvore binaria simples\n");
// 	printf("\nPRE ORDEN: { ");
// 	preordemS(raizS);
	
// 	printf("}\nCENTRAL:   { ");
// 	centralS(raizS);
	
// 	printf("}\nPOS ORDEN: { ");
// 	posordemS(raizS);
// 	printf("}\n");

// 	printf("\nArvore binaria AVL\n");
// 	printf("\nPRE ORDEN: { ");
// 	preordemAVL(raizAVL);
	
// 	printf("}\nCENTRAL:   { ");
// 	centralAVL(raizAVL);
	
// 	printf("}\nPOS ORDEN: { ");
// 	posordemAVL(raizAVL);
// 	printf("}\n");

// 	printf("\nArvore binaria red blak\n");
// 	printf("\nPRE ORDEN: { ");
// 	preordemRB(raizRB);
	
// 	printf("}\nCENTRAL:   { ");
// 	centralRB(raizRB);
	
// 	printf("}\nPOS ORDEN: { ");
// 	posordemRB(raizRB);
// 	printf("}\n");
// }