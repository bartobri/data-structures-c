#ifndef PQ_H
#define PQ_H 1

#include "Item.h"

void PQinit(void);
 int PQempty(void);
void PQinsert(Item);
Item PQdelmax(void);

#endif
