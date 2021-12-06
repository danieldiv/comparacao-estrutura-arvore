#include "treeAVL.h"

TreeAVL* createTreeAVL() {
	return NULL;
}

void rotacaoSimplesDireitaAVL(TreeAVL **t) {
	TreeAVL *aux;

	aux = (*t)->esq;
	(*t)->esq = aux->dir;
	aux->dir = (*t);
	(*t)->peso = getMaxPeso( getPeso( &(*t)->esq ), getPeso( &(*t)->dir ) ) + 1;
	aux->peso = getMaxPeso( getPeso( &(*t)->esq ), (*t)->peso ) + 1;
	(*t) = aux;
}

void rotacaoSimplesEsquerdaAVL(TreeAVL **t) {
	TreeAVL *aux;

	aux = (*t)->dir;
	(*t)->dir = aux->esq;
	aux->esq = (*t);
	(*t)->peso = getMaxPeso( getPeso( &(*t)->esq ), getPeso( &(*t)->dir ) ) + 1;
	aux->peso = getMaxPeso( getPeso( &(*t)->esq ), (*t)->peso ) + 1;
	(*t) = aux;
}

void rotacaoDuplaDireita(TreeAVL **t) {
	rotacaoSimplesEsquerdaAVL(&(*t)->esq);
	rotacaoSimplesDireitaAVL(t);
}

void rotacaoDuplaEsquerda(TreeAVL **t) {
	rotacaoSimplesDireitaAVL(&(*t)->dir);
	rotacaoSimplesEsquerdaAVL(t);
}

void insertItemAVL(TreeAVL **t, Record r) {
	if(*t == NULL) {
		*t = (TreeAVL*)malloc(sizeof(TreeAVL));
		(*t)->esq = NULL;
		(*t)->dir = NULL;
		(*t)->reg = r;
		(*t)->peso = 0;
	} else {
		

		if(r.key < (*t)->reg.key) {
			insertItemAVL(&(*t)->esq, r);

			if(getPeso( &(*t)->esq) - getPeso(&(*t)->dir) == 2) {
				if(r.key < (*t)->esq->reg.key)
					rotacaoSimplesDireitaAVL(t);
				else 
					rotacaoDuplaDireita(t);
			}
		}

		if(r.key > (*t)->reg.key) {
			insertItemAVL(&(*t)->dir, r);

			if(getPeso( &(*t)->dir) - getPeso(&(*t)->esq) == 2) {
				if(r.key > (*t)->dir->reg.key)
					rotacaoSimplesEsquerdaAVL(t);
				else
					rotacaoDuplaEsquerda(t);
			}
		}
	}
	(*t)->peso = getMaxPeso( getPeso( &(*t)->esq ), getPeso( &(*t)->dir ) ) + 1;

}

int getPeso(TreeAVL **t) {
	if(*t == NULL)
		return -1;
	return (*t)->peso;
}

int getMaxPeso(int left, int right) {
	if(left > right)
		return left;
	return right;
}

void pesquisaAVL(TreeAVL **t, TreeAVL **aux, Record r, double *quant) {
	(*quant)++;
	
	if(*t == NULL) {
		// printf("[ERRO]: Node (%lf) not found!\n", r.key);
		return;
	}

	if((*t)->reg.key > r.key) { pesquisaAVL(&(*t)->esq, aux, r, quant); return; }
	if((*t)->reg.key < r.key) { pesquisaAVL(&(*t)->dir, aux, r, quant); return; }

	*aux = *t;
}

void rebalanceTree(TreeAVL **t) {

	int balance;
	int left = 0;
	int right = 0;

	balance = getPeso(&(*t)->esq) - getPeso(&(*t)->dir);
	
	if((*t)->esq)
		left = getPeso(&(*t)->esq->esq) - getPeso(&(*t)->esq->dir);
	if((*t)->dir)
		right = getPeso(&(*t)->dir->esq) - getPeso(&(*t)->dir->dir);

	// printf("\n============Valores balanceamento=========\n");
	// printf("Raiz: %lf, Filho esq: %lf, Filho dir: %lf\n", balance, left, right);
	// printf("==========================================");

	if(balance == 2 && left >= 0)
		rotacaoSimplesDireitaAVL(t);
		
	if(balance == 2 && left < 0)
		rotacaoDuplaDireita(t);

	if(balance == -2 && right <= 0)
		rotacaoDuplaEsquerda(t);
	if(balance == -2 && right > 0)
		rotacaoSimplesEsquerdaAVL(t);
}

void antecessorAVL(TreeAVL **t, TreeAVL *aux) {
	if((*t)->dir != NULL) {
		antecessorAVL(&(*t)->dir, aux);
		return;
	}

	aux->reg = (*t)->reg;
	aux = *t;
	*t = (*t)->esq;
	free(aux);
}

void removeItemAVL(TreeAVL **t, TreeAVL **f, Record r) {
	TreeAVL *aux;

	if(*t == NULL) {
		printf("[ERROR]: Record (%lf) not found!!!\n", r.key);
		return;
	}

	if(r.key < (*t)->reg.key) { removeItemAVL(&(*t)->esq, t, r); return; }
	if(r.key > (*t)->reg.key) { removeItemAVL(&(*t)->dir, t, r); return; }

	if((*t)->dir == NULL) {
		aux = *t;
		*t = (*t)->esq;
		free(aux);

		rebalanceTree(f);
		return;
	}

	if((*t)->esq != NULL) {
		antecessorAVL(&(*t)->esq, *t);
		
		rebalanceTree(f);
		rebalanceTree(t);
		return;
	}

	aux = *t;
	*t = (*t)->dir;
	free(aux);
	
	rebalanceTree(f);
	rebalanceTree(t);
}

void preordemAVL(TreeAVL *t) {
	if(!(t == NULL)) {
		printf("%lf ", t->reg.key);
		preordemAVL(t->esq);
		preordemAVL(t->dir);
	}
}

void centralAVL(TreeAVL *t) {
	if(!(t == NULL)) {
		centralAVL(t->esq);
		printf("%lf ", t->reg.key);
		centralAVL(t->dir);
	}
}

void posordemAVL(TreeAVL *t) {
	if(!(t == NULL)) {
		posordemAVL(t->esq);
		posordemAVL(t->dir);
		printf("%lf ", t->reg.key);
	}
}