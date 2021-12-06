/*
	=================================
		ARVORE BINARIA AVL
	=================================
*/
#ifndef TREE_AVL_H
#define TREE_AVL_H

#include "treeS.h"

typedef struct TreeAVL TreeAVL;

struct TreeAVL {
	Record reg;
	TreeAVL *esq, *dir;
	int peso;
	TreeAVL *pai;
};

TreeAVL* createTreeAVL();
void insertItemAVL(TreeAVL **t, Record r);
void pesquisaAVL(TreeAVL **t, TreeAVL **aux, Record r, double *quant);

void antecessorAVL(TreeAVL **t, TreeAVL *aux);
void removeItemAVL(TreeAVL **t, TreeAVL **f, Record r);
void rebalanceTree(TreeAVL **t);

void preordemAVL(TreeAVL *t);
void centralAVL(TreeAVL *t);
void posordemAVL(TreeAVL *t);

int getPeso(TreeAVL **t);
int getMaxPeso(int left, int right);

void rotacaoSimplesDireita(TreeAVL **t);
void rotacaoSimplesEsquerda(TreeAVL **t);
void rotacaoDuplaDireita(TreeAVL **t);
void rotacaoDuplaEsquerda(TreeAVL **t);

#endif