#ifndef ITEM_H
#define ITEM_H 1

typedef int item;

//#define key(A)          (A.key)
#define item_less(A,B)       (A < B)
//#define exch(A,B)       { item t = A; A = B; B = t; }
//#define compexch(A,B)   if (less(B, A)) exch(A,B)

item item_rand(void);
item item_dummy(void);
void item_show(item);

#endif
