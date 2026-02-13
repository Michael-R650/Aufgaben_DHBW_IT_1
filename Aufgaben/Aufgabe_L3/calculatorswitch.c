#include <stdio.h>

int main()
{
    float value1 = 0;
    float value2 = 0;
    char value3 = 0;
    printf("Gib den ersten Wert an:\n");
    if (scanf("%f", &value1) != 1)
    {
        printf("Input error1\n");
    }
    printf("\nGib den zweiten Wert an:\n");
    if (scanf("%f", &value2) != 1)
    {
        printf("Input error2\n");
    }
    printf("\nGib den Operanten an:\n");
    if (scanf(" %c", &value3) != 1)
    {
        printf("Input error3\n");
    }
    
    switch (value3)
    {
    case '+':
        printf("%.2f\n", (value1 + value2));
        break;
    case '-':
        printf("%.2f\n", (value1 - value2));
        break;
    case '*':
        printf("%.2f\n", (value1 * value2));
        break;
    case '/':
        if (value2 == 0)
        {
            printf("Division by 0 not possible");
        }
        else
            printf("%.2f\n", (value1 / value2));
        break;
    default:
        printf("Math error");
    }
    printf("Ende");
}