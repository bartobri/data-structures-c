#ifndef ST_H
#define ST_H 1

#include "item.h"

void STinit(void);
int  STcount(void);
void STinsert(Item);
Item STsearch(Key);
Item STselect(int);
void STdelete(Key);
void STsort(void (*visit)(Item));

#endif
