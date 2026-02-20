#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Please insert an integer: ");
    char input[20];
    int n;
    if (fgets(input, sizeof(input), stdin) == NULL)
    {
        printf("Error reading input");
        return 1;
    }
    n = atoi(input);
    int *safe = malloc(n * sizeof(int));
    *safe = n;
    // printf("%d ",*safe) ;

    int *csafe = calloc(*safe, sizeof(int));
    for (int i = 0; i < *safe; i++)
    {
        csafe[i] = (i + 1) * (i + 1);
    }
    for (int i = 0; i < *safe; i++)
    {
        printf("%d, ", csafe[i]);
    }
    printf("\n");
    //Doppelter Speicher:
*safe = 2*(*safe);
//printf("ouch%d",*safe);
    csafe = realloc(csafe, *safe * sizeof(int));
    for (int i = 0; i < *safe; i++)
    {
        csafe[i] = (i + 1) * (i + 1);
    }
    for (int i = 0; i <(*safe); i++)
    {
        printf("%d, ", csafe[i]);
    }
    return 0;
    free(safe);
    free(csafe);
}