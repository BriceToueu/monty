/*
 * Fichier: code_erreur_op_toks.c
 * Auteur: Brice Toueu
 */

#include "monty.h"

/**
 * code_erreur_op_toks - Définit le dernier élément de op_toks
 *                       comme étant un code d'erreur.
 * @error_code: Entier à stocker sous forme de chaîne dans op_toks.
 */
void code_erreur_op_toks(int error_code)
{
	int toks_len = 0, i = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;

	toks_len = token_arr_len();
	new_toks = malloc(sizeof(char *) * (toks_len + 2));
	if (!op_toks)
	{
		erreur_malloc();
		return;
	}
	while (i < toks_len)
	{
		new_toks[i] = op_toks[i];
		i++;
	}
	exit_str = obt_ent(error_code);
	if (!exit_str)
	{
		free(new_toks);
		erreur_malloc();
		return;
	}
	new_toks[i++] = exit_str;
	new_toks[i] = NULL;
	free(op_toks);
	op_toks = new_toks;
}
