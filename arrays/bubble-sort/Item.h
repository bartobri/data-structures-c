#ifndef ITEM_H
#define ITEM_h 1

#define key(A)          (A.key)
#define less(A,B)       (key(A) < key(B))
#define exch(A,B)       { Item t = A; A = B; B = t; }
#define compexch(A,B)   if (less(B, A)) exch(A,B)

typedef struct {
	int key;
	int val;
} Item;

#endif
