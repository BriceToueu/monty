# :snake: Interpreteur Monty

Bienvenue sur le site de l'interpréteur Monty Bytecode. Cet interpréteur a été construit en langage C et est compatible avec `ISO90`, `ISO99`, et `ISO11`. Il lit les fichiers de bytecode Monty de n'importe quelle extension (de préférence `.m` bien que cela n'ait pas d'importance), et interprète les opcodes qu'ils contiennent.

Notre interprète peut être exécuté comme une pile (LIFO) ou une file d'attente (FIFO). Le mode peut être changé en cours de script. L'interpréteur peut gérer une variété d'opcodes Monty, y compris l'impression, les opérations mathématiques, et plus encore - tous les opcodes gérés sont listés ci-dessous.

## :running: Démarrer

* [Ubuntu 14.04 LTS](http://releases.ubuntu.com/14.04/) - Système d'exploitation requis.

* [GCC 4.8.4](https://gcc.gnu.org/gcc-4.8/) - Compilateur utilisé


## :warning: Prérequis

* Il faut que `git` soit installé.

* Le dépôt doit avoir été cloné.

```
$ sudo apt-get install git
```


## :arrow_down: Installation et utilisation

Cloner le dépôt dans un nouveau répertoire :

```
$ git clone https://github.com/BriceToueu/monty.git
```
Compiler avec les éléments suivants :

```
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

Exécuter l'interpréteur sur un fichier :

```
./monty file.m
```


## :wrench: Opcodes Monty

* **push**
  * Usage: `push <int>`
  * Insère un élément dans la pile.
  * Le paramètre `<int>` doit être un entier.

* **pall**
  * Imprime toutes les valeurs de la pile/queue, en commençant par le sommet.

* **pint**
  * Imprime la valeur supérieure de la pile ou de la file d'attente.

* **pop**
  * Supprime l'élément supérieur de la pile ou de la file d'attente.

* **swap**
  * Intervertit les deux premiers éléments de la pile ou de la file d'attente.

* **nop**
  * Ne fait rien.

* **add**
  * Ajoute les deux premiers éléments de la pile ou file d'attente.
  * Le résultat est stocké dans le deuxième élément en partant du haut et l'élément supérieur est supprimé.

* **sub**
  * Soustrait l'élément supérieur de la pile ou de la file d'attente du deuxième élément en partant du haut.
  * Le résultat est stocké dans le deuxième élément en partant du haut et l'élément supérieur est supprimé.

* **mul**
  * Multiplie les deux premiers éléments de la pile ou file d'attente.
  * Le résultat est stocké dans le deuxième élément en partant du haut et l'élément supérieur est supprimé.

* **div**
  * Divise le deuxième élément du haut de la pile ou file d'attente par l'élément du haut.
  * Le résultat est stocké dans le deuxième élément en partant du haut et l'élément supérieur est supprimé.

* **mod**
  * Calcule le module du deuxième élément à partir du sommet de la pile ou file d'attente divisé par l'élément supérieur.
  * Le résultat est stocké dans le deuxième élément en partant du haut et l'élément supérieur est supprimé.

* **pchar**
  * Imprime la valeur du caractère de l'élément supérieur de la pile ou file d'attente.
  * Le nombre entier en haut de la page est traité comme une valeur ASCII.

* **pstr**
  * Imprime la chaîne de caractères contenue dans la pile ou la file d'attente.
  * Imprime les caractères élément par élément jusqu'à ce que la pile ou la file d'attente soit vide, qu'une valeur soit `0`, ou qu'une erreur se produise.

* **rotl**
  * Fait pivoter l'élément supérieur de la pile ou de la file d'attente vers le bas.

* **rotr**
  * Fait pivoter l'élément le plus bas de la pile ou de la file d'attente vers le haut.

* **stack**
  * Fait passer une file d'attente en mode pile.

* **queue**
  * Fait passer une pile en mode file d'attente.

:arrow_forward : Les opcodes précédés d'un `#` sont traités comme des commentaires et la ligne correspondante est ignorée.

:arrow_forward : Les lignes peuvent être vides et peuvent contenir n'importe quel nombre d'espaces avant ou après un opcode et son argument (seul le premier opcode et/ou argument est pris en compte).


## :clipboard: Exemples

Remarque, l'interprète Monty fonctionne dans le mode par défaut, le mode PILE. Cela signifie qu'il utilise une pile. Pour passer au mode file d'attente, voir les exemples ci-dessous.

Introduire des valeurs dans la pile et les imprimer toutes, ou le sommet de la pile/le début de la file d'attente.

```
$ cat push_pall_pint.m
push 1
push 2
push 3
pall
pint
$ ./monty push_pall_pint.m
3
2
1
3
```

Utiliser des opérations mathématiques pour additionner, multiplier, diviser, etc. Prend la seconde du sommet et effectue l'opération sur le sommet : `second_from_top / top`, `second_from_top - top`, `etc`. Il l'affecte ensuite au `second_from_top` et retire l'élément supérieur de la pile.

```
$ cat math.m
push 3
push 2
push 1
pall
mul
pall
$ ./monty math.m
1
2
3
1
6
```

L'entrée en mode file d'attente permet d'effectuer toutes les opérations en mode FIFO (file d'attente) au lieu du mode LIFO (pile) par défaut. Remarque : ne modifie pas la pile actuelle, mais place le début de la file d'attente au sommet de la pile.

```
$ cat queue.m
queue
push 1
push 2
push 3
pall
stack
push 4
push 5
push 6
pall
$ ./monty queue.m
1
2
3
6
5
4
1
2
3
```

## :books: Tests de style de codage

Le guide de style `Betty` a été strictement respecté. Pour installer

```
$ git clone https://github.com/holbertonschool/Betty.git

$ cd Betty; ./install.sh
```


## :pencil: Version

* 0.1.0


## :blue_book: Auteur

* **Guy-Brice Nunkahon Toueu** - [@BriceToueu](https://github.com/BriceToueu)


## :mega: Remerciements

* ALX Software engeniering Program (providing guidance)
* Stack Overflow (help on various memory errors (not leaks))

<p align="center">
  <img src="https://www.alxafrica.com/wp-content/uploads/2023/12/logo-black.svg">
</p>
