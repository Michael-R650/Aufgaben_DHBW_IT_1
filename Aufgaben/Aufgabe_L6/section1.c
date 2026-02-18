#include <stdio.h>
#include <string.h>
 #include <direct.h>
int main(){
   
char cwd[500];
_getcwd(cwd, 500);
printf("Working directory: %s\n", cwd);
FILE *datei = fopen("test.txt", "r");
if (!datei) {
    perror("Fehler beim Öffnen");
    return 1;
}

    //Öffnen einer Datei im Read Modus
//FILE *datei = fopen("test.txt","w");
// fputc('K',datei);
// fputs("Random sentence without a sense", datei);
// fclose(datei);'
//FILE *datei = fopen("test.txt", "r");
char ausgabe = fgetc(datei);
printf("Inserted Char: %c\n",ausgabe);
rewind(datei);

char myString[100];
fgets(myString,100,datei);

printf("String:%s\n",myString);
fclose(datei);

return 0;
}