#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "userInfo.h"
typedef void * value;
user_info* userInfo_create(unsigned int uid, char* uname){
	user_info* newInfo = malloc(sizeof(struct user_info));
	newInfo->uid=uid;
	newInfo->uname=uname;
	return newInfo;
};
bool userInfo_compare(void* u1,void* u2){
	return ((user_info*)u1)->uid>=((user_info*)u2)->uid;
};
void userInfo_swap(void* u1,void* u2){
	unsigned int t = ((user_info*)u1)->uid;
	((user_info*)u1)->uid=((user_info*)u2)->uid;
	((user_info*)u2)->uid=t;
};
unsigned int userInfo_getUid(user_info* u){
	return u->uid;
};
char* userInfo_getUname(user_info* u){
	return u->uname;
};
