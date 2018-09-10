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
	unsigned int gid,uid;
	char uname[32],pass[100],geo[300],dir[300],shell[300];
	size_t len = 0;
	ssize_t read;
	int lineCount=1;
	//unsigned int uid;
	//char* uname;
	while((read= getline(&string,&len,fp))!=-1){
		char* temp=malloc(strlen(string)+1);
		strcpy(temp,string);

		sscanf(temp,"%[^:]:%[^:]:%u:%u:%[^:]:%[^:]:%[^:]:",uname,pass,&uid,&gid,geo,dir,shell);
		printf("%s %s %d %d %s %s %s\n",uname,pass,uid,gid,geo,dir,shell);
		if(strlen(temp)==1)
			printf("Line %d: Encountered a <BLANKLINE>\n",lineCount);
		else if(!validFormat(string)){
			printf("Line %d: Invalid format: %s\n",lineCount,string);
		}else if(!validUID(string)){
			printf("Line %d: UID has to be a number. Got: \"%d\"",lineCount,getUID(string));
		}else if(!validGID){
			printf("Line %d: GID has to be a positive number. Got \"%d\""
					,lineCount,getGID(string));
		}else if(!hasEmptyFields){
			printf("Line %d: The %s field cannot be empty",lineCount,getEmptyFieldType(string));
		}
		lineCount++;
	}
	/*
	fseek(fp,0,SEEK_END);
	long fsize = ftell(fp);
	char* string = malloc(fsize+1);
	printf("%s\n",argv[1]);
	fseek(fp,0,SEEK_SET);
	fread(string,fsize,1,fp);
	*/
	fclose(fp);

}

bool validFormat(char* string){
	int count = 0;
	char* token= strtok(string,":");
	while(token!=NULL){
		count++;
		token=strtok(NULL,":");	
	}
	
	return count==7;
};
bool validUID(char* string){
	return string!="";
};
bool validGID(char* string){
	return string!="";
};
unsigned int getGID(char* string){
	return 0;
};
bool hasEmptyFields(char* string){
	return string!="";
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
		printf("%d:%s\n"
			,userInfo_getUid(uinfo)
			,userInfo_getUname(uinfo));
	}	
};
