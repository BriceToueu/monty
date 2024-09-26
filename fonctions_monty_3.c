/*
 * Fichier: fonctions_monty_3.c
 * Auteur: Brice Toueu
 */

#include "monty.h"

void monty_nop(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);

/**
 * monty_nop - Ne fait absolument rien pour l'opcode Monty 'nop'.
 * @stack: Un pointeur sur le nœud de mode supérieur
 *         d'une liste chaînée stack_t.
 * @line_number: Le numéro de la ligne de travail actuelle
 *               d'un fichier de bytecodes Monty.
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * monty_pchar - Imprime le caractère dans la valeur supérieure
 *               d'une liste chaînée stack_t.
 * @stack: Un pointeur sur le nœud de mode supérieu
 *         d'une liste chaînée stack_t.
 * @line_number: Le numéro de la ligne de travail actuelle
 *               d'un fichier de bytecodes Monty.
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		code_erreur_op_toks(erreur_pchar(line_number, "pile vide"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		code_erreur_op_toks(erreur_pchar(line_number,
					     "valeur hors plage"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * monty_pstr - Imprime la chaîne de caractères contenue
 *              dans une liste chaînée stack_t.
 * @stack: Un pointeur sur le nœud de mode supérieur
 *         d'une liste chaînée stack_t.
 * @line_number: Le numéro de la ligne de travail actuelle
 *               d'un fichier de bytecodes Monty.
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");

	(void)line_number;
}
