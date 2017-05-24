#ifndef ST_H
#define ST_H 1

#include "item.h"

void STinit(void);
void STinsert(Item);
Item STsearch(Key);
void STsort(void (*)(Item));
Item STselect(int);
void STdelete(Key);

#endif
