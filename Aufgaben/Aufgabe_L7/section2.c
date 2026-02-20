// // Ich hasse es Listen selber zu bauen
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <time.h>

// typedef struct Node
// {
//     double value;
//     struct Node *next;
// } Node;

// Node *new_Node(double p_value)
// {
//     Node *newNode = malloc(sizeof(Node)); // reserviert Speicher für genau ein Node
//     if (newNode == NULL)
//     {
//         return NULL;
//     }
//     newNode->value = p_value;
//     newNode->next = NULL;
//     return newNode;
// }

// Node *end_Node(Node **head, Node *newNode)
// {
//     if (*head == NULL)
//     {
//         *head = newNode;
//         return;
//     }
//     Node *temp = *head;
//     while (temp->next != NULL)
//     {
//         temp = temp->next;
//         temp->next = newNode;
//     }
// }
// Node *pos_Node(Node **head, Node *newNode, int index)
// {
//     if (index == 0)
//     {
//         newNode->next = *head;
//         *head = newNode;
//         return;
//     }
//     Node *temp = *head;
//     for (int i = 0; i < index - 1 && temp != NULL; i++)
//     {
//         temp->next;
//         if (temp == NULL)
//             return;
//         newNode->next = temp->next;
//         temp->next = newNode;
//     }
// }
// void printList(Node *head)
// {
//     while (head != NULL)
//     {
//         printf("%.2f", head->value);
//         head = head->next;
//     }
//     printf("\n");
// }
// void freeList(Node *head)
// {
//     Node *temp;
//     while (head != NULL)
//     {
//         temp = head;
//         head = head->next;
//         free(temp);
//     }
// }
// int main()
// {
//     srand(time);
//     Node *head = NULL; // Leere List generieren
//     int *random_num[51];
//     int i = 0;
//     for (i; i < 50; i++)
//     {
//         new_Node(0);
//         *(random_num + i) = rand();
//     }
//     *(random_num + 3) = rand();
//     free(new_Node);
// }
