#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "userInfo.h"
typedef void * value;

/*
* Namn: userInfo_create
* Syfte: Skapar en ny "användare"
* Parametrar: uid,uname
* Returvärde: pekare till en ny user_info.
*/

user_info* userInfo_create(unsigned int uid, char* uname){
	user_info* newInfo = malloc(sizeof(struct user_info));
	if(!newInfo){
		perror("no memory available");
		exit(1);
	}
	newInfo->uid=uid;
	newInfo->uname=uname;
	return newInfo;
};

/*
* Namn: userInfo_compare
* Syfte: jämför två uppsättningar av user_info
* Parametrar: user_info 1, user_info2
* Returvärde: om uid för user_info 1 är större än user_info2
*/

bool userInfo_compare(void* u1,void* u2){
	return ((user_info*)u1)->uid>((user_info*)u2)->uid;
};

/*
* Namn: userInfo_swap
* Syfte: Byter värden mellan två user_info structs.
* Parametrar: user_info1,user_info2.
* Kommentar: används för att byta plats på två värden i sorteringsfunktioner.
*/

void userInfo_swap(void* u1,void* u2){
	unsigned int t = ((user_info*)u1)->uid;
	((user_info*)u1)->uid=((user_info*)u2)->uid;
	((user_info*)u2)->uid=t;
	char *t2 = ((user_info*)u1)->uname;
	((user_info*)u1)->uname=((user_info*)u2)->uname;
	((user_info*)u2)->uname=t2;
	
};

/*
* Namn: userInfo_free
* Syfte: Frigör allokerat minne för uname.
* Parametrar: pekare till en user_info struct som ska frigöras.
* Kommentar: används av listors clear funktion.
*/

void userInfo_free(void* u){
	free(((user_info*)u)->uname);
}

/*
* Namn: userInfo_getUid
* Syfte: Hämtar uid värde från en user_info struct
* Parametrar: pekare till user_info som ska läsas av.
* Returnerar: integer värde representerande dess uid.
*/

unsigned int userInfo_getUid(user_info* u){
	return u->uid;
};

/*
* Namn: userInfo_getUname
* Syfte: Hämtar uname värdet från en user_info struct
* Parametrar: pekare till user_info som ska läsas av.
* Returnerar: char* värde representerande dess uname.
*/

char* userInfo_getUname(user_info* u){
	return u->uname;
};

/*
* Namn: userInfo_print
* Syfte: Skriver ut värdena i user_info som en sträng till stdout
* Parametrar: pekare till user_info som ska skrivas ut.
*/

void userInfo_print(user_info *u){
	printf("%u:%s\n"
			,userInfo_getUid(u)
			,userInfo_getUname(u));
}
