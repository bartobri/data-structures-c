#ifndef ITEM_H
#define ITEM_H 1


typedef char item;

#define key(A)          (A - 97)
//#define less(A,B)       (key(A) < key(B))
//#define exch(A,B)       { item t = A; A = B; B = t; }
//#define compexch(A,B)   if (less(B, A)) exch(A,B)

item item_rand(void);
void item_show(item);

#endif
