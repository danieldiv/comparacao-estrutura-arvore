#ifndef FILE_H
#define FILE_H

#include <string.h>
#include <time.h>

#include "treeAVL.h"
#include "treeRB.h"

void writeFile(char *nome, int max);
void readFile(TreeS **raizS, TreeAVL **raizAVL, TreeRB **raizRB, char *nome);
void randomValue();

#endif