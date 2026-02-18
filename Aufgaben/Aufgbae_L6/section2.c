#include <stdio.h>
struct car
{
    float max_fuel_level;
    int fuel_level;
    char model[50];
}
        refuel(struct car *p)
    {
        if ((p->fuel_level) < (p->max_fuel_level- 10))
        {
            p->fuel_level += 10;
        }
    }
    void print_fuel_level(struct car *p)
    {
        printf("Current Fuel Level: %i\n", p->fuel_level);
    }
 int main()
{
    struct car eins = {100, 14, "Audi A4"};
    refuel(&eins);
    print_fuel_level(&eins);

     
}