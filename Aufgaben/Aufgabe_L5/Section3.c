#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **acrgv)
{
    const int LENGTH = 9;
    srand((unsigned int)time(NULL));
    int gametable[10] = {0};
    int next_simulation[10] = {0};
    int *p_gametable = gametable;
    int *p_next_Simulation = next_simulation;

    *(p_gametable + 2) = 1;
    *(p_gametable + 4) = 1;
    *(p_gametable + 6) = 1;
    int steps = 10;
    int time = 0;

    for (int i = 0; i < 10; i++)
    {

        for (int i = 0; i < (steps); i++)
        {
            if (*(p_gametable + i) == 1)
            {

                if (rand() % 2)
                {printf("%d->%d\n", i, i - 1);

                    if (i != 0)
                    {
                        
                        *(p_gametable + i) = 0;
                        *(p_next_Simulation - 1 + i) = 1;
                    }
                }
                else
                {printf("%d->%d\n", i, i + 1);
                    if (i != LENGTH)
                    {
                        
                        *(p_gametable + 1 + i) = 0;
                        *(p_next_Simulation + 1 + i) = 1;
                    }
                    // printf("%d\n",i);
                }
                //*(p_gametable+i)=0;
            }
        }

        for (int i = 0; i < steps; i++)
        {
            *(p_gametable + i) = *(p_next_Simulation + i);
            *(p_next_Simulation+i)=0;
        }
        time++;
        printf("Time :%d ", time);
        for (int i = 0; i < steps; i++)
        {
            printf("%d ", *(p_gametable + i));
        }
        printf("\n");
    }
}