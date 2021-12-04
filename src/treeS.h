/*
	=================================
		ARVORE BINARIA SIMPLES
	=================================
*/
#ifndef TREE_S_H
#define TREE_S_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Record Record;
typedef struct TreeS TreeS;

struct Record {
	int value;
	double key;
};

struct TreeS {
	Record reg;
	TreeS *esq, *dir;
	TreeS *pai;
};

TreeS* createTreeS();
void insertItemS(TreeS **t, Record r);
void pesquisaS(TreeS **t, TreeS **aux, Record r);

void antecessorS(TreeS **t, TreeS *aux);
void removeItemS(TreeS **t, TreeS **f, Record r);

void preordemS(TreeS *t);
void centralS(TreeS *t);
void posordemS(TreeS *t);

#endif