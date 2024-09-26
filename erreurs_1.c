/*
 * Fichier: erreurs_1.c
 * Auteur: Brice Toueu
 */

#include "monty.h"

int erreur_utilisation(void);
int erreur_malloc(void);
int erreur_ouv_f(char *filename);
int erreur_ins_in(char *opcode, unsigned int line_number);
int erreur_arg_nv(unsigned int line_number);

/**
 * erreur_utilisation - Imprime les messages d'erreur d'utilisation.
 *
 * Return: (EXIT_FAILURE) toujours.
 */
int erreur_utilisation(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * erreur_malloc - Imprime les messages d'erreur de malloc.
 *
 * Return: (EXIT_FAILURE) toujours.
 */
int erreur_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * erreur_ouv_f - Imprime les messages d'erreur d'ouverture
 * de fichier avec le nom du fichier.
 * @filename: Nom du fichier dont l'ouverture a échoué
 *
 * Return: (EXIT_FAILURE) toujours.
 */
int erreur_ouv_f(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * erreur_ins_in - Imprime les messages d'erreur des instructions inconnues.
 * @opcode: Opcode où l'erreur s'est produite.
 * @line_number: Numéro de ligne dans le fichier de bytecodes Monty
 * où l'erreur s'est produite.
 *
 * Return: (EXIT_FAILURE) toujours.
 */
int erreur_ins_in(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * erreur_arg_nv - Imprime les messages d'erreur relatifs
 * aux arguments monty_push non valides.
 * @line_number: Numéro de ligne dans le fichier de bytecodes Monty
 * où l'erreur s'est produite.
 *
 * Return: (EXIT_FAILURE) toujours.
 */
int erreur_arg_nv(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
