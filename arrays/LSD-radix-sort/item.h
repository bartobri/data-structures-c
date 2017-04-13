#ifndef ITEM_H
#define ITEM_h 1

#define bitsword    32
#define bitsbyte    8
#define bytesword   4
#define R           (1 << bitsbyte)
#define digit(A,B)  (((A) >> (bitsword-((B)+1)*bitsbyte)) & (R-1))

#define key(A)          (A)
#define less(A,B)       (key(A) < key(B))
#define exch(A,B)       { Item t = A; A = B; B = t; }
#define compexch(A,B)   if (less(B, A)) exch(A,B)

typedef int Item;

#endif
