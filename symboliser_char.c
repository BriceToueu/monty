/*
 * Fichier: symboliser_char.c
 * Auteur: Brice Toueu
 */

#include <stdlib.h>

char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int obt_lon_mot(char *str, char *delims);
int obt_nb_mot(char *str, char *delims);
char *obt_mot_suiv(char *str, char *delims);

/**
 * strtow - prend une chaîne et sépare ses mots
 *
 * @str: chaîne de caractères à séparer en mots
 * @delims: les délimiteurs à utiliser pour délimiter les mots
 *
 * Return: Tableau 2D de pointeurs sur chaque mot
 */

char **strtow(char *str, char *delims)
{
	char **words = NULL;
	int wc, wordLen, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = obt_nb_mot(str, delims);


	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (i < wc)
	{
		wordLen = obt_lon_mot(str, delims);
		if (is_delim(*str, delims))
		{
			str = obt_mot_suiv(str, delims);
		}
		words[i] = malloc((wordLen + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordLen)
		{
			words[i][n] = *(str + n);
			n++;
		}
		words[i][n] = '\0'; /* mettre fin à la chaîne de caractères */
		str = obt_mot_suiv(str, delims);
		i++;
	}
	words[i] = NULL; /* le dernier élément est nul pour l'itération */
	return (words);
}

/**
 * is_delim - vérifie si le flux a un délimiteur char
 *
 * @ch: caractère dans le flux
 *
 * @delims: Pointeur vers un tableau de délimiteurs à terminaison nulle
 *
 * Return: 1 (succès) 0 (échec)
 */

int is_delim(char ch, char *delims)
{
	int i = 0;

	while (delims[i])
	{
		if (delims[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

/**
 * obt_lon_mot - obtient la longueur du mot cur dans str
 *
 * @str: chaîne de caractères pour obtenir la longueur du mot actuel
 * @delims: les délimiteurs à utiliser pour délimiter les mots
 *
 * Return: longueur du mot actuel
 */

int obt_lon_mot(char *str, char *delims)
{
	int wLen = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			wLen++;
		}
		if (wLen > 0 && is_delim(str[i], delims))
			break;
		i++;
	}
	return (wLen);
}

/**
 * obt_nb_mot - obtient le nombre de mots d'une chaîne de caractères
 *
 * @str: chaîne de caractères pour obtenir le nombre de mots
 * @delims: les délimiteurs à utiliser pour délimiter les mots
 *
 * Return: le nombre de mots de la chaîne
 */

int obt_nb_mot(char *str, char *delims)
{
	int wc = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wc++;
		}
		i++;
	}
	return (wc);
}

/**
 * obt_mot_suiv - obtient le mot suivant dans une chaîne de caractères
 *
 * @str: chaîne de caractères à partir de laquelle le mot suivant est obtenu
 * @delims: les délimiteurs à utiliser pour délimiter les mots
 *
 * Return: pointeur sur le premier caractère du mot suivant
 */

char *obt_mot_suiv(char *str, char *delims)
{
	int pending = 0;
	int i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
			break;
		i++;
	}
	return (str + i);
}
