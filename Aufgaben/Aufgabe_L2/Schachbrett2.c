#include <stdio.h>

int main(){
    char buchstaben[8]={'A','B','C','D','E','F','G','H'};
    int schwarz=1;
    printf("     A   B   C   D   E   F   G   H\n");
    for (int i = 0; i < 8; i++)
    {
        
         printf("   +---+---+---+---+---+---+---+---+\n");
         printf(" %-2i|",8-i);
         schwarz++;
        for (int j = 0; j < 8; j++)
        {
           
            
            if((schwarz%2)==0){
                
                printf("###|");
            }else{
                printf("   |");
            }
            schwarz++;
        }
        printf(" %-2i\n",8-i);
    }
     printf("   +---+---+---+---+---+---+---+---+\n");
     printf("     A   B   C   D   E   F   G   H");
    
}