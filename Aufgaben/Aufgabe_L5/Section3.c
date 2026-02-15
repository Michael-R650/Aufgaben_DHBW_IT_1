#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **acrgv)
{
    const int MAX = 9;
    const int MIN = 0;
    srand((unsigned int)time(NULL));
    int gametable[10] = {0};
    int next_simulation[10] = {0};
    int *p_gametable = gametable;
    int *p_next_Simulation = next_simulation;

    int anzahl = 3;
    int steps = 10;
    int time = 0;
    *(p_gametable + 2) = 1;
    *(p_gametable + 4) = 1;
    *(p_gametable + 6) = 1;

    // Schleife, solange es mehr als eine 1 auf dem Spielfeld gibt
    while (anzahl > 1)
    {//Ausge der Zeit,Anzahl der Einsen und des Spielbrettes
        printf("Time :%d ,Anzahl: %d Spielbrett-> ", time, anzahl);
        for (int i = 0; i < steps; i++)
        {
            printf("%d ", *(p_gametable + i));
        }
        printf("\n");
        anzahl = 0;
        // Schleife welche alle Elemente des Arrays durchläuft
        for (int i = 0; i < (steps); i++)
        { // Abfrage, ob ein Element eine 1 ist
            if (*(p_gametable + i) == 1)
            {
                anzahl++;
                // Entscheidung, ob ein Element nach rechts oder links geht
                if (rand() % 2)
                {

                    if (i > MIN)
                    {
                        *((p_next_Simulation + i - 1)) += 1;
                    }
                    else
                    {
                        *((p_next_Simulation + i)) += 1;
                    }
                }
                else
                {

                    if (i < MAX)
                    {
                        *((p_next_Simulation + 1 + i)) += 1;
                    }
                    else
                    {
                        *((p_next_Simulation + i)) += 1;
                    }
                }
            }
        }
        // Schleife zum übertragen des temporären Arrays zum anderen
        for (int i = 0; i < steps; i++)
        {
            if (*(p_next_Simulation + i) > 1)
            {
                printf("Collision on Index %d\n", i);
                *(p_next_Simulation + i) = 0;
            }
            *(p_gametable + i) = *(p_next_Simulation + i);
            *(p_next_Simulation + i) = 0;
        }
        time++;
    }
}