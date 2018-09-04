#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedList.h"
void createListTest(){
	linkedList list = linkedList_create();
	linkedList_clear(list);
};
int main(){
	createListTest();
	printf("test completed\n");
	return 0;
}
