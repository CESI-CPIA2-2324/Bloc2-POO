# Mini-Projet: Système de Gestion de Comptes Bancaires Simple

## Concepts C++ utilisés dans le projet

- **Classes et Objets**: Utilisation de classes pour représenter des comptes bancaires.
- **Encapsulation**: Utilisation de l'accès privé pour protéger les attributs des comptes.
- **Constructeurs**: Initialisation des objets compte avec des états spécifiques.
- **Méthodes**: Opérations bancaires comme dépôts et retraits.

## Intégration de Bonnes Pratiques de Développement

- **Commentaires**: Documentez chaque classe, méthode et logique importante avec des commentaires clairs.
- **Versionnage**: Utilisez Git pour le suivi des versions et l'historique des modifications.
- **Modélisation UML**: Avant de coder, créez un diagramme UML pour planifier la structure des classes.

### Rappel des Concepts

#### Classes et Objets

Une classe est un modèle pour un objet. Une classe définit des attributs et des méthodes qui représentent l'état et le comportement d'un objet. Un objet est une instance d'une classe. Par exemple, la classe `CompteBancaire` peut être utilisée pour créer des objets de type compte bancaire.

Une exemple de classe `Exemple`:

```cpp
class Exemple
{
private:
    int attribut1;
    int attribut2;
public:
    Exemple(void);
    Exemple(int);
    void methode1();
    void methode2();
};
```

#### Encapsulation

L'encapsulation est le mécanisme qui permet de regrouper des données et des méthodes dans une classe. L'encapsulation permet de protéger les données en les rendant privées. Les méthodes publiques peuvent être utilisées pour accéder et modifier les données privées.

En C++, l'encapsulation est représentée par les mots-clés `public`, `private` et `protected`. Les attributs et les méthodes privés ne peuvent être accédés que par les méthodes de la classe. Les attributs et les méthodes publics peuvent être accédés par n'importe qui. Les attributs et les méthodes protégés peuvent être accédés par les méthodes de la classe et par les méthodes des classes dérivées.

#### Constructeurs

Un constructeur est une méthode spéciale qui est appelée lorsqu'un objet est créé. Les constructeurs sont utilisés pour initialiser les objets avec des états spécifiques. En C++, un constructeur a le même nom que la classe et n'a pas de type de retour.

Un exemple de constructeur `Exemple`:

```cpp
class Exemple
{
private:
    int attribut1;
    int attribut2;
public:
    Exemple(void);
    Exemple(int);
    void methode1();
    void methode2();
};

Exemple::Exemple(void)
{
    attribut1 = 0;
    attribut2 = 0;
}

Exemple::Exemple(int a)
{
    attribut1 = a;
    attribut2 = 0;
}
```

#### Méthodes

Une méthode est une fonction qui est définie à l'intérieur d'une classe. Les méthodes sont utilisées pour définir le comportement d'un objet. Les méthodes peuvent être définies à l'intérieur de la classe ou à l'extérieur de la classe.

Un exemple de méthode `Exemple`:

```cpp
class Exemple
{
private:
    int attribut1;
    int attribut2;
public:
    Exemple(void);
    Exemple(int);
    void methode1();
    void methode2();
};

void Exemple::methode1()
{
    attribut1 = 0;
    attribut2 = 0;
}

void Exemple::methode2()
{
    attribut1 = 0;
    attribut2 = 0;
}
```

## Description du Projet

Développer un système simple pour créer et gérer des comptes bancaires. Le système doit permettre aux utilisateurs d'effectuer des dépôts, des retraits et de consulter le solde de leurs comptes.

## Étapes et Exercices

1. **Classe CompteBancaire**

Créez une classe `CompteBancaire` qui contient des attributs privés comme `titulaire`, `numeroCompte`, et `solde`. Fournissez des méthodes publiques pour accéder et modifier ces attributs de manière sécurisée.

   Indice : Utilisez les mots-clés `public` et `private` pour définir les attributs et les méthodes de la classe.

2. **Constructeurs et Destructeurs**

Ajoutez un constructeur à la classe `CompteBancaire` pour initialiser un compte avec le titulaire et un solde initial. Implementez un destructeur qui peut, par exemple, enregistrer une action de clôture de compte dans un fichier journal.

   Indice : Utilisez le mot-clé `this` pour accéder aux attributs de la classe.

3. **Opérations de Base**

Implémentez des méthodes pour permettre les dépôts (`deposer`) et les retraits (`retirer`). Assurez-vous que le solde ne peut pas devenir négatif.

   Indice : Utilisez le mot-clé `static` pour définir des attributs et des méthodes de classe.

4. **Affichage des Informations**

Ajoutez une méthode `afficherSolde` qui imprime le solde actuel du compte. Une autre méthode `afficherInformations` pourrait afficher toutes les informations du compte.

   Indice : Utilisez le mot-clé `const` pour définir des méthodes qui ne modifient pas les attributs de la classe.

5. **Gestion des Transactions**

Créer une structure ou une classe `Transaction` qui enregistre les détails des opérations bancaires et les associe à la classe `CompteBancaire`.

   Indice : Utilisez le mot-clé `friend` pour permettre à la classe `Transaction` d'accéder aux attributs privés de la classe `CompteBancaire`.

6. **Validation des Opérations**

Écrivez des fonctions qui valident les opérations de dépôt et de retrait, vérifiant par exemple que les montants des transactions sont positifs et que le solde est suffisant pour un retrait.

   Indice : Utilisez le mot-clé `inline` pour définir des fonctions qui sont compilées à l'endroit où elles sont appelées.

7. **Interface Utilisateur Simple**

Concevez une interface utilisateur en ligne de commande qui permet à l'utilisateur de créer un compte, effectuer des dépôts, des retraits, et afficher le solde.

   Indice : Utilisez le mot-clé `namespace` pour organiser les classes et les fonctions.
