#ifndef QUEUE_H
#define QUEUE_H 1

typedef struct queue *Q;

void QUEUEdump(Q);
Q    QUEUEinit(int);
int  QUEUEempty(Q);
void QUEUEput(Q, Item);
Item QUEUEget(Q);

#endif
