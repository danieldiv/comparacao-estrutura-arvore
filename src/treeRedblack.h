#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Record Record;
typedef struct Tree Tree;

struct Record {
	int value;
	int key;
};

struct Tree {
	Record reg;
	Tree *esq, *dir;
	Tree *pai;
	bool cor; // 1 - vermelho | 0 - preto
};

Tree* createTree();
void insertItem(Tree **t, Tree **p, Tree *item, Record r);
void pesquisa(Tree **t, Tree **aux, Record r);

void antecessor(Tree **t, Tree *aux);
void removeItem(Tree **t, Tree **f, Record r);

void preordem(Tree *t);
void central(Tree *t);
void posordem(Tree *t);

void rotacaoSimplesDireita(Tree **t);
void rotacaoSimplesEsquerda(Tree **t);

#endif