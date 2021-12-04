/**
    def_header.c
	Using windows.h for coloring the nodes in console.
	
    @author George Papageorgakis
    @version 1.0 01/2012
*/
#ifndef DEF_HEADER_H
#define	DEF_HEADER_H
#include <stdio.h>
#include <stdlib.h>
// #include <windows.h>   // WinApi header

void Left_Rotate(struct node *x);
void Right_Rotate(struct node *y);
void fix_insert(struct node *aux);
void rb_insert(struct node *x,struct node *y,struct node *temp);
void RB_transplant(struct node *aux,struct node *auxchild);

struct node *tree_successor(struct node *aux_succ);

void RB_delete_fix(struct node *x,struct node *w);
void RB_delete(struct node* z,struct node* y,struct node *x);
void search_delete(struct node *aux,double z);

void io_print(struct node *aux,struct node *auxnill);
void tree_print(struct node *aux,struct node *nill);

void preordem(struct node *aux);
void central(struct node *aux);
int check(struct node *aux,int z,int chk);

enum type {black, red};

struct node {
	enum type color;
	double key;
	struct node *LC, *RC, *P;
};

#endif	/* DEF_HEADER_H */

// ============================================
// ============================================
// ============================================
/*
	=================================
		ARVORE BINARIA RED BLACK
	=================================
*/
// #ifndef TREE_RB_H
// #define TREE_RB_H

// #include "treeS.h"

// #define BLACK 0
// #define RED 1

// typedef struct TreeRB TreeRB;

// struct TreeRB {
//     Record reg;
//     int cor;
//     TreeRB *pai;
//     TreeRB *esq;
//     TreeRB *dir;
// };

// TreeRB* createTreeRB();

// void insertItemRB(TreeRB **arvore, TreeRB *pPai, TreeRB **pMain, Record k);

// TreeRB *avo(TreeRB *arvore);
// TreeRB *tio(TreeRB *arvore);

// void rotacaoDireita(TreeRB **no);
// void rotacaoEsquerda(TreeRB **no);
// void consertaRB(TreeRB **arvore, TreeRB **pMain);

// void dRotacaoDireita(TreeRB **no);
// void dRotacaoEsquerda(TreeRB **no);

// void removeNo(TreeRB **arvore, Record k);

// void nBlackIBlackFRed(TreeRB *aRemover, TreeRB **arvore);
// void nBlackIBlackFBlack(TreeRB *aRemover, TreeRB **arvore);

// void nBlackIRed(TreeRB *aRemover, TreeRB **arvore);

// TreeRB *buscaNo(TreeRB *arvore, Record k);

// TreeRB *irmao(TreeRB *pai, TreeRB *noAtual);

// int filhoEsquerdo(TreeRB *arvore);

// TreeRB **maiorEsq(TreeRB **pMaiorEsq);

// void preordemRB(TreeRB *t);
// void centralRB(TreeRB *t);
// void posordemRB(TreeRB *t);

// #endif