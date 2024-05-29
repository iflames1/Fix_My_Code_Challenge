#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current;
    unsigned int p;

    if (head == NULL || *head == NULL)
        return (-1);

    current = *head;

    /* Traverse to the node at the specified index */
    for (p = 0; current != NULL && p < index; p++)
        current = current->next;

    /* If the index is out of range */
    if (current == NULL)
        return (-1);

    /* If the node to be deleted is the head node */
    if (current == *head)
    {
        *head = current->next;
        if (*head != NULL)
            (*head)->prev = NULL;
    }
    else
    {
        /* Update the next pointer of the previous node */
        if (current->prev != NULL)
            current->prev->next = current->next;

        /* Update the prev pointer of the next node */
        if (current->next != NULL)
            current->next->prev = current->prev;
    }

    /* Free the memory allocated for the current node */
    free(current);

    return (1);
}
