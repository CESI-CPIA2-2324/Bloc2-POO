# Workshop 4

## Exercice 1

- Créez un tableau de 3 entiers, remplissez-le, affichez le contenu.

- Réalisez un schéma pour représenter la mémoire vis-à-vis du code source que vous avez créé.

- Comment le compilateur interprète-t-il tab[2] = 30 ?

- Proposez des explications sur la notion d’offset et d’arithmétique. Dans quel cas est-il utile d’utiliser ce genre de tableau ?

- Créez un tableau dynamique de 3 entiers, remplissez-le, affichez le contenu

- Réalisez un schéma pour représenter la mémoire vis-à-vis du code source que vous avez créé.  

- Comment le compilateur interprète-t-il tab[2] = 30 ?

- Dans quel cas est-il utile d’utiliser ce genre de tableau ?

- Un tableau réserve un emplacement contigu en mémoire au moment de la compilation, il est donc facilement utilisable avec une boucle for et son arithmétique, puisque les blocs mémoires sont contigus. Un tableau dynamique réserve aussi un emplacement contigu en mémoire au moment de l’exécution, il est donc facilement utilisable avec une boucle for et son arithmétique, puisque les blocs mémoires sont contigus. Comment gérer avec une boucle des emplacements discontinus en mémoire ? Codez et utilisez un programme qui répond à cette problématique.  

## Exercice 2

- Réutilisez les classes Objet2D, Cube, Rectangle du Workshop précédent.

- Modifiez la classe Objet2D en ajoutant un membre privé Suivant qui est un pointeur vers Objet2D, ajoutez également les accesseurs pour ce membre.

- Créez une classe listeObjets2D de stockage d’Objet2D comme une liste chainée unidirectionnelle avec Head et Tail étant des pointeurs vers la tête et la queue de la chaine et sans information sur la taille. Cette classe de stockage va gérer un nombre indéterminé d’objets de type Rectangle et/ou de type Cube. La classe de stockage doit disposer d’une méthode ajouter (AtHead, AtTail, AtIndex), ainsi les méthodes correspondantes pour supprimer un élément. Modifier la méthode afficherInfos() qui appellera la méthode afficheInfo() de tous les objets stockés à l’aide d’une boucle while.

- Créez des objets dans le main, ajoutez-les à la classe de stockage et appelez les méthodes des objets stockés, sans demander la taille mais plutôt une condition d’arrêt.

- Réfléchissez à la gestion de la mémoire. Comment libérer de la mémoire dans leurs programmes ? Qu’advient-il des objets internes de la classe de stockage ? Faites des schémas pour expliquer. Construisez un destructeur qui préviendra des fuites de mémoires. Que va faire le destructeur si la classe de stockage utilise les références des objets ? Si un destructeur de la classe de stockage est utilisé, est-il alors nécessaire de supprimer les objets stockés un à un dans le main ?

## Exercice 3

Une classe A souhaite envoyer des messages personnalisés aux différentes instances d’une classe B. Par soucis d’économie de mémoire, elle ne peut pas manipuler directement les différentes instances, de toutes façon, elle ne peut pas savoir combien il y en aura. La classe A connait la signature de la méthode à appeler de la classe B, mais la classe B comporte plusieurs méthodes avec la même signature. La classe A ne peut pas connaitre à l’avance la méthode à appeler. Codez la solution que vous proposez pour résoudre cette problématique.  
