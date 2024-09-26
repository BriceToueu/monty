/*
 * Fichier: fonctions_monty_2.c
 * Auteur: Brice Toueu
 */

#include "monty.h"

void monty_add(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);

/**
 * monty_add - Ajoute les deux premières valeurs d'un
 *             liste chaînée stack_t.
 * @stack: Un pointeur sur le nœud de mode supérieur
 *         d'une liste chaînée stack_t.
 * @line_number: Le numéro de la ligne de travail actuelle
 *               d'un fichier de bytecodes Monty.
 *
 * Description: Le résultat est stocké dans le deuxième nœud de valeur
 *              à partir du sommet et la valeur du sommet est supprimée.
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		code_erreur_op_toks(erreur_pile_courte(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_sub - Soustrait la deuxième valeur de la partie supérieure de
 *             une liste chaînée stack_t par la valeur supérr
 * @stack: Un pointeur sur le nœud de mode supérieu
 *         d'une liste chaînée stack_t.
 * @line_number: Le numéro de la ligne de travail actuelle
 *               d'un fichier de bytecodes Monty.
 *
 * Description: Le résultat est stocké dans le deuxième nœud de valeur
 *              à partir du sommet et la valeur du sommet est supprimée.
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		code_erreur_op_toks(erreur_pile_courte(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_div - Divise la deuxième valeur à partir du haut de
 *             une liste chaînée stack_t par la valeur supérieure.
 * @stack: Un pointeur sur le nœud de mode supérieur
 *         d'une liste chaînée stack_t.
 * @line_number: Le numéro de la ligne de travail actuelle
 *               d'un fichier de bytecodes Monty.
 *
 * Description: Le résultat est stocké dans le deuxième nœud de valeur
 *              à partir du sommet et la valeur du sommet est supprimée.
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		code_erreur_op_toks(erreur_pile_courte(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		code_erreur_op_toks(erreur_div(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mul - Multiplie la deuxième valeur à partir du haut de la page
 *             une liste chaînée stack_t par la valeur supérieure.
 * @stack: Un pointeur sur le nœud de mode supérieur
 *         d'une liste chaînée stack_t.
 * @line_number: Le numéro de la ligne de travail actuelle
 *               d'un fichier de bytecodes Monty.
 *
 * Description: Le résultat est stocké dans le deuxième nœud de valeur
 *              à partir du sommet et la valeur du sommet est supprimée.
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		code_erreur_op_toks(erreur_pile_courte(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mod - Calcule le module de la deuxième valeur de l'élément
 *             sommet d'une liste chaînée stack_t par la valeur du sommet.
 * @stack: Un pointeur sur le nœud de mode supérieur
 *         d'une liste chaînée stack_t.
 * @line_number: Le numéro de la ligne de travail actuelle
 *               d'un fichier de bytecodes Monty.
 *
 * Description: Le résultat est stocké dans le deuxième nœud de valeur
 *              à partir du sommet et la valeur du sommet est supprimée.
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		code_erreur_op_toks(erreur_pile_courte(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		code_erreur_op_toks(erreur_div(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	monty_pop(stack, line_number);
}
