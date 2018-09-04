#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedList.h"


linkedList linkedList_create(){
	printf("creating list");
	linkedList list=malloc(sizeof(list));
	list->head=malloc(sizeof(node));
	list->head->next=NULL;
	return list;
};
bool linkedList_isEmpty(linkedList l){
	return l->head->next==NULL;
};
node_position linkedList_next(node_position p){
	return p->next;
};

node_position linkedList_first(linkedList l){
	return l->head->next;
};

bool linkedList_hasNext(node_position p){
	return p->next!=NULL;

};

node_position linkedList_addLast(linkedList l,node_position p){
	return NULL;

};

node_position linkedList_insert(linkedList l,node_position p, value v){
	return NULL;
};

void linkedList_clear(linkedList l){
	if(linkedList_isEmpty(l)){
		free(l->head);
		free(l);
	};
};
