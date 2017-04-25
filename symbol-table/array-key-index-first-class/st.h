#ifndef ST_H
#define ST_H 1

#include "item.h"

typedef struct symbol_table *ST;

ST STinit(int);
int  STcount(ST);
void STinsert(ST, Item);
Item STsearch(ST, Key);
void STdelete(ST, Item);
Item STselect(ST, int);
void STsort(ST, void (*visit)(Item));

#endif
