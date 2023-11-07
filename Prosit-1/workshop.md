# Workshop

## Exercice 1

1. Créez une classe qui comprend une méthode affichant un message. Utilisez cette classe dans la fonction main() de votre programme en effectuant une allocation statique et une allocation dynamique.

2. Présentez votre code à l'aide du vidéo projecteur. Expliquez les raisons de vos choix de programmation et modélisez les allocations mémoires sur un tableau. Discutez avec les autres étudiants des avantages et inconvénients d'une allocation sur la pile et sur le tas.

## Exercice 2

1. Voici le header et le main() à utiliser :

```cpp

#pragma once

class CLcalcul
{
private:
    int n;
    void ini(int);
    static int cpteObj;

public:
    CLcalcul(void);
    CLcalcul(int);
    void carre();
    void setN(int);
    int getN(void);
};

#include "pch.h"

using namespace System;

void main(void)
{
    int pause;
    CLcalcul o1;
    CLcalcul o2(2);
    CLcalcul* p1;
    CLcalcul* p2;

    p1 = new CLcalcul();
    p2 = new CLcalcul(3);

    o1.carre(); o2.carre(); cout << o1.getN() << endl; cout << o2.getN() << endl;

    p1->carre(); p2->carre(); cout << p1->getN() << endl; cout << p2->getN() << endl;

    cin >> pause;
}

```

2. Réalisez le fichier .cpp de la classe CLcalcul pour que le programme fonctionne correctement.

3. Présentez et expliquez votre code .cpp en détail. Répondez aux questions pour démontrer votre compréhension.

### Exercice 3

1. Concevez un programme avec un main, une classe de type service et deux classes de type composant. Visez la simplicité.

2. Modélisez votre programme à l'aide de diagrammes de classes, de séquence et d’activité.

3. Échangez vos modélisations avec un pair et tentez de coder le programme basé sur les diagrammes reçus.

4. Comparez le code résultant avec celui de votre pair et discutez des différences ou problèmes éventuels.

5. Utilisez les modélisations et les différences observées comme base pour des explications plus approfondies.

### Exercice 4

1. Définissez la classe Fraction et ses méthodes pour réaliser les opérations d'addition, de soustraction, de multiplication et de division.

2. Créez :

    - Le diagramme de classes.
    - Le diagramme de séquence pour les quatre opérations.

3. Présentez votre fichier C++ (.cpp) et expliquez votre code ligne par ligne. Participez aux discussions et répondez aux questions pour valider votre compréhension.