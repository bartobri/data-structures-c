#ifndef ITEM_H
#define ITEM_H 1

#define key(A)          (A->key)
#define less(A,B)       (key(A) < key(B))
#define exch(A,B)       { Item t = A; A = B; B = t; }
#define compexch(A,B)   if (less(B, A)) exch(A,B)

#define NULLitem NULL

typedef int Key;
typedef int Data;

typedef struct {
	Key  key;
	Data data;
} *Item;

#endif
