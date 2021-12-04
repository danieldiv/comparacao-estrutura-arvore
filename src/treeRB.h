/*
	=================================
		ARVORE BINARIA RED BLACK
	=================================
*/
#ifndef TREE_RB_H
#define TREE_RB_H

#include "treeS.h"

#define BLACK 0
#define RED 1

typedef struct TreeRB TreeRB;

struct TreeRB {
    Record reg;
    int cor;
    TreeRB *pai;
    TreeRB *esq;
    TreeRB *dir;
};

TreeRB* createTreeRB();

void insertItemRB(TreeRB **arvore, TreeRB *pPai, TreeRB **pMain, Record k);

TreeRB *avo(TreeRB *arvore);
TreeRB *tio(TreeRB *arvore);

void rotacaoDireita(TreeRB **no);
void rotacaoEsquerda(TreeRB **no);
void consertaRB(TreeRB **arvore, TreeRB **pMain);

void dRotacaoDireita(TreeRB **no);
void dRotacaoEsquerda(TreeRB **no);

void removeNo(TreeRB **arvore, Record k);

void nBlackIBlackFRed(TreeRB *aRemover, TreeRB **arvore);
void nBlackIBlackFBlack(TreeRB *aRemover, TreeRB **arvore);

void nBlackIRed(TreeRB *aRemover, TreeRB **arvore);

TreeRB *buscaNo(TreeRB *arvore, Record k);

TreeRB *irmao(TreeRB *pai, TreeRB *noAtual);

int filhoEsquerdo(TreeRB *arvore);

TreeRB **maiorEsq(TreeRB **pMaiorEsq);

void preordemRB(TreeRB *t);
void centralRB(TreeRB *t);
void posordemRB(TreeRB *t);

#endif