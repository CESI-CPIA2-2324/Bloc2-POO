# Mini-Projet: Système de Suivi de Projets et Tâches en C++

## Concepts C++ utilisés dans le projet

- **Classes et Objets**: Modélisation des projets, des tâches et des membres de l'équipe à l'aide de classes.
- **Héritage et Polymorphisme**: Utilisation de l'héritage pour créer des types de tâches spécialisés et le polymorphisme pour leur gestion.
- **Gestion des Exceptions**: Assurer une saisie valide des données et une gestion appropriée des erreurs d'exécution.
- **Collections Dynamiques**: Emploi de conteneurs STL tels que `std::vector` et `std::map` pour maintenir des collections d'objets dynamiques.

## Intégration de Bonnes Pratiques de Développement

- **Commentaires et Documentation**: Utilisation de commentaires explicatifs et de la documentation Doxygen pour chaque classe, méthode et logique importante.
- **Versionnage avec Git**: Adoption de Git pour le suivi des versions, avec des branches et des pull requests pour gérer les fonctionnalités et les corrections.
- **Tests Unitaires avec CppUnit**: Application de tests unitaires pour valider la logique de chaque composant clé du système.

### Rappel des Concepts

#### Classes et Objets

Les classes fournissent des structures pour créer des objets qui encapsulent à la fois les données et les méthodes pour manipuler ces données.

Exemple de classe `Tache`:

```cpp
class Tache
{
private:
    std::string nom;
    std::string description;
    bool estComplete;
public:
    Tache(const std::string&, const std::string&);
    void completerTache();
    // Autres méthodes...
};
```

#### Héritage et Polymorphisme

L'héritage permet à une classe de dériver d'une autre, héritant de ses attributs et méthodes. Le polymorphisme permet de redéfinir ces méthodes dans les classes dérivées.

#### Gestion des Exceptions

Le mécanisme d'exception en C++ permet de répondre aux erreurs de manière structurée et contrôlée à travers les blocs `try`, `catch`, et `throw`.

##### Try-Catch-Throw

Le bloc `try` contient le code qui peut générer une exception. Le bloc `catch` contient le code pour gérer l'exception. Les exceptions sont levées avec le mot-clé `throw`.

Les exceptions sont des objets qui héritent de la classe `std::exception`. Il est recommandé de définir des classes d'exception personnalisées pour les erreurs spécifiques à votre application.

Les exceptions servent à gérer les erreurs d'exécution, tandis que les erreurs de saisie sont gérées avec des instructions `if` et `else`.

Vous pouvez trouver plus d'informations sur les exceptions C++ [ici](https://www.cplusplus.com/doc/tutorial/exceptions/).

```cpp
try
{
    // Code qui peut générer une exception
}
catch (const std::exception& e)
{
    // Code pour gérer l'exception
} 
throw std::runtime_error("Erreur d'exécution");
```

#### Collections Dynamiques

Les conteneurs de la STL tels que `std::vector` et `std::map` offrent une flexibilité pour stocker et manipuler des collections de données qui peuvent changer de taille à l'exécution.

## Description du Projet

Développez un système en C++ pour gérer les projets de développement logiciel de manière interactive. Ce système doit permettre aux chefs de projets de créer et d'organiser des projets, de définir et d'assigner des tâches, de gérer des équipes et de suivre l'état d'avancement des projets en temps réel.

### Exemple d'Interface Utilisateur

```text
Bienvenue dans le système de suivi de projets !

Veuillez choisir une option :
1. Créer un nouveau projet
2. Afficher les projets existants
3. Quitter

Votre choix : 1

Nom du projet : Système de Suivi de Projets

Description du projet : Développement d'un système de suivi de projets en C++

Projet créé avec succès !
```

## Étapes et Exercices

1. **Classe Projet**

   - Développez une classe `Projet` avec des attributs pour stocker un nom, une description, et une collection de tâches.
   - Implémentez des méthodes pour ajouter, supprimer et rechercher des tâches dans un projet.

2. **Classe Tâche**

   - Créez une classe `Tâche` qui inclut des détails comme le nom, la description, l'état d'avancement et la priorité.
   - Ajoutez des méthodes pour marquer une tâche comme complétée et pour mettre à jour sa priorité.

3. **Gestion des Membres de l'Équipe**

   - Concevez une classe `Membre` pour représenter les membres de l'équipe avec leur nom, rôle et liste de tâches assignées.
   - Introduisez une méthode pour assigner des tâches à des membres et pour récupérer leur charge de travail.

4. **Héritage pour les Tâches Spéciales**

   - Étendez la classe `Tâche` pour créer des classes spécialisées comme `TacheCritique` ou `TacheLongTerme`, offrant des comportements ou des attributs supplémentaires.

5. **Interface Utilisateur en Ligne de Commande**

   - Élaborez une interface utilisateur en ligne de commande pour naviguer entre les différents projets, visualiser les tâches et interagir avec le système.

6. **Tests et Validation (Option)** 

   - Utilisez le framework de test CppUnit pour écrire des tests unitaires pour les classes `Projet`, `Tâche`, et `Membre`.
   - Assure la couverture de tous les cas de test importants pour valider la logique de ces classes.