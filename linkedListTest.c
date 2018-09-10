#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedList.h"
void createListTest(){
	list* list = list_create();
	list_clear(list,NULL);
};
void addEntryToList(){
	int value= 10;
	list* list= list_create();
	node* n = list_insert(list_first(list),&value);
	if(list_isEmpty(list)){printf("not able to add to list");}
	else{ printf("%d\n",*((int*)list_inspect(n)));};
	list_clear(list,NULL);
}
int main(){
	createListTest();
	addEntryToList();
	printf("test completed\n");
	return 0;
}
