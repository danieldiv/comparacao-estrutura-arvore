#include "file.h"
#include "time.h"

int menu();
int menuInput();
int menuSearch();
void resetTree(TreeS **raizS, TreeAVL **raizAVL, TreeRB **raizRB);
void insertAllTree(TreeS **raizS, TreeAVL **raizAVL, TreeRB **raizRB);
void printAllTree(TreeS *raizS, TreeAVL *raizAVL, TreeRB *raizRB);

int main() {
	system("clear");    

	int op, tam, tamVetor;
    char tamanho[100];

	TreeS *raizS;
	TreeAVL *raizAVL;
	TreeRB *raizRB;

    Record r;
    double pesquisa[] = {21498.424782,79924.619786,64991.24182,19180.063206,4824.369977,63443.301733,16594.409617, 51439.424539};

    clock_t antes, depois;

	do {
		system("clear");
        op = menu();
		
		switch(op) {
			case 1:
                tam = menuInput();

                if(tam == 0)
                    printf("Nenhuma entrada selecionada!\n");    
                else {
                    resetTree(&raizS, &raizAVL, &raizRB);
				    
                    antes = clock();
                    printf("inserindo dados ...\n");
                    
                    readFileInput(&raizS, &raizAVL, &raizRB, tam);

                    depois = clock();
                    printf("Tempo de insersao: %lf\n", (depois - antes) / (double)CLOCKS_PER_SEC);
                }
			break;
			case 2:
                // tamVetor = sizeof(pesquisa)/sizeof(pesquisa[0]);
                
                printf("searching...\n\n");

                if(raizS == NULL || raizAVL == NULL || raizRB == NULL)
                    printf("As arvores estao vazias!\n");
                else {
                    tam = menuSearch();

                    if(tam == 0)
                        printf("Nenhuma entrada selecionada!\n");    
                    else {
                        antes = clock();
                        readFileSearch(&raizS, &raizAVL, &raizRB, tam);

                        depois = clock();
                        printf("Tempo de pesquisa: %lf\n", (depois - antes) / (double)CLOCKS_PER_SEC);
                    }
                    // for(int i=0; i < tamVetor; i++) {
                    //     r.key = pesquisa[i];
                    //     search_delete(raizRB, r);
                    // }
                }
			break;
			case 3:
				insertAllTree(&raizS, &raizAVL, &raizRB);
				break;
			case 0:
				printf("O programa sera finalizado!\n");
				return EXIT_SUCCESS;
			default:
				printf("Opcao invalida!\n");
		}

		system("read -p \"\nPressione enter para continuar...\" continue");
	} while (op != 0);

    return EXIT_SUCCESS;
}

/**
 * @brief Reinicia as tres arvores
 * 
 * @param raizS ponteiro da arvore simples
 * @param raizAVL ponteiro da arvore AVL
 * @param raizRB ponteiro da arvore red black
 */
void resetTree(TreeS **raizS, TreeAVL **raizAVL, TreeRB **raizRB) {
    (*raizS) = createTreeS();
	(*raizAVL) = createTreeAVL();
    inicializaTreeRB(raizRB);
}

/**
 * @brief Menu de opcoes principal
 * 
 */
int menu() {
	int op;

	printf("====================\n");
	printf("   MENU DE OPCOES\n");
	printf("====================\n\n");
	
	printf("1 - Incializar arvore\n");
	printf("2 - Pesquisar\n");
	printf("3 - Arvore teste\n");
	printf("0 - Sair\n\n");

	printf("Escolha uma opção: ");
	scanf("%d", &op);

	return op;
}

/**
 * @brief Menu de opcoes para tamanho da entrada
 * 
 */
int menuInput() {
	int op;

    system("clear");
	printf("====================\n");
	printf("  OPCOES DE ENTRADA\n");
	printf("====================\n\n");
	
	printf("1 - 1000\n");
	printf("2 - 10000\n");
	printf("3 - 1000000\n");
	printf("0 - Sair\n\n");

	printf("Escolha uma entrada: ");
	scanf("%d", &op);

    switch(op) {
        case 1: return 1000;
        case 2: return 10000;
        case 3: return 1000000;
        default: return 0;
    }
}

/**
 * @brief Menu de opcoes para tamanho da pesquisa
 * 
 */
int menuSearch() {
    int op;

    system("clear");
	printf("====================\n");
	printf(" OPCOES DE PESQUISA\n");
	printf("====================\n\n");
	
	printf("1 - 5000\n");
	printf("2 - 10000\n");
	printf("3 - 100000\n");
	printf("0 - Sair\n\n");

	printf("Escolha uma entrada: ");
	scanf("%d", &op);

    switch(op) {
        case 1: return 5000;
        case 2: return 10000;
        case 3: return 100000;
        default: return 0;
    }
}

/**
 * @brief Insere e imprime os valores (11,2,14,1,7,15,5,8,4) nas tres arvores
 * 
 * @param raizS ponteiro da arvore simples
 * @param raizAVL ponteiro da arvore AVL
 * @param raizRB ponteiro da arvore red black
 */
void insertAllTree(TreeS **raizS, TreeAVL **raizAVL, TreeRB **raizRB) {
	*raizS = createTreeS();
	*raizAVL = createTreeAVL();
    inicializaTreeRB(raizRB);

	Record r;

	int vetor[] = {11,2,14,1,7,15,5,8,4};
	// int vetor[] = {10,2,7,5,3,9,16,4,11,1,6,23,14};
	
	int tam = sizeof(vetor)/sizeof(vetor[0]);

	for(int i = 0; i < tam; i++) {
		r.key = vetor[i];

		insertItemS(raizS, r);
		insertItemAVL(raizAVL, r);
        insertItemRB(raizRB, r);
	}
	printAllTree(*raizS, *raizAVL, *raizRB);
}

/**
 * @brief Imprime os valores salvos nas tres arvores
 * 
 * @param raizS ponteiro da arvore simples
 * @param raizAVL ponteiro da arvore AVL
 * @param raizRB ponteiro da arvore red black
 */
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

	printf("\nArvore binaria red black\n");
	printf("\nPRE ORDEN: { ");
	preordemRB(raizRB);
	
	printf("}\nCENTRAL:   { ");
	centralRB(raizRB);
	
	printf("}\nPOS ORDEN: { ");
	posordemRB(raizRB);
	printf("}\n");
}