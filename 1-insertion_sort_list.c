#include "sort.h"

/**
 * swapnode - Swap two nodes in listint_t doubly linked list
 * @head: pointer to the head of the doubly linked list
 * @i: pointer to the first node to swap
 * @j: second node to swap
 */
void swapnode(listint_t **head, listint_t **i, listint_t *j)
{
	(*i)->next = j->next;
	if (j->next != NULL)
		j->next->prev = *i;
	j->prev = (*i)->prev;
	j->next = *i;
	if ((*i)->prev != NULL)
		(*i)->prev->next = j;
	else
		*head = j;
	(*i)->prev = j;
	*i = j->prev;
}

/**
 * insertion_sort_list - sorts doubly linked list of ints
 * 			in ascending order
 * @list: A pointer to the head of a doubly-linked list of integers.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *insrt;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (node = (*list)->next; node != NULL; node = node->next)
	{
		insrt = node->prev;
		while (insrt != NULL && node->n < insrt->n)
		{
			swapnode(list, &insrt, node);
			print_list((const listint_t *)*list);
			insrt = node->prev;
		}
	}
}
