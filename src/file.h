#ifndef FILE_H
#define FILE_H

#include <string.h>
#include <time.h>

#include "treeAVL.h"
#include "treeRB.h"

#define PATH_INPUT "src/files/input"
#define PATH_SEARCH "src/files/search"

void writeFile(char *nome, int max);
void readFileInput(TreeS **raizS, TreeAVL **raizAVL, TreeRB **raizRB, int tamanho);
void readFileSearch(TreeS **raizS, TreeAVL **raizAVL, TreeRB **raizRB, int tamanho);
void randomValue();

double get_random();

#endif