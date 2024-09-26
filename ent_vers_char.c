/*
 * Fichier: ent_vers_char.c
 * Auteur: Brice Toueu
 */

#include <stdlib.h>

char *obt_ent(int num);
unsigned int _abs(int);
int obt_lon_ent_nsi(unsigned int num, unsigned int base);
void remp_nbc_base(unsigned int num, unsigned int base,
		       char *buff, int buff_size);

/**
 * obt_ent - obtient un pointeur de caractère vers une nouvelle
 *           chaîne de caractères contenant int
 * @num: nombre à convertir en chaîne de caractères
 *
 * Return: pointeur de caractères vers la chaîne nouvellement créée.
 *         NULL si malloc échoue.
 */
char *obt_ent(int num)
{
	unsigned int temp;
	int length = 0;
	long num_l = 0;
	char *ret;

	temp = _abs(num);
	length = obt_lon_ent_nsi(temp, 10);

	if (num < 0 || num_l < 0)
		length++; /* signe négatif */
	ret = malloc(length + 1); /* créer une nouvelle chaîne de caractères */
	if (!ret)
		return (NULL);

	remp_nbc_base(temp, 10, ret, length);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * _abs - obtient la valeur absolue d'un entier
 * @i: entier pour obtenir la valeur absolue de
 *
 * Return: entier non signé abs rep de i
 */
unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * obt_lon_ent_nsi - obtient la longueur du tampon nécessaire
 *                   pour un int non signé
 * @num: pour obtenir la longueur nécessaire pour
 * @base: base de la représentation des nombres utilisée par le tampon
 *
 * Return: entier contenant la longueur du tampon nécessaire
 *         (ne contient pas de bt nul)
 */
int obt_lon_ent_nsi(unsigned int num, unsigned int base)
{
	int len = 1; /* tous les nombres contiennent au moins un chiffre */

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * remp_nbc_base - remplit le tampon avec des
 *                 nombres corrects jusqu'à la base 36
 * @num: nombre à convertir en chaîne de caractères dans la base donnée
 * @base: base du nombre utilisé dans la conversion,
 *        ne fonctionne que jusqu'à la base 36
 * @buff: tampon à remplir avec le résultat de la conversion
 * @buff_size: taille du tampon en octets
 *
 * Return: toujours vide.
 */
void remp_nbc_base(unsigned int num, unsigned int base,
			char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9) /* renvoie la représentation ascii des valeurs en min */
			buff[i] = rem + 87; /* 10 sera a, 11 = b, ... */
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}
