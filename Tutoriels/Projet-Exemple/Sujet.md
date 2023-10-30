# Système de Gestion de Commandes de Pizzeria

## Objectif

Ce projet a pour but d'introduire les étudiants aux concepts fondamentaux du C++ tels que les classes, l'héritage, la surcharge de méthodes, la gestion de la mémoire, et les conteneurs de la bibliothèque standard. Le système permettra de gérer les commandes dans une pizzeria en permettant aux clients de choisir parmi différents types de pizzas et d'ajouter des garnitures supplémentaires.

Vous pouvez utiliser le fichier squelette `main.cpp` fourni dans ce répertoire pour commencer. Vous pouvez également créer votre propre fichier `main.cpp` et l'utiliser pour tester votre code.

## Description

Dans ce système, les utilisateurs peuvent créer des commandes de pizza, ajouter des garnitures, et voir le résumé de leur commande ainsi que le coût total. Les pizzas seront de trois types - Petite, Moyenne et Grande, avec des prix de base différents. Les garnitures auront également des coûts associés.

### Étape 1: Préparation de l'Environnement de Développement

- Installez et configurez un IDE (comme Visual Studio ou CLion) pour le développement en C++.
- Familiarisez-vous avec l'interface de l'IDE et assurez-vous que vous pouvez compiler et exécuter un programme C++ simple.

### Étape 2: Conception des Classes de Base

- Créez une classe `Pizza` qui contiendra des informations de base comme le nom, le diamètre et le prix de base.
- Créez une classe `Garniture` qui contiendra des informations sur une garniture comme son nom et son coût.
- Définissez les méthodes d'accès (getters) et de modification (setters) appropriées pour ces classes.

### Étape 3: Implémentation de l'Héritage

- Créez des classes dérivées de `Pizza` comme `PetitePizza`, `MoyennePizza` et `GrandePizza` pour représenter différents types de pizzas.
- Ces classes dérivées peuvent avoir des valeurs par défaut différentes pour le diamètre et le prix de base.

### Étape 4: Surcharge des Méthodes

- Surchargez des méthodes dans la classe `Pizza` pour calculer le coût total de la pizza en fonction des garnitures ajoutées.

### Étape 5: Utilisation des Conteneurs

- Utilisez des conteneurs de la bibliothèque standard C++, comme `std::vector`, pour stocker une liste de garnitures dans la classe `Pizza` et une liste de pizzas dans une nouvelle classe `Commande`.
  
### Étape 6: Gestion de la Mémoire

- Si nécessaire, utilisez des pointeurs intelligents pour gérer la mémoire efficacement et éviter les fuites de mémoire.

### Étape 7: Création de l'Interface Utilisateur

- Créez une interface utilisateur simple en console qui permettra aux utilisateurs de créer des commandes, d'ajouter des pizzas, d'ajouter des garnitures à des pizzas, et de voir le résumé et le coût total de leur commande.

### Étape 8: Test et Débogage

- Testez votre système en profondeur pour identifier et corriger les bugs.
- Assurez-vous que toutes les fonctionnalités fonctionnent comme prévu et que l'interface utilisateur est intuitive et conviviale.

### Étape 9: Documentation

- Documentez votre code en utilisant des commentaires appropriés pour expliquer la logique de votre programme.
- Vous pouvez également créer une documentation externe pour expliquer comment utiliser votre système.

### Étape 10: Révision et Amélioration

- Revoyez votre code pour identifier les domaines qui peuvent être améliorés ou optimisés.
- Obtenez des retours d'autres personnes et apportez des améliorations en conséquence.


## Ressources

- Compiler/IDE pour le C++ (comme Visual Studio, CLion, etc.)
- Documentation C++ pour référence.



