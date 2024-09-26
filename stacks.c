/*
 * Fichier: stacks.c
 * Auteur: Brice Toueu
 */

#include "monty.h"
#include <string.h>

void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);

/**
 * free_stack - Libère une pile stack_t.
 * @stack: Un pointeur vers le sommet (pile) ou
 *         bas (file d'attente) d'une pile_t.
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * init_stack - Initialise une pile stack_t avec un début
 *              et les nœuds de la file d'attente finale.
 * @stack: Un pointeur sur une pile unitialisée (stack_t).
 *
 * Return: En cas d'erreur - EXIT_FAILURE.
 *         Dans le cas contraire - EXIT_SUCCESS.
 */
int init_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (erreur_malloc());

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * check_mode - Vérifie si une liste chaînée stack_t est en mode
 *              pile ou en mode file d'attente.
 * @stack: Un pointeur vers le haut (pile) ou le bas (file d'attente)
 *         d'une liste chaînée stack_t.
 *
 * Return: Si le stack_t est en mode pile - STACK (0).
 *         Si le stack_t est en mode file d'attente - QUEUE (1).
 *         Dans le cas contraire - 2.
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
