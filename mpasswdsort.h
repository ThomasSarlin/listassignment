 /* mpasswdsort.h
   *  Thomas Sarlin
   *  Laboration 1: Systemnära programmering, HT-18
   *  Ansvarar för körning av programmet mpasswdsort
   */
#define ERROR_CODE 1;
#define SUCCESS_CODE 0;
/*
* Namn: run
* Syfte: Kör huvuddelen av programmet
* Parametrar: Filen som ska läsas av
* Returvärde: SUCCES_CODE om allt är OK, annars ERROR_CODE; 
*/
int run(FILE*);
/*
* Namn: sortAndPrint
* Syfte: Sortera och skriva ut listans innehåll.
* Parametrar: Listan som ska sorteras och skrivas ut.
* Returvärde: void 
* Kommentar: Anropar list_sort samt printUsrList.
*/
void sortAndPrint(list*);
/*
* Namn: addFileToList
* Syfte: Går igenom och lägger till raderna i filen till en lista
* Parametrar: Filen som ska läsas, Listan som värdena ska läggas till på.
* Returvärde: SUCCESS_CODE om felfri fil, ERROR_CODE om fel hittats. 
* Kommentar: Fel kan vara till exempel felaktigt formaterad rad.
*/

int addFileToList(FILE*, list*);

/*
* Namn: addStringToList
* Syfte: Tar ut uid & uname och lägger till dessa som ett inlägg på en
*        given lista.
* Parametrar: Strängen som ska hanteras, Listan som värdena ska läggas till på.
* Returvärde: void
* Kommentar: Bör ej kallas på med en sträng som inte 
*               hanterats av validFormat innan.
*/
void addStringToList(char*,list*);

/*
* Namn: validFormat
* Syfte: Går igenom varje block i en given password sträng och kontrollerar
*           så att varje fält är OK.
* Parametrar: Strängen som ska kontrolleras, radnumret.
* Returvärde: true om strängen är OK, false annars.
* Kommentar: Använder sig av strsep för att separera de invidividuella blocken
*               i strängen och kallar sedan på checkToken.
*/

bool validFormat(char*,int);

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
bool checkToken(char*,char*,int,int);
/*
* Namn: isEmptyField
* Syfte: Kollar om ett fält i en passwd sträng är tomt
* Parametrar: Strängen som ska kontrolleras
* Returvärde: true om den är tom, false annars.
*/
bool isEmptyField(char*);

/*
* Namn: isNumeric
* Syfte: Kollar om ett fält i passwd sträng är numeriskt.
* Parametrar: Strängen som ska kontrolleras
* Returvärde: true om den är numerisk, false annars.
*/
bool isNumeric(char*);

/*
* Namn: isPositive
* Syfte: Kollar om ett fält i en passwd sträng är positivt.
* Parametrar: Strängen som ska kontrolleras
* Returvärde: true om den är positiv, false annars.
*/
bool isPositive(char*);

/*
* Namn: printUsrList
* Syfte: Skriver ut listans innehåll.
* Parametrar: Listan som ska skrivas ut till stdout.
* Returvärde: void 
* Kommentar: använder userInfo_print för att skriva ut värdena.
*/

void printUsrList(list*);
