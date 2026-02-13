#include <stdio.h>

int main(){
    char buchstaben[8]={'A','B','C','D','E','F','G','H'};
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%c%-4i",buchstaben[j],(8-i));
        }
        printf("\n");
    }
    
}