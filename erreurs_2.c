/*
 * Fichier: erreurs_2.c
 * Auteur: Brice Toueu
 */

#include "monty.h"

int erreur_pop(unsigned int line_number);
int erreur_pint(unsigned int line_number);
int erreur_pile_courte(unsigned int line_number, char *op);
int erreur_div(unsigned int line_number);
int erreur_pchar(unsigned int line_number, char *message);

/**
 * erreur_pop - Imprime des messages d'erreur pop pour les piles vides.
 * @line_number: Numéro de ligne dans le script où l'erreur s'est produite.
 *
 * Return: (EXIT_FAILURE) toujours.
 */
int erreur_pop(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * erreur_pint - Imprime des messages d'erreur pour les piles vides.
 * @line_number: Numéro de ligne dans le fichier de bytecodes
 *               Monty où l'erreur s'est produite.
 *
 * Return: (EXIT_FAILURE) toujours.
 */
int erreur_pint(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * erreur_pile_courte - Imprime les messages d'erreur de la fonction monty math
 *              pour les piles ou les files d'attente inférieure a
 *              deux noeuds.
 * @line_number: Numéro de ligne dans le fichier de bytecodes Mo
 *               où l'erreur s'est produite.
 * @op: Opération au cours de laquelle l'erreur s'est produite.
 *
 * Return: (EXIT_FAILURE) toujours.
 */
int erreur_pile_courte(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * erreur_div - Imprime les messages d'erreur de division pour
 *              la division par 0.
 * @line_number: Numéro de ligne dans le fichier de bytecodes
 *              Monty où l'erreur s'est produite.
 *
 * Return: (EXIT_FAILURE) toujours.
 */
int erreur_div(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * erreur_pchar - Imprime les messages d'erreur pchar pour les piles vides
 *                piles vides et valeurs autres que des caractères.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 * @message: Le message d'erreur correspondant à imprimer.
 *
 * Return: (EXIT_FAILURE) toujours.
 */
int erreur_pchar(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
