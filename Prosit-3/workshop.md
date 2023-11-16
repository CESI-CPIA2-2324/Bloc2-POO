# Workshop 3 - Polymorphisme et Héritage

---

## Exercice 1

- Prenez en main le diagramme de classes disponible à l'adresse suivante : <https://moodle.cesi.fr/pluginfile.php/29936/mod_resource/content/8/res/WS3IMG1.jpg>

- Faites attention aux éléments suivants :
  - Membres protégés
  - Méthodes virtuelles
- Votre objectif :
  - Programmez les fichiers d’en-tête (.h) et les fichiers source (.cpp) pour les trois classes indiquées.
  - Élaborez le fichier principal (main.cpp) qui :
    - Initialise un pointeur `Objet2D`.
    - Crée un objet (`Rectangle` ou `Carré`) selon le choix entré par l’utilisateur.

---

## Exercice 2

- Continuez à partir de l'exercice 1.
- Créez une classe `StockageObjet2D` pour gérer une collection d'objets de types `Rectangle` ou `Cube`.
- Votre classe de stockage devra :
  - Déterminer le nombre d’objets à gérer lors de l'instanciation.
  - Avoir une méthode `ajouter` pour intégrer des objets sans gestion d'index.
  - Avoir une méthode surchargée `ajouter` pour placer des objets à un index spécifique.
  - Avoir une méthode `afficherInfos()` qui appelle `afficheInfo()` pour chaque objet stocké.
- Dans le `main.cpp` :
  - Créez des instances d'objets.
  - Ajoutez-les à la classe de stockage.
  - Utilisez les méthodes des objets ajoutés.
- Pensez à la gestion de la mémoire :
  - Comment libérer de la mémoire efficacement ?
  - Comment gérer les objets internes de la classe de stockage ?
  - Concevez un destructeur pour éviter les fuites de mémoire.

---

## Exercice 3

- Concevez un scénario où l’utilisation de deux classes est nécessaire :
  - La classe `B` doit être une spécialisation de la classe `A`.
  - Les deux classes doivent contenir une méthode `void m(void)`.
- Dans le `main.cpp` :
  - Allouez de la mémoire pour les deux types d'objets.
  - Expérimentez avec les méthodes définies.
  - Transformez un objet de type `A` en type `B`.
  - Appliquez la méthode `m(void)` sur l’objet transformé.

---

## Exercices supplémentaires

Si vous avez terminé, consultez la corbeille d'exercice à l'adresse suivante : <https://moodle.cesi.fr/pluginfile.php/29939/mod_resource/content/6/co/_3_Corbeille_-_A_points.html>
