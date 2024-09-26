/*
 * Fichier: fonctions_monty_1.c
 * Auteur: Brice Toueu
 */

#include "monty.h"

void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);

/**
 * monty_push - Insère une valeur dans une liste chaînée stack_t.
 * @stack: Un pointeur sur le nœud de mode supérieur
 *         d'une liste chaînée stack_t.
 * @line_number: Le numéro de la ligne de travail actuelle
 *               d'un fichier de bytecodes Monty.
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		code_erreur_op_toks(erreur_malloc());
		return;
	}

	if (op_toks[1] == NULL)
	{
		code_erreur_op_toks(erreur_arg_nv(line_number));
		return;
	}

	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			code_erreur_op_toks(erreur_arg_nv(line_number));
			return;
		}
	}
	new->n = atoi(op_toks[1]);

	if (check_mode(*stack) == STACK) /* Insertion en mode STACK à l'avant */
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else /* Mode QUEUE insérer à la fin */
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}

/**
 * monty_pall - Imprime les valeurs d'une liste chaînée stack_t.
 * @stack: Un pointeur sur le nœud de mode supérieur
 *         d'une liste chaînée stack_t.
 * @line_number: Le numéro de la ligne de travail actuelle
 *               d'un fichier de bytecodes Monty.
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}

/**
 * monty_pint - Imprime la valeur supérieure d'une liste chaînée stack_t.
 * @stack: Un pointeur sur le nœud de mode supérieur
 *         d'une liste chaînée stack_t.
 * @line_number: Le numéro de la ligne de travail actuelle
 *               d'un fichier de bytecodes Monty.
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		code_erreur_op_toks(erreur_pint(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}


/**
 * monty_pop - Supprime l'élément de valeur supérieure
 *             d'une liste chaînée stack_t.
 * @stack: Un pointeur sur le nœud de mode supérieur
 *         d'une liste chaînée stack_t.
 * @line_number: Le numéro de la ligne de travail actuelle
 *               d'un fichier de bytecodes Monty.
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		code_erreur_op_toks(erreur_pop(line_number));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * monty_swap - Échange les deux premiers éléments
 *              d'une liste chaînée stack_t.
 * @stack: Un pointeur sur le nœud de mode supérieur
 *         d'une liste chaînée stack_t.
 * @line_number: Le numéro de la ligne de travail actuelle
 *               d'un fichier de bytecodes Monty.
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		code_erreur_op_toks(erreur_pile_courte(line_number, "swap"));
		return;
	}

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
