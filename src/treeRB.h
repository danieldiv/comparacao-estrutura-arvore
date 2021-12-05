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

void Left_Rotate(TreeRB **root, TreeRB *x);
void Right_Rotate(TreeRB **root, TreeRB *y);
void fix_insert(TreeRB **root, TreeRB *aux);
void insertItemRB(TreeRB **root, Record r);
void rb_insert(TreeRB **root, TreeRB *x,TreeRB *y,TreeRB *temp);
void RB_transplant(TreeRB *aux,TreeRB *auxchild);

void RB_delete_fix(TreeRB *x,TreeRB *w);
void RB_delete(TreeRB* z,TreeRB* y,TreeRB *x);
void search_delete(TreeRB *aux, Record z);

void preordemRB(TreeRB *aux);
void centralRB(TreeRB *aux);
void posordemRB(TreeRB *aux);

int check(TreeRB *aux,int z,int chk);

#endif