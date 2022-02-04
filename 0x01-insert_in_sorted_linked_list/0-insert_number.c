#include "lists.h"
#include <stdlib.h>
/**
 *insert_node - a function in C that inserts a number into a sorted singly linked list.
 *@head: pointer to the head
 *@number: new node value
 *Return: new node adress or null
 */
listint_t *insert_node(listint_t **head, int number)
{
listint_t *new_node, *temp;
if (head == NULL)
return (NULL);
temp = *head;
new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);
new_node->n = number;
new_node->next = NULL;
if (*head == NULL)
{
*head = new_node;
return (*head);
}
if (temp->n > number)
{
new_node->next = *head;
*head = new_node;
return (*head);
}
while (temp != NULL)
{
if (temp->n < number && temp->next == NULL)
{
temp->next = new_node;
return (temp);
}
if (temp->n == number)
{
new_node->next = temp->next;
temp->next = new_node;
return (temp);
}
if (temp->n < number && temp->next->n > number)
{
new_node->next = (temp)->next;
temp->next = new_node;
return (temp);
}
temp = temp->next;
}
return (temp);
}