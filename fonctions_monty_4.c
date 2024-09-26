/*
 * Fichier: fonctions_monty_4.c
 * Auteur: Brice Toueu
 */

#include "monty.h"

void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);

/**
 * monty_rotl - Fait pivoter la valeur supérieure d'une liste chaînée
 *              stack_t vers la valeur inférieure.
 * @stack: Un pointeur sur le nœud de mode supérieur
 *         d'une liste chaînée stack_t.
 * @line_number: Le numéro de la ligne de travail actuelle
 *               d'un fichier de bytecodes Monty.
 */
void monty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_number;
}

/**
 * monty_rotr - Fait pivoter la valeur inférieure d'une liste chaînée
 *              stack_t vers le haut.
 * @stack: Un pointeur sur le nœud de mode supérieur
 *         d'une liste chaînée stack_t.
 * @line_number: Le numéro de la ligne de travail actuelle
 *               d'un fichier de bytecodes Monty.
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_number;
}

/**
 * monty_stack - Convertit une file d'attente en une pile.
 * @stack: Un pointeur sur le nœud de mode supérieur
 *         d'une liste chaînée stack_t.
 * @line_number: Le numéro de la ligne de travail actuelle
 *               d'un fichier de bytecodes Monty.
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * monty_queue - Convertit une pile en une file d'attente.
 * @stack: Un pointeur sur le nœud de mode supérieur
 *         d'une liste chaînée stack_t.
 * @line_number: Le numéro de la ligne de travail actuelle
 *               d'un fichier de bytecodes Monty.
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
