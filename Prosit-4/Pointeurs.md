# Pointeurs

**Déclaration et Initialisation:**
Pour déclarer un pointeur, on utilise l'opérateur `*` :

```cpp
int *ptr; // ptr est un pointeur sur un entier
```

L'initialisation se fait en attribuant l'adresse d'une variable (avec l'opérateur `&`) au pointeur :

```cpp
int var = 5;
int *ptr = &var; // ptr pointe maintenant vers l'adresse de var
```

**Déréférencement:**
Pour accéder à la valeur de la variable pointée, on utilise l'opérateur de déréférencement `*` :

```cpp
int value = *ptr; // value est maintenant égal à 5
```

**Pointeurs et Tableaux:**
Les pointeurs sont souvent utilisés avec les tableaux car le nom d'un tableau est en fait un pointeur sur son premier élément :

```cpp
int arr[3] = {10, 20, 30};
int *ptr = arr; // équivalent à int *ptr = &arr[0];
```

**Arithmétique des Pointeurs:**
L'arithmétique des pointeurs permet de se déplacer dans un tableau :

```cpp
int value1 = *(ptr + 1); // accède à arr[1]
int value2 = *(ptr + 2); // accède à arr[2]
```

## Pointeurs de Fonction

Un pointeur de fonction est déclaré en indiquant le type de retour de la fonction suivie par un astérisque et le nom du pointeur entre parenthèses, suivi par les paramètres de la fonction entre parenthèses.

**Déclaration:**

```cpp
void (*func_ptr)(int, int); // func_ptr est un pointeur vers une fonction qui prend deux int en paramètre et ne retourne rien
```

**Initialisation:**
Pour initialiser un pointeur de fonction, on lui assigne l'adresse d'une fonction existante :

```cpp
void add(int a, int b) {
    std::cout << (a + b) << std::endl;
}

func_ptr = &add; // Initialisation du pointeur de fonction
```

**Utilisation:**
Pour appeler une fonction via un pointeur de fonction, on utilise l'opérateur de déréférencement suivi par les arguments entre parenthèses :

```cpp
(*func_ptr)(2, 3); // Appelle la fonction add via le pointeur de fonction
```

ou simplement :

```cpp
func_ptr(2, 3); // C++ sait que vous souhaitez appeler la fonction
```

## Bonnes Pratiques

1. **Initialisation des Pointeurs :** Toujours initialiser les pointeurs. Un pointeur non initialisé peut pointer vers un emplacement mémoire aléatoire, causant des bugs difficiles à détecter.

2. **Vérification des Pointeurs :** Avant de déréférencer un pointeur, assurez-vous qu'il ne pointe pas sur `nullptr`.

3. **Gestion de la Mémoire :** Lorsque vous utilisez des pointeurs avec de la mémoire allouée dynamiquement, assurez-vous de libérer cette mémoire avec `delete` pour éviter les fuites de mémoire.

4. **Pointeurs de Fonction :** Ils sont utiles pour implémenter des callbacks et pour la programmation orientée événements. Veillez à ce que la fonction pointée ait la même signature que le pointeur de fonction.

## Exemple Complet

Voici un exemple complet illustrant les pointeurs et pointeurs de fonction :

```cpp
#include <iostream>

void operation(int a, int b, void (*op_func)(int, int)) {
    (*op_func)(a, b); // Utilisation du pointeur de fonction
}

void add(int a, int b) {
    std::cout << "Addition: " << (a + b) << std::endl;
}

void subtract(int a, int b) {
    std::cout << "Subtraction: " << (a - b) << std::endl;
}

int main() {
    int x = 10, y = 5;

    // Pointeur vers une fonction 'add'
    void (*op_ptr)(int,int) = &add;
    operation(x, y, op_ptr);

    // Pointeur vers une fonction 'subtract'
    op_ptr = &subtract;
    operation(x, y, op_ptr);

    return 0;
}
```

## Exercice d'application : Tri de Tableau avec Pointeurs de Fonction


Vous devez écrire un programme en C++ qui triera un tableau d'entiers en utilisant un pointeur de fonction pour la comparaison. L'objectif de cet exercice est de pratiquer l'utilisation des pointeurs de fonction et de comprendre comment ils peuvent être utilisés pour créer des fonctions plus génériques et réutilisables.

**Consignes:**

1. Créez une fonction `sort` qui prend les paramètres suivants :
   - Un tableau d'entiers `arr[]`.
   - La taille du tableau `size`.
   - Un pointeur de fonction `compare` qui prend deux entiers en paramètres et retourne un booléen.

2. La fonction `sort` doit trier le tableau `arr[]` en utilisant la fonction pointée par `compare` pour déterminer l'ordre de tri.

3. Écrivez deux fonctions de comparaison :
   - `ascending(int a, int b)` qui retourne `true` si `a` est inférieur à `b`.
   - `descending(int a, int b)` qui retourne `true` si `a` est supérieur à `b`.

4. Dans la fonction `main`, créez un tableau d'entiers et utilisez la fonction `sort` pour le trier en ordre ascendant et en ordre descendant, en passant respectivement les pointeurs vers `ascending` et `descending`.

5. Affichez le tableau avant et après le tri pour chaque cas pour vérifier que votre fonction `sort` fonctionne correctement.

**Exemple de signature de la fonction `sort`:**

```cpp
void sort(int arr[], int size, bool (*compare)(int, int));
```

**Critères de réussite:**

- Le programme doit compiler sans erreurs ni avertissements.
- Le tableau doit être affiché correctement avant et après le tri.
- Le tri doit fonctionner correctement en ordre ascendant et en ordre descendant.

**Bonus:**

- Gérez les cas d'erreur, par exemple un tableau vide ou un pointeur de fonction `nullptr`.
- Ajoutez une fonctionnalité qui permet à l'utilisateur de choisir le type de tri au lancement du programme.
