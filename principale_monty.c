/*
 * Fichier: principale_monty.c
 * Auteur: Brice Toueu
 */

#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_toks = NULL;

/**
 * main - le point d'entrée de Monty Interp
 *
 * @argc: le nombre d'arguments passés au programme
 * @argv: pointeur sur un tableau de pointeurs sur les arguments
 *
 * Return: (EXIT_SUCCESS) sur la réussite (EXIT_FAILURE) en cas d'erreur
 */
int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (erreur_utilisation());
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (erreur_ouv_f(argv[1]));
	exit_code = run_monty(script_fd);
	fclose(script_fd);
	return (exit_code);
}
