#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Error");
    }
    for (int i = 0; i < argc; i++)
    {
        printf("Argument %d at adress %p has content: %s (length:%d)\n", i, argv[i], argv[i], strlen(argv[i]));
    }
}
