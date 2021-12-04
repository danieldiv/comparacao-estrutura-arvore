#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "treeRB.h"

TreeRB* createTreeRB() {
    return NULL;
}

void insertItemRB(TreeRB **arvore, TreeRB *pPai, TreeRB **pMain, Record k) {
    assert(arvore);

    if (*arvore == NULL) {
        *arvore = (TreeRB*)malloc(sizeof(TreeRB));
        if (*arvore == NULL) return;

        (*arvore)->reg.key = k.key;
        (*arvore)->cor = RED;

        (*arvore)->esq = NULL;
        (*arvore)->dir = NULL;
        (*arvore)->pai = pPai;
        // return;
    } else {
        if (k.key < (*arvore)->reg.key) {
            insertItemRB(&((*arvore)->esq), *arvore, pMain, k);
            return;

            consertaRB(&((*arvore)->esq), pMain);
            return;
        } else if (k.key > (*arvore)->reg.key) {
            insertItemRB(&((*arvore)->dir), *arvore, pMain, k);
            return; 

            consertaRB(&((*arvore)->dir), pMain);
            return;
        }
        return;
    }
    return;
}

TreeRB *avo(TreeRB *arvore) {
    if ((arvore != NULL) && (arvore->pai != NULL))
            return (arvore->pai)->pai;
    else
        return NULL;
}

TreeRB *tio(TreeRB *arvore) {
    TreeRB *nAvo = avo(arvore);
    if (nAvo == NULL) return NULL;

    if (arvore->pai == nAvo->esq)
        return nAvo->dir;
    else
        return nAvo->esq;

}

void rotacaoDireita(TreeRB **no) {
    assert(no);

    if (*no == NULL) return;

    TreeRB *aux = *no;
    *no = aux->esq;

    if (*no == NULL) return; // este return
    
    aux->esq = (*no)->dir;
    (*no)->dir = aux;

    (*no)->pai = aux->pai;
    if(aux->dir != NULL)
        (aux->dir)->pai = aux;

    aux->pai = *no;

    aux->cor = RED;
    (*no)->cor = BLACK;

}

void rotacaoEsquerda(TreeRB **no) {
    assert(no);

    if (*no == NULL) return;

    TreeRB *aux = *no;

    *no = aux->dir;
    
    if (*no == NULL) return; // este return

    aux->dir = (*no)->esq;
    (*no)->esq = aux;
    (*no)->pai = aux->pai;

    if (aux->esq != NULL)
        (aux->esq)->pai = aux;

    aux->pai = *no;
 
    aux->cor = RED;
    (*no)->cor = BLACK;
}

void consertaRB(TreeRB **arvore, TreeRB **pMain) {
    assert(arvore);

    TreeRB *nAvo = NULL;
    TreeRB *nTio = NULL;

    printf("chamou o conserta\n");
    if((*arvore)->pai != NULL) {
        if((*arvore)->pai->cor == BLACK) return;

        if((*arvore)->cor == RED) {
            nTio = tio(*arvore); 
            if (nTio != NULL && nTio->cor == RED) {
                nAvo = avo(*arvore);
                (*arvore)->pai->cor = BLACK;
                nTio->cor = BLACK;
                if (nAvo->pai != NULL) {
                    nAvo->cor = RED;
                } 
            } else {
                nAvo = avo(*arvore);
                if (nAvo != NULL) {
                    if ((*arvore)->pai == nAvo->esq) { // filho esquerdo
                        if ((*arvore) == (nAvo->esq)->esq) {
                            if (nAvo->pai != NULL) {
                                if ((nAvo->pai)->esq == nAvo) {
                                    rotacaoDireita(&((nAvo->pai)->esq));
                                }
                                    
                                else {
                                    rotacaoDireita(&((nAvo->pai)->dir));
                                }
                                    
                            } else {
                                rotacaoDireita(pMain);
                            }


                       } else {
                           if (nAvo->pai != NULL) {
                               if ((nAvo->pai)->esq == nAvo) {
                                    dRotacaoDireita(&((nAvo->pai)->esq));
                               } else {
                                   dRotacaoDireita(&((nAvo->pai)->dir));
                               }
                           } else { 
                                dRotacaoDireita(pMain);
                           }
                      }
                   } else { 
                       if ((*arvore) == ((nAvo->dir)->dir)) {
                           if (nAvo->pai != NULL) {
                               if (((nAvo->pai)->esq) == nAvo) {
                                    rotacaoEsquerda(&((nAvo->pai)->esq));
                               } else {
                                   rotacaoEsquerda(&((nAvo->pai)->dir));
                               }
                                   
                           } else {
                                rotacaoEsquerda(pMain);
                           }

                       } else {
                           if (nAvo->pai != NULL) {
                               if((nAvo->pai)->esq == nAvo) {
                                    dRotacaoEsquerda(&((nAvo->pai)->esq));
                               } else {
                                   dRotacaoEsquerda(&((nAvo->pai)->dir));
                               }
                           } else {
                                dRotacaoEsquerda(pMain);
                           }
                       }
                    }
                }
            }
        }
    }
}

void dRotacaoEsquerda(TreeRB **no) {
    assert(no);

    rotacaoDireita(&((*no)->dir));
    rotacaoEsquerda(no);
    
}

void dRotacaoDireita(TreeRB **no) {
    assert(no);

    rotacaoEsquerda(&((*no)->esq));
    rotacaoDireita(no);
    
}

// void removeNo(TreeRB **arvore, Record k){
//     assert(arvore);

//     if((*arvore) == NULL) return;

//     TreeRB *aRemover = *arvore;

//     aRemover = buscaNo(aRemover, k);

//     if(aRemover == NULL) return;

//     if(aRemover->dir == NULL && aRemover->esq == NULL){
//         if(aRemover->pai == NULL){
//             free(aRemover);
//             *arvore = NULL;
//             return;
//         } else {
//             if(aRemover->cor == RED && aRemover->dir == NULL && aRemover->esq == NULL){
//                 if(filhoEsquerdo(aRemover) == 1){
//                     free(aRemover);
//                     aRemover->pai->esq = NULL;
//                 } else {
//                     free(aRemover);
//                     aRemover->pai->dir = NULL;
//                 }
//                 return;
//             } else {
//                 TreeRB *nIrmao = irmao(aRemover->pai,aRemover);
//                     if(nIrmao == NULL) return;

//                 if(aRemover->cor == BLACK && nIrmao->cor == BLACK){
//                     if(nIrmao->dir == NULL && nIrmao->esq == NULL){
//                         nBlackIBlackFBlack(aRemover, arvore);
//                         return;
//                     } else if(nIrmao->esq->cor == BLACK && nIrmao->dir->cor == BLACK){
//                         nBlackIBlackFBlack(aRemover, arvore);
//                         return;
//                     }
//                     else if(nIrmao->dir->cor == BLACK && nIrmao->esq == NULL){
//                         nBlackIBlackFBlack(aRemover, arvore);
//                         return;
//                     }
//                     else if(nIrmao->esq->cor == BLACK && nIrmao->dir == NULL){
//                         nBlackIBlackFBlack(aRemover, arvore);
//                         return;
//                     }
//                 } else if(aRemover->cor == BLACK && nIrmao->cor == BLACK && (nIrmao->esq->cor == RED || nIrmao->dir->cor == RED)){
//                     if(nIrmao->esq != NULL){
//                         nBlackIBlackFRed(aRemover, arvore);
//                         return;
//                     } else if (nIrmao->dir != NULL){
//                         nBlackIBlackFRed(aRemover, arvore);
//                         return;
//                     }
//                 } else if(aRemover->cor == BLACK && nIrmao->cor == RED){
//                     nBlackIRed(aRemover, arvore);
//                 }
//             }

//             return;
//         }
//     } else if (aRemover->dir == NULL || aRemover->esq == NULL){
//         if(aRemover->dir != NULL){
//             aRemover->reg.key = aRemover->dir->reg.key;
//             free(aRemover->dir);
//             aRemover->dir = NULL;
//         } else {
//             aRemover->reg.key = aRemover->esq->reg.key;
//             free(aRemover->esq);
//             aRemover->esq = NULL;
//         }
//     } else {
//         TreeRB **nSubstituto = maiorEsq(&(aRemover->esq));
//         TreeRB *auxSubstituto = *nSubstituto;

//         aRemover->reg.key = (*nSubstituto)->reg.key;
//         (*nSubstituto)->pai->esq = (*nSubstituto)->esq;


//         if(aRemover->cor == RED){
//             if(aRemover->esq == NULL && aRemover == aRemover->pai->esq && (aRemover->dir->dir != NULL || aRemover->dir->esq != NULL)){
//                 if(aRemover->dir->dir != NULL){
//                     rotacaoDireita(&(aRemover->esq));
//                     rotacaoEsquerda(&aRemover);
//                 }
//                 if(aRemover->dir->esq != NULL){
//                     rotacaoDireita(&(aRemover->dir));
//                     rotacaoEsquerda(&aRemover);
//                 }
//             } else if(aRemover->esq == NULL && aRemover == aRemover->pai->dir && (aRemover->esq->dir != NULL || aRemover->esq->esq != NULL)){
//                 if(aRemover->esq->dir != NULL){
//                     rotacaoEsquerda(&(aRemover->esq));
//                     rotacaoDireita(&aRemover);
//                 }
//                 if(aRemover->esq->esq != NULL){
//                     rotacaoEsquerda(&(aRemover->esq));
//                     rotacaoDireita(&aRemover);
//                 }
//             }

//             aRemover->cor = BLACK;
//             if(aRemover->esq != NULL)
//                 aRemover->esq->cor = RED;
//             if(aRemover->dir != NULL)
//                 aRemover->dir->cor = RED;
//         }
//         free(auxSubstituto);
//     }
// }

void nBlackIBlackFRed(TreeRB *aRemover, TreeRB **arvore){
    assert(arvore);

    TreeRB *paiARemover = aRemover->pai;

    if(filhoEsquerdo(aRemover) == 1){
        free(aRemover);
        aRemover->pai->esq = NULL;
    } else {
        free(aRemover);
        aRemover->pai->dir = NULL;
    }

    if(paiARemover->esq == NULL){
        if(paiARemover->pai == NULL){
            if((paiARemover->dir)->dir == NULL){
                rotacaoDireita(&((*arvore)->dir));
            }
            rotacaoEsquerda(arvore);
        } 
        else {
            if((paiARemover->dir)->dir == NULL){
                rotacaoDireita(&(paiARemover->dir));
            }
            rotacaoEsquerda(&paiARemover);
        }
    } 
    else {
        if(paiARemover->pai == NULL){
            if((paiARemover->esq)->esq == NULL){
                rotacaoEsquerda(&((*arvore)->esq));
            }
            rotacaoDireita(arvore);
        } else {
            if((paiARemover->dir)->dir == NULL){
                rotacaoEsquerda(&(paiARemover->esq));
            }
            rotacaoDireita(&paiARemover);
        }
    }
    return;
}

void nBlackIBlackFBlack(TreeRB *aRemover, TreeRB **arvore){
    assert(arvore);

    TreeRB *paiARemover = aRemover->pai;
    TreeRB *nIrmao = irmao(paiARemover, aRemover);

    nBlackIRed(aRemover, arvore);

    paiARemover->cor = BLACK;
    nIrmao->cor = RED;
}

void nBlackIRed(TreeRB *aRemover, TreeRB **arvore){
    assert(arvore);

    TreeRB *paiARemover = aRemover->pai;

    nBlackIBlackFRed(aRemover,arvore);

    paiARemover->cor = BLACK;
    if(paiARemover->esq != NULL)
        (paiARemover->esq)->cor = RED;
    if(paiARemover->dir != NULL)
        (paiARemover->dir)->cor = RED;
}

// TreeRB *buscaNo(TreeRB *arvore, Record k){
//     if (arvore == NULL) return NULL;

//     if (arvore->reg.key == k.key) return arvore;

//     if (k.key < arvore->reg.key)
//         return buscaNo(arvore->esq, k);
//     else
//         return buscaNo(arvore->dir, k);
// }

TreeRB *irmao(TreeRB *pai, TreeRB *noAtual){
    if(pai == NULL) return NULL;

    if(pai->dir->reg.key == noAtual->reg.key)
        return pai->esq;
    else
        return pai->dir;
}

int filhoEsquerdo(TreeRB *arvore){
    if(arvore->pai->esq == arvore)
        return 1;
    else
        return 0;
}

TreeRB **maiorEsq(TreeRB **pMaiorEsq){
    assert(pMaiorEsq);
    
    if (*pMaiorEsq == NULL) return NULL;

    if ((*pMaiorEsq)->dir == NULL)
        return pMaiorEsq;
    else
        return maiorEsq(&((*pMaiorEsq)->dir));
}

void preordemRB(TreeRB *t) {
	if(!(t == NULL)) {
		printf("%lf ", t->reg.key);
		preordemRB(t->esq);
		preordemRB(t->dir);
	}
}

void centralRB(TreeRB *t) {
	if(!(t == NULL)) {
		centralRB(t->esq);
		printf("%lf ", t->reg.key);
		centralRB(t->dir);
	}
}

void posordemRB(TreeRB *t) {
	if(!(t == NULL)) {
		posordemRB(t->esq);
		posordemRB(t->dir);
		printf("%lf ", t->reg.key);
	}
}