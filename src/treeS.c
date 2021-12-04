#include "treeS.h"

TreeS* createTreeS() {
	return NULL;
}

void insertItemS(TreeS **t, Record r) {
	if(*t == NULL) {
		*t = (TreeS*)malloc(sizeof(TreeS));
		(*t)->esq = NULL;
		(*t)->dir = NULL;
		(*t)->reg = r;
	} else {
		if(r.key < (*t)->reg.key) 
			insertItemS(&(*t)->esq, r);

		if(r.key > (*t)->reg.key)
			insertItemS(&(*t)->dir, r);
	}
}

void pesquisaS(TreeS **t, TreeS **aux, Record r) {
	if(*t == NULL) {
		printf("[ERRO]: Node (%lf) not found!\n", r.key);
		return;
	}

	if((*t)->reg.key > r.key) { pesquisaS(&(*t)->esq, aux, r); return; }
	if((*t)->reg.key < r.key) { pesquisaS(&(*t)->dir, aux, r); return; }

	*aux = *t;
}

void antecessorS(TreeS **t, TreeS *aux) {
	if((*t)->dir != NULL) {
		antecessorS(&(*t)->dir, aux);
		return;
	}

	aux->reg = (*t)->reg;
	aux = *t;
	*t = (*t)->esq;
	free(aux);
}

void removeItemS(TreeS **t, TreeS **f, Record r) {
	TreeS *aux;

	if(*t == NULL) {
		printf("[ERROR]: Record (%lf) not found!!!\n", r.key);
		return;
	}

	if(r.key < (*t)->reg.key) { removeItemS(&(*t)->esq, t, r); return; }
	if(r.key > (*t)->reg.key) { removeItemS(&(*t)->dir, t, r); return; }

	if((*t)->dir == NULL) {
		aux = *t;
		*t = (*t)->esq;
		free(aux);

		return;
	}

	if((*t)->esq != NULL) {
		antecessorS(&(*t)->esq, *t);
		return;
	}

	aux = *t;
	*t = (*t)->dir;
	free(aux);
}

void preordemS(TreeS *t) {
	if(!(t == NULL)) {
		printf("%lf ", t->reg.key);
		preordemS(t->esq);
		preordemS(t->dir);
	}
}

void centralS(TreeS *t) {
	if(!(t == NULL)) {
		centralS(t->esq);
		printf("%lf ", t->reg.key);
		centralS(t->dir);
	}
}

void posordemS(TreeS *t) {
	if(!(t == NULL)) {
		posordemS(t->esq);
		posordemS(t->dir);
		printf("%lf ", t->reg.key);
	}
}