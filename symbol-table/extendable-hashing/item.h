#ifndef ITEM_H
#define ITEM_H 1

#define bitsword    32
#define bitsbyte    8
#define bytesword   4

//#define bits(A,B,C)     (A >> (bitsword - (B + C)))
#define bits(A,B,C)     ((A) >> (bitsword - ((B) + (C) + 1)))

#define key(A)          (A->key)
#define less(A,B)       (key(A) < key(B))
#define lesskey(A,B)    (A < B)
#define eq(A,B)         (key(A) == key(B))
#define eqkey(A,B)      (A == B)
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
