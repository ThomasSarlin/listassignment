 /* mpasswdsort.c
   *  Thomas Sarlin
   *  Laboration 1: Systemnära programmering, HT-18
   *  Ansvarar för körning av programmet mpasswdsort
   */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include "linkedList.h"
#include "userInfo.h"
#include "mpasswdsort.h"

int main(int argc, char *argv[]){
	int result=SUCCESS_CODE;
	FILE *fp;
	if(argc==1){
		fp = stdin;
		if(!fp){
			perror("stdin");
			result=ERROR_CODE;
		}else
			result = run(fp);
	}
	else if(argc==2){
		fp = fopen(argv[1],"r");
		if(!fp){
			perror(argv[1]);
			result=ERROR_CODE;
		}else
			result = run(fp);
	}
	else{
		fprintf(stderr,"Invalid number of arguments\n");
		result=ERROR_CODE;
	}
	return result;
};

/*
* Namn: run
* Syfte: Kör huvuddelen av programmet
* Parametrar: Filen som ska läsas av
* Returvärde: SUCCES_CODE om allt är OK, annars ERROR_CODE; 
*/

int run(FILE *fp){
		list *l;
		int result = SUCCESS_CODE;
		l=list_create();
		result=addFileToList(fp,l);
		sortAndPrint(l);
		list_clear(l,userInfo_free);
		fclose(fp);
		return result;
}
/*
* Namn: sortAndPrint
* Syfte: Sortera och skriva ut listans innehåll.
* Parametrar: Listan som ska sorteras och skrivas ut.
* Returvärde: void 
* Kommentar: Anropar list_sort samt printUsrList.
*/
void sortAndPrint(list *l){
	if(l!=NULL){
		if(!list_isEmpty(l)){
			list_sort(l,userInfo_compare,userInfo_swap);
			printUsrList(l);
		}	
	}
}
/*
* Namn: addFileToList
* Syfte: Går igenom och lägger till raderna i filen till en lista
* Parametrar: Filen som ska läsas, Listan som värdena ska läggas till på.
* Returvärde: SUCCESS_CODE om felfri fil, ERROR_CODE om fel hittats. 
* Kommentar: Fel kan vara till exempel felaktigt formaterad rad.
*/
int addFileToList(FILE* fp,list *l){
	char *string=NULL, *strCopy=NULL;
	size_t len = 0;
	ssize_t read;
	int lineCount=1;
	int result=SUCCESS_CODE;

	while((read= getline(&string,&len,fp))!=-1){
		strCopy=malloc(strlen(string)*sizeof(char)+1);
		if(!strCopy)perror("no memory available");
		strCopy=strcpy(strCopy,string);
		if(validFormat(strCopy,lineCount)){
			addStringToList(string,l);	
		}
		else{
			result=ERROR_CODE;
		}
		lineCount++;
		free(strCopy);
	}
	free(string);
	return result;
}
/*
* Namn: addStringToList
* Syfte: Tar ut uid & uname och lägger till dessa som ett inlägg på en
*        given lista.
* Parametrar: Strängen som ska hanteras, Listan som värdena ska läggas till på.
* Returvärde: void
* Kommentar: Bör ej kallas på med en sträng som inte 
*               hanterats av validFormat innan.
*/
void addStringToList(char *s,list *l){
	int count = 0;
	char *token,*uname;
	unsigned int uid;
	
	while((token=strsep(&s,":"))!=NULL){
		switch(count){
			case 0:
				uname = malloc(strlen(token)*sizeof(char)+1);
				if(!uname)perror("no memory available");
				uname = strcpy(uname,token);
				break;
			case 2:
				uid = strtol(token,NULL,0);
			default:
				break;
		}
		count++;
	}
	
	list_insert(list_first(l),userInfo_create(uid,uname));
}

/*
* Namn: validFormat
* Syfte: Går igenom varje block i en given password sträng och kontrollerar
*           så att varje fält är OK.
* Parametrar: Strängen som ska kontrolleras, radnumret.
* Returvärde: true om strängen är OK, false annars.
* Kommentar: Använder sig av strsep för att separera de invidividuella blocken
*               i strängen och kallar sedan på checkToken.
*/

bool validFormat(char* string,int lineCount){
	if(strlen(string)==1){
		fprintf(stderr,"Line %d: Encountered a <BLANKLINE>\n"
			,lineCount);
		return false;
	}
	
	int count = 0;
	bool validFormat=true;
	char *token, *fullstring;
	fullstring=malloc(strlen(string)*sizeof(char)+1);
	if(!fullstring)perror("no memory available");
	fullstring=strcpy(fullstring,string);
	fullstring =strtok(fullstring,"\n");

	while((token=strsep(&string,":"))!=NULL && validFormat){
		validFormat=checkToken(fullstring,token,lineCount,count);
		count++;
	}
	if(count!=7 && validFormat){
		validFormat=false;
		fprintf(stderr,"Line %d: Invalid format:" 
			" '%s'\n",lineCount,fullstring);
	}
	free(fullstring);
	return validFormat;
};

/*
* Namn: checkToken
* Syfte: Går igenom en specifik del av en passwd sträng och kontrollerar
*           dess värde mot labspecifikationen.
* Parametrar:   Hela passwdsträngen (används för utskrift),
*               Sträng som representerar ett fält i passwd strängen,
*               Integer representerande det fältnummer som ska kontrolleras,
*               Radnumret för den givna passwd strängen (används för utskrift).
* Returvärde: true ifall fältet är OK, annars false.
* Kommentar: denna funktion skriver ut meddelanden till stderr ifall fel
*                med fältet upptäckts. Returvärdet bör användas för att 
*               indikera att hela strängen är felaktig vid upptäckt fel.
*/

bool checkToken(char* fullstring,char* token,int lineCount,int index){
	bool result=true;
	switch(index){
		case 0:
			if(isEmptyField(token)){
				fprintf(stderr, "Line %d: The username\
					 field cannot be empty\n",lineCount);
				result=false;
			}
			break;
	       	case 2:
			if(isEmptyField(token)){
				fprintf(stderr, "Line %d: The uid field" 
					" cannot be empty\n",lineCount);
				result=false;
			}
			else if(!isPositive(token)){
				fprintf(stderr,"Line %d: the 'uid' field" 
						" has to be a positive"
						" number: %s\n",
						lineCount,fullstring);	
				result=false;
			}
			else if(!isNumeric(token)){
				fprintf(stderr,"Line %d: The 'uid' field" 
					" has to be numeric: %s\n"
					,lineCount,fullstring);
				result=false;
			}
			break;
		case 3:
			if(isEmptyField(token)){
				fprintf(stderr, "Line %d: The gid field" 
				" cannot be empty\n",lineCount);
				result=false;
			}	
			else if(!isPositive(token)){
				fprintf(stderr,"Line %d: the 'uid' field" 
					" has to be a positive number: %s\n",
					lineCount,fullstring);	
				result=false;
			}

			else if(!isNumeric(token)){
				fprintf(stderr,"Line %d: The 'gid' field" 
					" has to be numeric: %s\n"
					,lineCount,fullstring);
				result=false;
			}
							
			break;
		case 5:	
			if(isEmptyField(token)){
				fprintf(stderr, "Line %d: The directory" 
					" field cannot be empty\n",lineCount);
				result=false;
			}
			break;
		case 6:	
			if(isEmptyField(token)){
				fprintf(stderr, "Line %d: The shell" 
					" field cannot be empty\n",lineCount);
				result=false;
			}
			break;
		default:
			break;
	}
	return result;
}
/*
* Namn: isEmptyField
* Syfte: Kollar om ett fält i en passwd sträng är tomt
* Parametrar: Strängen som ska kontrolleras
* Returvärde: true om den är tom, false annars.
*/

bool isEmptyField(char *s){
	return s[0]=='\0';
}

/*
* Namn: isNumeric
* Syfte: Kollar om ett fält i passwd sträng är numeriskt.
* Parametrar: Strängen som ska kontrolleras
* Returvärde: true om den är numerisk, false annars.
*/

bool isNumeric(char *s){
	bool result=true;
	while(*s){
		if(!isdigit(*s++))result=false;
	}
	return result;
						
}

/*
* Namn: isPositive
* Syfte: Kollar om ett fält i en passwd sträng är positivt.
* Parametrar: Strängen som ska kontrolleras
* Returvärde: true om den är positiv, false annars.
*/

bool isPositive(char* s){
	return (strtol(s,NULL,0)>=0);
}

/*
* Namn: printUsrList
* Syfte: Skriver ut listans innehåll.
* Parametrar: Listan som ska skrivas ut till stdout.
* Returvärde: void 
* Kommentar: använder userInfo_print för att skriva ut värdena.
*/

void printUsrList(list* l){
	user_info* uinfo;
	node* n = list_first(l);
	while(list_hasNext(n)){
		n=list_next(n);
		uinfo=list_inspect(n);
		userInfo_print(uinfo);
	}	
};
