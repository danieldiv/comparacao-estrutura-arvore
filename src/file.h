#ifndef FILE_H
#define FILE_H

#include <string.h>
#include <time.h>

#include "treeAVL.h"
#include "treeRB.h"

#define PATH_INPUT "src/files/input"
#define PATH_SEARCH "src/files/search"

void writeFile(char *nome, int max);
void readFileInput(TreeS **raizS, TreeAVL **raizAVL, TreeRB **raizRB, int tam, double *tS, double *tAVL, double *tRB);
void readFileSearch(TreeS **raizS, TreeAVL **raizAVL, TreeRB **raizRB, int tam, double *tS, double *tAVL, double *tRB);
void randomValue();

void readFileInput1Bilhao(TreeRB **raizRB, double *tempo);
void corrigeValoresRepetidos(TreeRB **raizRB);

double get_random();

#endif