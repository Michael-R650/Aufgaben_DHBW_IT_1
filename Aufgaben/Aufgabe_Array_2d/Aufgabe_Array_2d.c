#include <stdio.h>

// Matrizen mit Werten
int matrix1[2][2] = {{5, 9}, {3, 6}};
int matrix2[2][2] = {{0, 3}, {2, 1}};
// Matrix fürs Zwischenspeichern
int speicher[2][2] = {{}, {}};

//Methode zum Ausgeben der Werte in klarer Struktur
void ausgabe()
{
    printf("|");
    for (int i = 0; i <= 1; i++)
    {

        for (int j = 0; j <= 1; j++)
        {
            printf("%u", matrix1[i][j]);
        }
        printf("|");
    }
    printf("\n|");
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            printf("%u", matrix2[i][j]);
        }
        printf("|");
    }
    printf("\n");
}

int main()
{
    printf("Vor dem Vertauschen:\n");
    ausgabe();
//Schleifen zum Vertauschen der Werte
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            speicher[i][j] = matrix1[i][j];
            matrix1[i][j] = matrix2[i][j];
            matrix2[i][j] = speicher[i][j];
        }
    }
    printf("Nach dem Vertauschen:\n");
    ausgabe();
}