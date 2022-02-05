#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
* is_palindrome - checks if a singly linked list is a palindrome.
* @head: head
* Return: 0 if it is not a palindrome, 1 if it is a palindrome
*/
int is_palindrome(listint_t **head)
{
	listint_t *c, *k;

	if (*head == NULL || (*head)->next == NULL)
	return (1);

	k = *head;
	while (k->next)
	{
		k = k->next;
	}
	c = *head;
	while (k >= c)
	{
		if (c->n == k->n)
		{
			c = c->next;
			k -= 2;
		}
		else
			return (0);
	}
	return (1);
}
