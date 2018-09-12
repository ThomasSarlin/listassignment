#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedList.h"
#include "userInfo.h"
#include <errno.h>
#include <string.h>

void printUsrList(list*);
void printErrorList(list*);
void checkFile(char* file);
bool validFormat(char* string);
bool validUID(char* string);
bool validGID(char* string);
bool hasEmptyFields(char* string);
char* getEmptyFieldType(char* string);
unsigned int getUID(char* string);
unsigned int getGID(char* string);

int main(int argc, char *argv[]){
		
	printf("Initiating list");
	//list* linkedList= list_create();

	if(argc==2){
		checkFile(argv[1]);
	}
	if(argc==1){
		
	}	
	
	printf("Starting password sort\n");
	//list_sort(linkedList,userInfo_compare,userInfo_swap);
	//printUsrList(linkedList);
	//list_clear(linkedList);
	
	return 0;
};

void checkFile(char* file){
	FILE* fp;
	fp=fopen(file,"r");
	char* string;
	size_t len = 0;
	ssize_t read;
	int lineCount=1;
	while((read= getline(&string,&len,fp))!=-1){
		char* temp=malloc(strlen(string)+1);
		strcpy(temp,string);

		if(strlen(temp)==1)
			printf("Line %d: Encountered a <BLANKLINE>\n"
					,lineCount);
		else if(!validFormat(string)){
			printf("Line %d: Invalid format: %s\n"
					,lineCount,string);
		}
		lineCount++;
		free(temp);
	}
	fclose(fp);

}

bool validFormat(char* string){
	int count = 0;
	while(strsep(&string,":")!=NULL)
		count++;
	return count==7;
};
bool validUID(char* string){
	return true;
};
bool validGID(char* string){
	return true;
};
unsigned int getGID(char* string){
	return 0;
};
bool hasEmptyFields(char* string){
	return true;
};
char* getEmptyFieldType(char* string){
	return string;
};
unsigned int getUID(char* string){
	return 0;
};
void printUsrList(list* l){
	user_info* uinfo;
	node* n = list_first(l);
	while(list_hasNext(n)){
		n=list_next(n);
		uinfo=list_inspect(n);
		printf("%u:%s\n"
			,userInfo_getUid(uinfo)
			,userInfo_getUname(uinfo));
	}	
};
