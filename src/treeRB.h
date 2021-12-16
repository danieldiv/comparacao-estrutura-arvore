/*
	=================================
		ARVORE BINARIA RED BLACK
	=================================
*/
#ifndef TREE_RB_H
#define TREE_RB_H

#include "treeS.h"

enum type {black, red};

typedef struct  TreeRB TreeRB;

struct TreeRB {
	enum type color;
	Record reg;

	TreeRB *LC;
	TreeRB *RC;
	TreeRB *P;
};

void inicializaTreeRB(TreeRB **root);

TreeRB *tree_successor(TreeRB *aux_succ);

void rotacaoEsquerda(TreeRB **root, TreeRB *item);
void rotacaoDireita(TreeRB **root, TreeRB *item);
void fix_insert(TreeRB **root, TreeRB *aux);
void insertItemRB(TreeRB **root, Record r, int *contadorRP, int *cont);

void rb_insert(TreeRB **root, TreeRB *x,TreeRB *y,TreeRB *temp);

void RB_delete(TreeRB **root, TreeRB* z,TreeRB* y,TreeRB *x);
void RB_delete_fix(TreeRB **root, TreeRB *x,TreeRB *w);
void RB_transplant(TreeRB **root, TreeRB *aux,TreeRB *auxchild);

void searchRB(TreeRB *aux, Record z, double *quant);
void search_delete(TreeRB **root, TreeRB *aux, Record z);

void preordemRB(TreeRB *aux);
void centralRB(TreeRB *aux);
void posordemRB(TreeRB *aux);

int check(TreeRB *aux,double z,int chk);

// void insertItemRBCorrecao(TreeRB **root, Record r, int *contadorRP, int *cont);

#endif