#ifndef STACK_H
#define STACK_H 1

#include "Item.h"

typedef struct stack *S;

void STACKdump(S);
S    STACKinit(int);
int  STACKempty(S);
void STACKput(S, Item);
Item STACKget(S);

#endif
