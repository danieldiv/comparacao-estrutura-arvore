// #include "treeRedblack.h"

// int main() {
//     return 0;
// }

/**
    redblack_tree_main.c
    Purpose: A simple implementation of a Red Black Tree in C, windows edition
	see chapter 13 of Introduction to Algorithms 3rd edition - Cormen, Leiserson, Rivest, Stein.
	
	A red-black tree is a binary tree that satisfies the following red-black properties:
	1. Every node is either red or black.
	2. The root is black.
	3. Every leaf (NIL) is black.
	4. If a node is red, then both its children are black.
	5. For each node, all simple paths from the node to descendant leaves contain the
	same number of black nodes.
    
    @author George Papageorgakis
    @version 1.0 01/2012
*/
// #include "def_header.h"
#include <string.h>

#include "treeRB.h"
#include "file.h"

struct node *temp, *nill, *root;

int main(){
    system("clear");

    // randomValue();

    // return 0;

    double data = 0, chk = 0;
    char ch = ' ';
    // HANDLE  hConsole;
    // hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //initialiazation  of nill (and root)
    nill        =(struct node *) malloc(sizeof(struct node));
    nill->color = black;
    nill->LC    = NULL;
    nill->RC    = NULL;
    nill->P     = NULL;
    nill->key   = 0;
    root        = nill;

    int vetor[] = {11,2,14,1,7,15,5,8,4};
    int tam = sizeof(vetor)/sizeof(vetor[0]);


    //===================
    FILE *file;
	char linha[100];
	char *result;
	int cont = 0;

    char nome[100];
	strcpy(nome, "src/files/input1000.txt");

	file = fopen(nome, "r");

	if(file == NULL) {
		printf("Erro ao abrir\n");
	} else {
		while(!feof(file)) {
			result = fgets(linha, 100, file);

			if(result) {
                data = atof(linha);
                // printf("%lf\t", data);
            if ((temp = (struct node *) malloc(sizeof(struct node))) != NULL){
                temp->P     = nill;
                temp->LC    = nill;
                temp->RC    = nill;
                temp->key   = data;
                temp->color = black;
                chk         = check(root,data,0);
                if(chk == 0){
                    rb_insert(root, nill, temp);
                }
                else{
                    printf("Node already registered: %lf\n", data);   fflush(stdout);
                    free(temp);
                }
            }
				cont++;
			}
		}
		printf("cont total : %d\n", cont);
	}
	fclose(file);

    double pesquisa[] = {21498.424782,79924.619786,64991.24182,19180.063206,4824.369977,63443.301733,16594.409617};
    tam = sizeof(pesquisa)/sizeof(pesquisa[0]);
    
    printf("searching\n\n");

    for(int i=0; i < tam; i++) {
        search_delete(root, pesquisa[i]);
    }
    return 0;
}


//left rotate x and x.RC
void Left_Rotate(struct node *x){
    struct node *y;
    y = x->RC;
    x->RC = y->LC;
    if (y->LC != nill)
        y->LC->P = x;
    y->P = x->P;
    if (x->P == nill)
        root = y;
    else if (x == x->P->LC)
        x->P->LC = y;
    else if (x == x->P->RC)
        x->P->RC = y;
    y->LC = x;
    x->P  = y;
}

//right rotate y and y.LC
void Right_Rotate(struct node *y){
    struct node *x;
    x = y->LC;
    y->LC = x->RC;
    if (x->RC != nill)
        x->RC->P = y;
    x->P = y->P;
    if (y->P == nill)
        root = x;
    else if (y == y->P->RC)
        y->P->RC = x;
    else if (y == y->P->LC)
        y->P->LC = x;
    x->RC = y;
    y->P  = x;
}

// each iteration 2 possibilities: either move up aux or perform rotation and terminate
void fix_insert(struct node *aux){
    struct node *y;
    while (aux->P->color == red){	
        //if aux->P is root do not do anything
        if (aux->P == aux->P->P->LC){
            y = aux->P->P->RC;
            //case 1 if uncle is red (red-red problem)
            //recolor parent->black & uncle->black & grandparent->red
            if (y->color == red){				
                aux->P->color    = black;		
                y->color         = black;
                aux->P->P->color = red;
                aux              = aux->P->P;
            }
            else{
                //case 2 an uncle == black
                //if aux is RC rotate aux and aux.P
                if (aux == aux->P->RC){		
                    aux = aux->P;
                    Left_Rotate(aux);		
                }
                //case 3 uncle == black and aux is a LC, rotate grandparent with parent
                aux->P->color    = black;		
                aux->P->P->color = red;
                Right_Rotate(aux->P->P);
            }
        }
        //if parent of inserted node is the right child of grandparent
        else if (aux->P == aux->P->P->RC){
            //case 1 if uncle of y.color==red
            //make parent black, uncle set to aux, settle to grandparent and set him red
            y = aux->P->P->LC;
            if (y->color == red) {
                aux->P->color    = black;
                y->color         = black;
                aux->P->P->color = red;	
                aux              = aux->P->P;
            }
            //case 2 if uncle==black
            //if aux is LC rotate aux and aux.P
            else{
                if (aux == aux->P->LC){
                    aux = aux->P;
                    Right_Rotate(aux);
                }
                //case 3: uncle==black and aux is RC
                aux->P->color    = black;		
                aux->P->P->color = red;
                Left_Rotate(aux->P->P);
            }
        }
    }
    root->color = black; //always set root.color=black							
}

//insert node to tree, trailing pointer y is x's parent (x=root, y=nill)
void rb_insert(struct node *x, struct node *y, struct node *temp){
    //move down the tree left-right depending on the key value until x==nill
    //save previous position in case of x==nill
    while (x != nill){				
        y = x;					
        if (temp->key < x->key)
            x = x->LC;
        else 
            x = x->RC;
    }
    //reassign pointers, temp->P must be same as x->P since its 1 step down
    temp->P=y;
    if (y == nill)                  //if tree is empty				
        root = temp;
    else if (temp->key < y->key)    //if temp is placed on the left
        y->LC = temp;
    else                            //if temp is placed on the right
        y->RC = temp;
    temp->LC    = nill;             //inserted nodes always be leaves pointing to nill
    temp->RC    = nill;
    temp->color = red;              //inserted node is always red
    fix_insert(temp);               //fix tree in case or RB property violation
}


///////////////////////////////////////////////////////////////////////////////
//replace the subtree rooted at node aux with the subtree rooted at aux-LC or aux->RC
void RB_transplant(struct node *aux, struct node *auxchild){
    if (aux->P == nill)             //if aux=root child becomes root
        root = auxchild;
    else if (aux == aux->P->LC)     //if child is a LC
        aux->P->LC = auxchild;      //connect grandparent's->LC with child
    else 
    	aux->P->RC = auxchild;     //if child is RC connect grandparent's->RC with child
    auxchild->P = aux->P;	   //connect child to point to parent
}


//-----------------------------------------------------------------------------
//find the successor of a node
struct node *tree_successor(struct node *aux_succ){
    while (aux_succ->LC != nill)
        aux_succ = aux_succ->LC;
    return aux_succ;
}


///////////////////////////////////////////////////////////////////////////////
//fix the balance after a node deletion
void RB_delete_fix(struct node *x, struct node *w){
    while (x != root && x->color == black) {
        //x is LC
        if (x == x->P->LC){
            w = x->P->RC;               //w is x's sibling
            //case 1: x's sibling w is red, w must have black children 
            //we switch colors of w <=> x.p and then Left_Rotation
            if (w->color == red){	
                w->color    = black;    //case 1 is converted into case 2,3 or 4.
                x->P->color = red;
                Left_Rotate(x->P);      //x->p with w
                w = x->P->RC;
            }
            //case 2: x's sibling w is black, and both of w's children are black to 
            //compensate for removing 1 black we add extra black to x.p which and
            //we do so by repeating (while loop) with x.p as new node x was red or black
	    //we remove 1 black color from x and w
            else if (w->LC->color == black && w->RC->color == black){	
                w->color = red;
                x = x->P;
            }
            //case 3:x's sibling w is black, w's LC is red and w's RC is black
            //switch colors w <=> w.LC and perform Right_Rotation on w without 
            //violations of RBT
            else if (w->RC->color == black){
                w->LC->color = black;	//new sibling w of x is now black with red RC
                w->color     = red;	//thus case 3 transformed to case 4
                Right_Rotate(w);
                w = x->P->RC;
            }
            //case 4: x's sibling w is black and w's RC is red
            //color changes and Left_Rotation on x.p we can remove the extra black on x
            //making it singly black. Setting x=root we terminate the while loop
            else{
                w->color     = x->P->color;				
                x->P->color  = black;	
                w->RC->color = black;	
                Left_Rotate(x->P);
                x = root;               //for termination of loop
            }
        }
        //x is RC
        else{
            w = x->P->LC;
            if (w->color == red){
                w->color    = black;
                x->P->color = red;
                Right_Rotate(x->P);
                w = x->P->LC;
            }
            else if (w->RC->color == black && w->LC->color == black){
                w->color=red;
                x=x->P;
            }
            else if (w->LC->color == black) {
                w->RC->color = black;
                w->color     = red;
                Left_Rotate(w);
                w = x->P->LC;
            }
            else{
                w->color     = x->P->color;
                x->P->color  = black;
                w->LC->color = black;
                Right_Rotate(x->P);
                x = root;
            }
        }
    }
    x->color = black;
}


//delete z node, if z has fewer than 2 children we remove it and replace 
//it with successor(always successor->LC=nill)
void RB_delete(struct node* z, struct node* y, struct node *x){	
    enum type originalcolor;	//keep track of x which moves into y's original position
    originalcolor = y->color;	//Keep track of original color

    //case 1: z has no LC
    if (z->LC == nill){
        x = z->RC;
        RB_transplant(z, z->RC);    //pointers of z's R child and z's P point each other
    }
    //case 2: z has LC but no RC
    else if (z->RC == nill){
        x = z->LC;
        RB_transplant(z, z->LC);
    }
    //two cases: z has both Children
    else{
        y = tree_successor(z->RC);      //find successor
        originalcolor = y->color;       //save color of successor
        x=y->RC;
        //successor has no LC=>nill (its the minimum to the left)
        if (y->P == z){
            x->P = y;
        }
        //swap subtree of y->RC pointing to y->P (before we move y to z)
        else {
            RB_transplant(y, y->RC);		
            y->RC    = z->RC;		//partial change of y
            y->RC->P = y;
        }
        //replacement of z with y (also builds subtrees)
        RB_transplant(z, y);
        y->LC    = z->LC;
        y->LC->P = y;
        y->color = z->color;
    }
    //imbalanced RBT only possible when we delete a black node
    if (originalcolor == black)
        RB_delete_fix(x,x);
    free(z);
}

//------------------------------------------------------------------------------
//search for node to be deleted, begin at root and trace a simple path downward the tree
void search_delete(struct node *aux, double z){
    while (aux != nill && z != aux->key){
        if (z < aux->key)
            aux = aux->LC;
        else 
            aux = aux->RC;
    }
    if (aux->key == z) {
        printf("Node (%lf) found\n", z);
        //     RB_delete(aux, aux, aux);
    }
    else 
        printf("Node (%lf) does not exist\n", z);    fflush(stdout);
}


////////////////////////////////////////////////////////////////////////////////
void preordem(struct node *aux) {
    if(aux != NULL) {
        printf("%lf ", aux->key);
        preordem(aux->LC);
        preordem(aux->RC);
    }
}

void central(struct node *aux) {
    if(aux != NULL) {
        central(aux->LC);
        printf("%lf ", aux->key);
        central(aux->RC);
    }
}

//print as a tree
void tree_print(struct node *aux, struct node *nill){
}

//check in case of overwrite
int check(struct node *aux, int z, int chk){
    //compare each node with z
    while (aux != nill && z != aux->key){
        if (z < aux->key)
            aux = aux->LC;
        else 
            aux = aux->RC;
    }
    if (aux->key == z)
        chk = 1;
    return chk;
}

// ============================================
// ============================================
// ============================================

// #include "file.h"

// int menu();
// void insertAllTree(TreeS **raizS, TreeAVL **raizAVL, TreeRB **raizRB);
// void printAllTree(TreeS *raizS, TreeAVL *raizAVL, TreeRB *raizRB);

// int main() {
// 	system("clear");

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


//     return EXIT_SUCCESS;
// }

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