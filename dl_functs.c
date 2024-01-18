#include "monty.h"

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list
 *
 * @head: pointer to the head of the double linked list
 * @n: int to be stored in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);

	new_node->prev = NULL;
	new_node->n = n;
	new_node->next = *head;

	if (*head != NULL)
		(*head)->prev = new_node;

	(*head) = new_node;

	return (*head);
}

/**
 * free_dlistint - frees a dlistint_t list
 *
 * @head: header of the double linked list
 *
 * Return: void
 */
void free_dlistint(stack_t *head)
{
	stack_t *temp = head;

	while (temp != NULL)
	{
		temp = temp->next;
		free(head);
		head = temp;
	}
}
