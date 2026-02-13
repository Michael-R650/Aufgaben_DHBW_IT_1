#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX_LENGTH 101
char speicher[MAX_LENGTH];
//Methode zum Einlesen eines Wortes
void eingabe()
{
    printf("Please enter your word (max. 100 characters):");
    if (fgets(speicher, sizeof(speicher), stdin) != NULL)
    {
        speicher[strcspn(speicher, "\n")] = '\0';
    }
}
//Methode zum bestimmen eines Palindroms
void palindrom(char *p1)
{
    int length = strlen(p1);
    bool palindrom = true;

    for (int i = 0; i < (length / 2); i++)
    {   
        if (tolower(p1[i]) != tolower(p1[length - 1 - i]))
        {
            palindrom = false;
            break;
        }
    }
    if (palindrom)
    {
        printf("Your provided word %s is a palindrome.", speicher);
    }
    else
    {
        printf("Your provided word %s is not a palindrome.", speicher);
    }
}
void main()
{
    char *p1 = speicher;
    eingabe();
    palindrom(speicher);
}