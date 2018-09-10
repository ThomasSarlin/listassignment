#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedList.h"

list* list_create(void){
	printf("creating list\n");
	list* newList=malloc(sizeof(struct list));
	newList->head=malloc(sizeof(struct node));
	newList->head->next=NULL;
	newList->head->prev=NULL;
	return newList;
};
bool list_isEmpty(list* l){
	return l->head->next==NULL;
};
node_pos list_next(node_pos n){
	return n->next;
};
node_pos list_prev(node_pos n){
	return n->prev;
}
node_pos list_first(list* l){
	return l->head;
};
bool list_hasNext(node_pos n){
	return n->next!=NULL;
};
node_pos list_last(list* l){
	node_pos n = list_first(l);
	while(list_hasNext(n))
		n=n->next;
	return n;
}
node_pos list_insert(node_pos n, value v){
	node_pos newNode = malloc(sizeof(struct node));
	newNode->value=v;
	newNode->prev=n;
	newNode->next=n->next;
	n->next=newNode;
	return newNode;
};
value list_inspect(node_pos n){
	return n->value;
}
void list_clear(list* l){
	while(!list_isEmpty(l)){
		node_pos n = l->head->next;
		l->head->next=n->next;
		free(n->value);
		free(n);
	}
		free(l->head);
		free(l);
};

void list_sort(list* l,compareFunc comp,swapFunc swap){
	bool swapped=true;
	while(swapped==true){
		swapped=false;
		node_pos n = list_first(l)->next;
		while(list_hasNext(n)){
			if(comp(n->value,n->next->value)){
				swap(n->value,n->next->value);
				swapped=true;
			}
			n=n->next;
		}
	}
	
};

