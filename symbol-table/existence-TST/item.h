#ifndef ITEM_H
#define ITEM_H 1

// The digit() definition for string keys (a-z only)
#define digit(A,B)     A[B]

#define key(A)          (A)
#define less(A,B)       (key(A) < key(B))
#define lesskey(A,B)    (A < B)
#define eq(A,B)         (key(A) == key(B))
#define eqkey(A,B)      (A == B)
#define exch(A,B)       { Item t = A; A = B; B = t; }
#define compexch(A,B)   if (less(B, A)) exch(A,B)

#define NULLitem   NULL
#define NULLdigit  0

// Algorithm requires that the Key and Item typedefs are the same.
typedef char *Key;
typedef char *Item;

#endif
