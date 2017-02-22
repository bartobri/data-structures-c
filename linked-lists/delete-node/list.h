#ifndef LIST_H
#define LIST_H 1

typedef struct node *link;
struct node {
	int item;
	link next;
};

link new_link(int);
link insert_after(link, link);
link delete_after(link);
void free_link(link);

#endif
