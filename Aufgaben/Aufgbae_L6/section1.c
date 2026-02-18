#include <stdio.h>
#include <string.h>

int main(){
    //Öffnen einer Datei im Read Modus
FILE *datei = fopen("test.txt","w");
fputc('A',datei);
fclose(datei);
return 0;
}