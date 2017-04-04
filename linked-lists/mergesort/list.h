#ifndef LIST_H
#define LIST_H 1

#include "item.h"

typedef struct node *link;
struct node {
	item key;
	link next;
};

link list_init(int);
void list_show(link);
link list_mergesort(link);

#endif
