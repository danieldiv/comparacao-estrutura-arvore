#include "treeRedblack.h"

Tree* createTree() {
	return NULL;
}

void rotacaoSimplesDireita(Tree **t) {
	Tree *aux;

	aux = (*t)->esq;
	(*t)->esq = aux->dir;
	aux->dir = (*t);
	// (*t)->peso = getMaxPeso( getPeso( &(*t)->esq ), getPeso( &(*t)->dir ) ) + 1;
	// aux->peso = getMaxPeso( getPeso( &(*t)->esq ), (*t)->peso ) + 1;
	(*t) = aux;
}

void rotacaoSimplesEsquerda(Tree **t) {
	Tree *aux;

	aux = (*t)->dir;
	(*t)->dir = aux->esq;
	aux->esq = (*t);
	// (*t)->peso = getMaxPeso( getPeso( &(*t)->esq ), getPeso( &(*t)->dir ) ) + 1;
	// aux->peso = getMaxPeso( getPeso( &(*t)->esq ), (*t)->peso ) + 1;
	(*t) = aux;
}

// void rotacaoDuplaDireita(Tree **t) {
// 	rotacaoSimplesEsquerda(&(*t)->esq);
// 	rotacaoSimplesDireita(t);
// }

// void rotacaoDuplaEsquerda(Tree **t) {
// 	rotacaoSimplesDireita(&(*t)->dir);
// 	rotacaoSimplesEsquerda(t);
// }

void insertItem(Tree **t, Tree **p, Tree *item, Record r) {
	if(*t == NULL) {
		*t = (Tree*)malloc(sizeof(Tree));
		(*t)->esq = NULL;
		(*t)->dir = NULL;
		(*t)->reg = r;

		if((*p)->reg.key == r.key) {
			(*t)->pai = createTree();
			(*t)->cor = false;
		} else {
			(*t)->pai = *p;
			(*t)->cor = true;
		}

	} else {
		Tree *pai = (*t);
		Tree *avo = createTree();
		Tree *tio = createTree();
		// Tree *item = createTree();

		if(r.key < pai->reg.key) {
			insertItem(&pai->esq, t, item, r);
			
			
			item = pai->esq;
				

			if(pai->pai != NULL) {
				avo = pai->pai;

				if(avo->dir != NULL && avo->dir->reg.key != pai->reg.key)
					tio = avo->dir;
				else if(avo->esq != NULL && avo->esq->reg.key != pai->reg.key)
					tio = avo->esq;
			}

			if(tio) {
				if(tio->cor) {
					pai->cor = false;
					tio->cor = false;
					avo->cor = true;
					item = avo;
				} else if(item->reg.key < pai->reg.key) {
					item = pai;
					printf("valor de p esq: %d\n", (*p)->reg.key);
					rotacaoSimplesEsquerda(p);
				}
				pai->cor = false;
				avo->cor = true;

				// rotacaoSimplesDireita(p);
			}
		}

		if(r.key > pai->reg.key) {
			insertItem(&pai->dir, t, item, r);
			item = pai->dir;

			if(pai->pai != NULL) {
				avo = pai->pai;

				if(avo->dir != NULL && avo->dir->reg.key != pai->reg.key)
					tio = avo->dir;
				else if(avo->esq != NULL && avo->esq->reg.key != pai->reg.key)
					tio = avo->esq;
			}

			if(tio) {
				if(tio->cor) {
					pai->cor = false;
					tio->cor = false;
					avo->cor = true;
					item = avo;
				} else if(item->reg.key < pai->reg.key) {
					item = pai;
					rotacaoSimplesDireita(p);
				}
				pai->cor = false;
				avo->cor = true;
				// rotacaoSimplesEsquerda(p);
			}
		}

		

		printf("(%d)-(%d)", item->reg.key, pai->reg.key);

		if(avo != NULL) {
			if(tio != NULL) {
				printf("-(*%d*)-(%d)", avo->reg.key, tio->reg.key);
			}
		}
		printf("\n");
	}
}

void pesquisa(Tree **t, Tree **aux, Record r) {
	if(*t == NULL) {
		printf("[ERRO]: Node (%d) not found!\n", r.key);
		return;
	}

	if((*t)->reg.key > r.key) { pesquisa(&(*t)->esq, aux, r); return; }
	if((*t)->reg.key < r.key) { pesquisa(&(*t)->dir, aux, r); return; }

	*aux = *t;
}

void antecessor(Tree **t, Tree *aux) {
	if((*t)->dir != NULL) {
		antecessor(&(*t)->dir, aux);
		return;
	}

	aux->reg = (*t)->reg;
	aux = *t;
	*t = (*t)->esq;
	free(aux);
}

void removeItem(Tree **t, Tree **f, Record r) {
	Tree *aux;

	if(*t == NULL) {
		printf("[ERROR]: Record (%d) not found!!!\n", r.key);
		return;
	}

	if(r.key < (*t)->reg.key) { removeItem(&(*t)->esq, t, r); return; }
	if(r.key > (*t)->reg.key) { removeItem(&(*t)->dir, t, r); return; }

	if((*t)->dir == NULL) {
		aux = *t;
		*t = (*t)->esq;
		free(aux);

		return;
	}

	if((*t)->esq != NULL) {
		antecessor(&(*t)->esq, *t);
		
		return;
	}

	aux = *t;
	*t = (*t)->dir;
	free(aux);
	
}

void preordem(Tree *t) {
	if(!(t == NULL)) {
		printf("%d ", t->reg.key);
		preordem(t->esq);
		preordem(t->dir);
	}
}

void central(Tree *t) {
	if(!(t == NULL)) {
		central(t->esq);
		printf("(%d:%d)", t->reg.key, t->cor);

		if(t->pai != NULL) {
			printf(" - (pai: %d) ", t->pai->reg.key);

			if(t->pai->pai != NULL) {
				printf(" - (pai-pai: %d)", t->pai->pai->reg.key);

				if(t->pai->pai->dir != NULL && t->pai->pai->dir->reg.key != t->pai->reg.key)
					printf(" - (tio: %d)", t->pai->pai->dir->reg.key);
				else if(t->pai->pai->esq != NULL && t->pai->pai->esq->reg.key != t->pai->reg.key)
					printf(" - (tio: %d)", t->pai->pai->esq->reg.key);
			}
		}
		printf("\n");

		central(t->dir);
	}
}

void posordem(Tree *t) {
	if(!(t == NULL)) {
		posordem(t->esq);
		posordem(t->dir);
		printf("%d ", t->reg.key);
	}
}