# Prosit 2 - Workshop

## Exercice 1 : Compréhension des relations entre classes et gestion de la mémoire

### 1.1. Analyse de code

Examinez le code suivant, qui illustre les relations entre les classes et l'utilisation des pointeurs et des références en C++ :

```cpp
#ifndef PCH_H
#define PCH_H

#include <iostream>
#include "CLb.h"
#include "CLa.h"

#endif // PCH_H
using namespace std;

// CLa.h
class CLa {
private:
    CLb b1;
    CLb* p1;

public:
    void ma1(void);
    void ma2(void);
    void ma3(CLb);
    void ma4(CLb&);
    void ma5(CLb*);
};

// CLb.h
#pragma once
#include "pch.h"

class CLb {
public:
    void mb(void);
};

// CLa.cpp
#include "pch.h"

void CLa::ma1(void) {
    cout << "Je travaille pour CLa" << endl;
    this->b1.mb();
}

void CLa::ma2(void) {
    cout << "Je travaille pour CLa" << endl;
    this->p1 = new CLb();
    this->p1->mb();
}

void CLa::ma3(CLb ov) {
    cout << "Je travaille pour CLa" << endl;
    ov.mb();
}

void CLa::ma4(CLb& oa) {
    cout << "Je travaille pour CLa" << endl;
    oa.mb();
}

void CLa::ma5(CLb* op) {
    cout << "Je travaille pour CLa" << endl;
    op->mb();
}

// CLb.cpp
#include "pch.h"

void CLb::mb(void) {
    cout << "Je travaille pour CLb" << endl;
}

// main.cpp
#include "pch.h"
using namespace System;

int main(void) {
    int pause;
    CLa oa;
    CLb ob;
    CLb* pb;
    pb = &ob;
    
    oa.ma1();
    oa.ma2();
    oa.ma3(ob);
    oa.ma4(*pb);
    oa.ma5(pb);

    cin >> pause;
}
```

1. Gestion des objets et des pointeurs : Comment CLa gère-t-elle les instances de CLb avec les membres b1 et p1 ? Quelles sont les implications de l'utilisation d'un membre objet b1 par rapport à un pointeur d'objet p1 dans la classe CLa ?

2. Passage de paramètres : Quelle est la différence entre les méthodes ma3, ma4, et ma5 en termes de passage d'arguments à la méthode mb de CLb ? Comment chaque méthode affecte-t-elle l'objet passé en terme de portée et de modifications potentielles ?

---

## Exercice 2 : Création d'une application avec fonctionnalités séparées

### Objectif

Développer une application avec des fonctionnalités clairement définies, qui démontre l'utilisation efficace des principes de la programmation orientée objet.

### 2.1. Tâche de développement

Votre mission est de programmer une application qui comprend trois fonctionnalités principales :

- **Fonctionnalité A** : Doit permettre de réaliser des calculs mathématiques de base (addition, soustraction).
- **Fonctionnalité B** : Doit gérer une petite base de données de contacts (ajouter, supprimer des contacts).
- **Fonctionnalité C** : Doit combiner des calculs mathématiques et la gestion de données pour produire des statistiques sur les contacts (par exemple, calculer l'âge moyen).

Chaque fonctionnalité doit être codée comme une section distincte de votre application.

### 2.2. Réflexion sur la conception

Discutez de la manière dont vous avez structuré votre application pour intégrer ces fonctionnalités. Comment avez-vous assuré que les sections de l'application peuvent fonctionner indépendamment tout en étant capables de partager des données si nécessaire ?

### 2.3. Flexibilité de l'application

Imaginez que vous devez maintenant ajouter une nouvelle fonctionnalité D, qui nécessite des modifications dans les calculs mathématiques ou dans la gestion des contacts. Comment votre conception actuelle facilite ou complique l'introduction de cette nouvelle fonctionnalité ? Comment pourrait-elle être modifiée pour mieux accueillir de telles extensions futures ?

---

## Exercice 3 : Manipulation de fichiers et gestion des données

### 3.1. Implémentation de classes

Créez les fichiers suivants à partir d'un diagramme de classe fourni :

- `Etudiant.h`
- `Etudiant.cpp`
- `Promo.h`
- `Promo.cpp`
- Le fichier `main` du projet.

La classe `Etudiant` comprend des constructeurs surchargés et des accesseurs, et la classe `Promo` contient le nombre d'étudiants.

Incluez également :

- Une méthode `inputNotesUtilisateur` pour l'insertion des données par l'utilisateur.
- Une méthode `afficheEtudiants` pour afficher les étudiants et leurs noms.
- Une méthode `inputNoteAUFichier` pour l'enregistrement des données dans un fichier.
- Une méthode `outputNoteDUFichier` pour la récupération des données depuis un fichier.

La liste d'étudiants est limitée à 10 pour simplifier la gestion de la mémoire.
