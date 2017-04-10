#ifndef PQ_H
#define PQ_H 1

typedef struct pq *PQ;
typedef struct PQnode *PQlink;

PQ     PQinit(void);
int    PQempty(PQ);
PQlink PQinsert(PQ, Item);
Item   PQdelmax(PQ);
void   PQchange(PQ, PQlink, Item);
void   PQdelete(PQ, PQlink);
void   PQjoin(PQ, PQ);
void   PQdestroy(PQ);
void   PQcopy(PQ, PQ);

#endif
