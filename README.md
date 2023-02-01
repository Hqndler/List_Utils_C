# List_Utils_C

Quelques fonctions utilitaires pour des listes doublement chainee en C.<br>
Garanti valgrind proof + norme.

## List int

Pour tout ce qui est lie au liste chainee ne contenant que des int.
- get_min() et get_max() comme fonction unique.
- Variante de free_list(), get_index(), print_list() et list_new() pour les int.

## List str
Pour tout ce aui est lie au liste chainee ne contenant que des char *.
- Variante de free_list(), get_index(), print_list() et list_new() pour les char *.

## List gen

Fonctions utilitaire generale utilisant les fonctions pour checker dans la memoire.<br>
Contient aussi toute les fonctions utilisees dans int et str.
- append : pour ajouter a la fin.
- addtop : pour ajouter au debut.
- insert : pour inserer a l'index souhaiter.
- len_list : pour recuperer la longueur de la liste chainee.
