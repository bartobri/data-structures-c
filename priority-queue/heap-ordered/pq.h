#ifndef PQ_H
#define PQ_H 1

#include "Item.h"

void PQshow(void);
void PQinit(int);
 int PQempty(void);
void PQinsert(Item);
Item PQdelmax(void);

#endif
