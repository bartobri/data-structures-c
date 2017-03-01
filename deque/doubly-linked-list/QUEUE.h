#ifndef QUEUE_H
#define QUEUE_H 1

#include "Item.h"

void QUEUEinit(int);
int  QUEUEempty(void);
void QUEUEputhead(Item);
void QUEUEputtail(Item);
Item QUEUEgethead(void);
Item QUEUEgettail(void);

#endif
