#include <stdio.h>
#include <string.h>
char input(){
    char input[99];
    char *p2 = input;
    printf("Insert a phrase:");
    if (fgets(input, sizeof(input), stdin) != NULL)
    {
        *(p2 + 1) = 'c';
        printf("Input user: %s\n", input);

    }

}
int main()
{
    char content[] = "Curly bird catches the worm";
    char *p1 = content;
    printf("Content 1: %s\n", content);
    printf("Content 2: %c\n", *p1);
    *p1 = 'E';
    *(p1 + 1) = 'a';
    printf("Content 1: %s\n", content);
    char buffer[99];
    
    input();
}