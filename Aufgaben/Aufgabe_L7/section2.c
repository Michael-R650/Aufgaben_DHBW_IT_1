#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
typedef struct Song
{
    double value;
    struct Song *next;
} Song;

Song *new_Node(double par_value)
{
    Song *newNode = malloc(sizeof(Song)); // Erstellen eines Knotens namens newNode mit der variablen Größe Node
    // If Abfrage, ob ein Knoten existiert und wenn nicht gibt es NULL zurück
    if (newNode == NULL)
    {
        return NULL;
    }
    // setzen den Paramaterwert ein und den ptr auf NULL
    newNode->value = par_value;
    newNode->next = NULL;
    // Rückgabe der Adresse auf den von malloc greservierten Speicher
    return newNode;
}
Song *insert_at_index(Song **head, double par_value, int index)
{
    Song *newNode = malloc(sizeof(Song)); // Erstellen eines Knotens namens newNode mit der variablen Größe Node
    if (newNode == NULL)
    {
        return NULL;
    }
    newNode->value = par_value;
    // Falls man am Anfang einfügt
    if (index == 0)
    {
        newNode->next = *head;
        *head = newNode;
        return newNode;
    }
    // Knoten vor dem Index finden
    Song *temp = *head;
    for (int i = 0; i < index - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    // Fals Index zu groß ist
    if (temp == NULL)
    {
        free(newNode);
        return NULL;
    }
    // Umsortieren der Zeigen
    newNode->next = temp->next;
    temp->next = newNode;
    return newNode;
}
void print_list(Song **head)
{
    Song *temp = *head;

    if (temp == NULL)
    {
        printf("Liste ist leer.\n");
        return ;
    }

    while (temp != NULL)
    {
        printf("%.2f, ", temp->value);
        temp = temp->next;
        if (temp != NULL)
        {
            printf("->");
        }
    }
    printf("\n");
    fflush(stdout);
}

void destroy_list(Song **head)
{
    if (head == NULL || *head == NULL)
    {
        return ;
    }
    Song *current = *head;
    Song *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}
int main()
{
    srand(time(NULL));
    // Erstellen einer leeren Liste mit *head pointer
    Song *head = NULL;
    for (int i = 0; i <= 50; i++)
    {
        insert_at_index(&head, (double)(rand() % 100), 0);
    }
    int array[51];
    int *ptr_array = &array[0];
    for (int i = 0; i <= 50; i++)
    {
        array[i] = rand();
    }
    for (int i = 50; i > 2; i--)
    {

        array[i] = array[i - 1];
    }

    *(ptr_array + 2) = rand();
    insert_at_index(&head, (double)(rand() % 100), 2);

    for (int i = 0; i <= 50; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\n");
    fflush(stdout);
    print_list(&head);
    destroy_list(&head);
    for (int i = 2; i <= 50; i++)
    {
        array[i] = 0;
    }

    printf("ENDE\n");
    return 0;
}