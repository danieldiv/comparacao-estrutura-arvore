#include "file.h"

int menu();
int menuInput();
int menuSearch();
void resetTree(TreeS **raizS, TreeAVL **raizAVL, TreeRB **raizRB);
void insertAllTree(TreeS **raizS, TreeAVL **raizAVL, TreeRB **raizRB, int *tam_aux);
void printAllTree(TreeS *raizS, TreeAVL *raizAVL, TreeRB *raizRB);

/**
 * @brief Menu principal
 * 
 */
int main() {
	system("clear");

	int op, tam, tam_aux = 0;

	TreeS *raizS;
	TreeAVL *raizAVL;
	TreeRB *raizRB;

	double t_inputS, t_inputAVL, t_inputRB;
	double t_searchS, t_searchAVL, t_searchRB;
	double t_total, t_tempo_1Bilhao;

	resetTree(&raizS, &raizAVL, &raizRB);

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
				    
                    printf("inserindo %d dados ...\n", tam);
                    
                    readFileInput(&raizS, &raizAVL, &raizRB, tam, &t_inputS, &t_inputAVL, &t_inputRB);
					tam_aux = tam;

					t_total = (t_inputS + t_inputRB + t_inputAVL);

                    printf("\nTempo total de insersao: %lf\n\n", t_total);
					printf("Tempo arvore Simples: %lf\n", t_inputS);
					printf("Tempo arvore AVL: %lf\n", t_inputAVL);
					printf("Tempo arvore Red Black: %lf\n", t_inputRB);
                }
				// else if(tam == -1) {
				// 	printf("inserindo 1 bilhao de dados ...\n");
				// 	readFileInput1Bilhao(&raizRB, &t_tempo_1Bilhao);
				// 	printf("Tempo 1 bilhao: %lf\n", t_tempo_1Bilhao);
				// } 
			break;
			case 2:
                printf("searching...\n\n");

                if(raizS == NULL || raizAVL == NULL || raizRB == NULL)
                    printf("As arvores estao vazias!\n");
                else {
                    tam = menuSearch();

                    if(tam == 0)
                        printf("Nenhuma entrada selecionada!\n");    
                    else {
						printf("\nArvores com %d entradas\n", tam_aux);
						printf("searching %d valores...\n", tam);

                        readFileSearch(&raizS, &raizAVL, &raizRB, tam, &t_searchS, &t_searchAVL, &t_searchRB);

                        t_total = (t_searchS + t_searchRB + t_searchAVL);

                        printf("\nTempo total de pesquisa: %lf\n\n", t_total);
						printf("Tempo arvore Simples: %lf\n", t_searchS);
						printf("Tempo arvore AVL: %lf\n", t_searchAVL);
						printf("Tempo arvore Red Black: %lf\n", t_searchRB);
                    }
                }
			break;
			case 3:
				insertAllTree(&raizS, &raizAVL, &raizRB, &tam_aux);
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
	// printf("4 - 1000000000\n");
	printf("0 - Sair\n\n");

	printf("Escolha uma entrada: ");
	scanf("%d", &op);

    switch(op) {
        case 1: return 1000;
        case 2: return 10000;
        case 3: return 1000000;
		// case 4: return -1;
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
 * @param tam_aux tamanho da arvore que sera inserida
 */
void insertAllTree(TreeS **raizS, TreeAVL **raizAVL, TreeRB **raizRB, int *tam_aux) {
	*raizS = createTreeS();
	*raizAVL = createTreeAVL();
    inicializaTreeRB(raizRB);
	int cont = 0, contRP = 0;

	Record r;

	int vetor[] = {11,2,14,1,7,15,5,8,4};
	// int vetor[] = {10,2,7,5,3,9,16,4,11,1,6,23,14};
	
	int tam = sizeof(vetor)/sizeof(vetor[0]);
	*tam_aux = tam;

	for(int i = 0; i < tam; i++) {
		r.key = vetor[i];

		insertItemS(raizS, r);
		insertItemAVL(raizAVL, r);
        insertItemRB(raizRB, r, &contRP, &cont);
	}
	printAllTree(*raizS, *raizAVL, *raizRB);

	r.key = 8;
	search_delete(raizRB, *raizRB, r);

	printf("\nApoz excluir o valor %lf da arvore red black...\n", r.key);
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