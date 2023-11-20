# Prosit 4 - Workshop

## Exercice 1

Créez un tableau statique de trois entiers, remplissez-le et affichez son contenu. Ensuite, réfléchissez à comment la mémoire est organisée par rapport à ce tableau et comment le compilateur gère l'instruction tab[2] = 30. Pensez à l'utilité d'un tel tableau lorsque la taille est fixe et la mémoire allouée lors de la compilation.

Ensuite, travaillez avec un tableau dynamique de trois entiers. Remplissez-le et affichez-le aussi. Pensez à la gestion de la mémoire et à l'interprétation de tab[2] = 30 par le compilateur dans ce contexte. Réfléchissez aux avantages de l'allocation dynamique, notamment quand la taille du tableau n'est pas connue à l'avance.

Pour finir, envisagez comment gérer des emplacements mémoire discontinus avec une boucle. Développez et utilisez un programme qui résout ce problème.

## Exercice 2

Utilisez les classes Objet2D, Cube, et Rectangle pour créer une liste chaînée unidirectionnelle sans information sur sa taille. Ajoutez un membre privé Suivant à la classe Objet2D et les accesseurs nécessaires. Votre liste chaînée doit pouvoir gérer un nombre indéterminé d'objets Rectangle et Cube. Implémentez des méthodes pour ajouter et supprimer des objets de cette liste et une méthode afficherInfos() pour afficher les informations de tous les objets.

Créez des objets et ajoutez-les à votre liste dans la fonction principale (main). Utilisez les méthodes sans spécifier la taille de la liste, mais plutôt en utilisant une condition d'arrêt. Pensez également à la gestion de la mémoire et à la manière de libérer la mémoire allouée par votre programme.

## Exercice 3

Imaginez une situation où une classe A doit envoyer des messages personnalisés à différentes instances d'une classe B, sans pouvoir manipuler directement ces instances ni connaître leur nombre. La classe A connaît la signature de la méthode à appeler de la classe B, mais il y a plusieurs méthodes avec la même signature et A ne sait pas à l'avance laquelle appeler. Concevez un code qui permet de résoudre ce scénario.