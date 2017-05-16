#ifndef ITEM_H
#define ITEM_H 1

#define bitsword    8
#define bitsbyte    1
#define bytesword   8
#define R           (1 << bitsbyte)
#define digit(A,B)  (((A) >> (bitsword-((B)+1)*bitsbyte)) & (R-1))

#define key(A)          (A->key)
#define less(A,B)       (key(A) < key(B))
#define lesskey(A,B)    (A < B)
#define eq(A,B)         (key(A) == key(B))
#define eqkey(A,B)      (A == B)
#define exch(A,B)       { Item t = A; A = B; B = t; }
#define compexch(A,B)   if (less(B, A)) exch(A,B)

#define NULLitem NULL

typedef unsigned char Key;
typedef int Data;

typedef struct {
	Key  key;
	Data data;
} *Item;

#endif
