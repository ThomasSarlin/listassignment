 /* userInfo.h
   *  Thomas Sarlin
   *  Laboration 1: Systemnära programmering, HT-18
   *  Ansvarar för intiering och hantering av användarinfo.
   */
typedef struct user_info{
	unsigned int uid;
	char* uname;
}user_info;
/*
* Namn: userInfo_create
* Syfte: Skapar en ny "användare"
* Parametrar: uid,uname
* Returvärde: pekare till en ny user_info.
*/
user_info* userInfo_create(unsigned int, char*);
/*
* Namn: userInfo_compare
* Syfte: jämför två uppsättningar av user_info
* Parametrar: user_info 1, user_info2
* Returvärde: om uid för user_info 1 är större än user_info2
*/
bool userInfo_compare(void* u1,void* u2);
/*
* Namn: userInfo_swap
* Syfte: Byter värden mellan två user_info structs.
* Parametrar: user_info1,user_info2.
* Kommentar: används för att byta plats på två värden i sorteringsfunktioner.
*/
void userInfo_swap(void* u1, void* u2);
/*
* Namn: userInfo_free
* Syfte: Frigör allokerat minne för uname.
* Parametrar: pekare till en user_info struct som ska frigöras.
* Kommentar: används av listors clear funktion.
*/
void userInfo_free(void*);
/*
* Namn: userInfo_getUid
* Syfte: Hämtar uid värde från en user_info struct
* Parametrar: pekare till user_info som ska läsas av.
* Returnerar: integer värde representerande dess uid.
*/
unsigned int userInfo_getUid(user_info*);
/*
* Namn: userInfo_getUname
* Syfte: Hämtar uname värdet från en user_info struct
* Parametrar: pekare till user_info som ska läsas av.
* Returnerar: char* värde representerande dess uname.
*/
char* userInfo_getUname(user_info*);
/*
* Namn: userInfo_print
* Syfte: Skriver ut värdena i user_info som en sträng till stdout
* Parametrar: pekare till user_info som ska skrivas ut.
*/
void userInfo_print(user_info*);
