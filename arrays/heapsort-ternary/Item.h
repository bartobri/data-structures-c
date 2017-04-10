#ifndef ITEM_H
#define ITEM_H 1

#define key(A)          (A)
#define less(A,B)       (key(A) < key(B))
#define exch(A,B)       { Item t = A; A = B; B = t; }
#define compexch(A,B)   if (less(B, A)) exch(A,B)
#define min(A,B)        (A < B) ? A : B

typedef int Item;

#endif
