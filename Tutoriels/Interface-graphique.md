# Interface Graphique

## Introduction

Pour créer une interface graphique (GUI) simple en C++, vous avez plusieurs options. L'une des bibliothèques les plus courantes et les plus puissantes pour la création de GUI en C++ est Qt. Voici un guide étape par étape pour créer une GUI simple en utilisant Qt :

1. **Installer Qt**: Téléchargez et installez le [Qt Creator IDE](https://www.qt.io/download) qui est livré avec la bibliothèque Qt et un concepteur d'interface graphique.

2. **Créer un Nouveau Projet**:
   - Ouvrez Qt Creator et sélectionnez `File > New File or Project`.
   - Choisissez `Application Qt Widgets` et cliquez sur `Choose...`.
   - Suivez les instructions pour nommer et créer votre projet.

3. **Concevoir l'Interface**:
   - Dans Qt Creator, ouvrez le fichier `.ui` généré automatiquement.
   - Utilisez le Qt Designer intégré pour faire glisser et déposer des widgets (comme des boutons, des étiquettes, des zones de texte) sur la fenêtre principale.

4. **Écrire le Code**:
   - Ajoutez des slots (des fonctions qui réagissent aux événements, comme les clics de bouton) dans le fichier de classe de la fenêtre principale.
   - Connectez les signaux des widgets (par exemple, le signal `clicked()` d'un bouton) aux slots correspondants en utilisant la macro `connect()`.

5. **Compiler et Exécuter**:
   - Compilez votre application en utilisant le bouton de compilation dans Qt Creator.
   - Exécutez l'application pour voir votre interface graphique en action.

Voici un exemple très basique de code pour une application Qt avec une fenêtre qui contient un bouton :

```cpp
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QPushButton button("Hello, World!");
    button.show();

    return app.exec();
}
```

Cet exemple montre comment créer un bouton avec le texte "Hello, World!" qui, lorsqu'il est cliqué, ferme l'application.

Pour une GUI plus complexe avec des interactions et des fonctionnalités supplémentaires, vous devriez vous familiariser avec les concepts suivants :

- **Widgets**: Éléments de base d'une GUI Qt, comme `QLabel`, `QLineEdit`, `QPushButton`, etc.
- **Layouts**: Gérez la disposition des widgets dans la fenêtre avec `QHBoxLayout`, `QVBoxLayout`, `QGridLayout`, etc.
- **Signals et Slots**: Mécanisme de communication entre les objets dans Qt pour la gestion des événements.

### Signaux et Slots en Qt

Les signaux et slots sont au cœur du mécanisme de communication entre objets dans le framework Qt. Ils permettent une séparation claire de la logique de l'interface utilisateur et de la logique métier.

#### Signaux

Un signal est émis lorsqu'un événement particulier se produit. Par exemple, la classe `QPushButton` émet le signal `clicked()` lorsque le bouton est cliqué par l'utilisateur. Les signaux sont définis dans une classe Qt à l'aide du mot-clé `signals`, et ils ne nécessitent pas d'être implémentés - Qt s'en occupe pour vous.

#### Slots

Un slot est une fonction qui peut être appelée en réponse à un signal particulier. Les slots peuvent être définis en utilisant le mot-clé `slots`, et vous devez les implémenter dans votre classe. Les slots peuvent faire partie de n'importe quelle classe, pas seulement des dérivés de `QWidget`.

#### Connexion Signal-Slot

La connexion entre un signal et un slot est établie avec la méthode `connect()`, qui prend généralement quatre paramètres :

1. L'objet émettant le signal.
2. Le signal.
3. L'objet recevant le signal.
4. Le slot qui doit être exécuté en réponse au signal.

Quand un signal est émis, tous les slots connectés à ce signal sont invoqués, ce qui permet un découplage flexible entre les émetteurs et les récepteurs.

#### Exemple

Dans cet exemple, nous allons créer une petite application qui contient un bouton et une étiquette (label). Lorsque l'utilisateur clique sur le bouton, la couleur de l'étiquette change.

#### Fichier d'en-tête (header) : `ColorChanger.h`

```cpp
#ifndef COLORCHANGER_H
#define COLORCHANGER_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

class ColorChanger : public QWidget {
    Q_OBJECT

public:
    ColorChanger(QWidget *parent = nullptr);

private slots:
    void changeColor();

private:
    QLabel *colorLabel;
    QPushButton *changeColorButton;
};

#endif // COLORCHANGER_H
```

#### Fichier source : `ColorChanger.cpp`

```cpp
#include "ColorChanger.h"
#include <QRandomGenerator>

ColorChanger::ColorChanger(QWidget *parent) : QWidget(parent) {
    // Crée un nouveau QLabel avec un texte initial et une couleur de fond
    colorLabel = new QLabel("Cliquez sur le bouton pour changer ma couleur!");
    colorLabel->setAlignment(Qt::AlignCenter);
    colorLabel->setStyleSheet("background-color: grey;");

    // Crée un nouveau QPushButton avec le texte "Changer la couleur"
    changeColorButton = new QPushButton("Changer la couleur");

    // Connecte le signal clicked() du bouton au slot changeColor() de cette classe
    connect(changeColorButton, &QPushButton::clicked, this, &ColorChanger::changeColor);

    // Crée un QVBoxLayout et y ajoute le label et le bouton
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(colorLabel);
    layout->addWidget(changeColorButton);
}

void ColorChanger::changeColor() {
    // Génère une couleur aléatoire
    int r = QRandomGenerator::global()->bounded(255);
    int g = QRandomGenerator::global()->bounded(255);
    int b = QRandomGenerator::global()->bounded(255);
    
    // Change la couleur de fond du QLabel
    colorLabel->setStyleSheet(QString("background-color: rgb(%1, %2, %3);").arg(r).arg(g).arg(b));
}
```

#### Fichier principal : `main.cpp`

```cpp
#include "ColorChanger.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ColorChanger colorChanger;
    colorChanger.show();

    return app.exec();
}
```

Dans cet exemple, la classe `ColorChanger` hérite de `QWidget`. Elle contient un QLabel et un QPushButton. Lorsque le bouton est cliqué, le slot `changeColor()` est appelé. Ce slot génère trois valeurs aléatoires pour les composantes rouge, vert et bleu, et met à jour la couleur de fond de l'étiquette avec ces valeurs, changeant ainsi sa couleur de manière aléatoire.

Notez l'utilisation de `Q_OBJECT` macro dans la définition de la classe. C'est nécessaire dans toute classe Qt qui définit des signaux ou des slots. En outre, le projet nécessite l'exécution de `moc` (Meta-Object Compiler) pour traiter les signaux et les slots, ce qui est automatiquement géré par le système de build de Qt.

---

## Exercice 1 : Création d'une application de calculatrice

### Objectif

Créer une application de calculatrice simple avec une interface graphique Qt.

### Tâche de développement

- Définir l'interface utilisateur: Vous concevriez votre interface graphique en plaçant des boutons pour les chiffres et les opérations, ainsi qu'un écran d'affichage pour les résultats.

- Connecter les signaux et les slots: Vous connecteriez les interactions de l'utilisateur avec les boutons à des fonctions dans votre code qui traitent les entrées et calculent les résultats.

- Implémenter la logique de la calculatrice: Vous écririez la logique nécessaire pour effectuer des calculs de base comme l'addition, la soustraction, la multiplication et la division.

- Compiler et exécuter: Vous compileriez votre application et l'exécuteriez pour voir votre calculatrice en action.

### Squelette de Base

Voici le code de base pour une application de calculatrice simple :

```cpp
#include <QApplication>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>

/**
 * @brief Classe principale de l'application de calculatrice.
 * Elle crée l'interface utilisateur et gère la logique de la calculatrice.
 */
class CalculatorApp : public QWidget {
public:
    CalculatorApp();  ///< Constructeur pour initialiser l'application calculatrice.

private slots:
    void digitPressed();              ///< Slot activé lorsqu'un bouton de chiffre est pressé.
    void unaryOperationPressed();     ///< Slot activé pour une opération unaire.
    void binaryOperationPressed();    ///< Slot activé pour une opération binaire.
    void equalsPressed();             ///< Slot activé lorsque le bouton égal est pressé.
    void clearPressed();              ///< Slot activé pour effacer l'affichage.

private:
    QLineEdit *display;               ///< Écran d'affichage de la calculatrice.
    double currentValue;              ///< Valeur actuelle stockée pour les calculs.
    QString pendingOperator;          ///< Opérateur en attente pour effectuer le calcul.
    bool waitingForOperand;           ///< Indicateur si la calculatrice attend une opérande.

    void calculate(double rightOperand);  ///< Effectue le calcul en utilisant l'opérateur et l'opérande en attente.
};

/**
 * @brief Constructeur de CalculatorApp.
 * Initialise l'interface utilisateur et les connections des signaux et slots.
 */
CalculatorApp::CalculatorApp() : currentValue(0.0), waitingForOperand(true) {
    // Initialisation du layout pour placer les widgets
    QGridLayout *layout = new QGridLayout;

    // Configuration de l'écran d'affichage
    display = new QLineEdit("0");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(15);
    layout->addWidget(display, 0, 0, 1, 4);

    // Les boutons pour les chiffres et les opérations seront ajoutés ici.
    // Pour chaque bouton, créez une instance de QPushButton et configurez sa taille, son texte, etc.
    // Connectez ensuite le signal clicked() de chaque bouton à son slot respectif.
    // Par exemple :
    // QPushButton *button = new QPushButton("1");
    // connect(button, &QPushButton::clicked, this, &CalculatorApp::digitPressed);
    // layout->addWidget(button, row, column);

    // Vous devriez créer un bouton pour chaque chiffre, chaque opération (+, -, *, /),
    // ainsi que pour les fonctions telles que 'égal' et 'effacer'.

    // Configuration finale du layout
    setLayout(layout);
    setWindowTitle(tr("Calculatrice Simple"));
}

// Les slots pour la manipulation des entrées de l'utilisateur et pour l'exécution des opérations seront implémentés ici.
// Par exemple :
// void CalculatorApp::digitPressed() { ... }
// void CalculatorApp::binaryOperationPressed() { ... }
// void CalculatorApp::equalsPressed() { ... }
// void CalculatorApp::clearPressed() { ... }

/**
 * @brief Effectue le calcul et met à jour l'affichage.
 * @param rightOperand L'opérande droite pour l'opération.
 */
void CalculatorApp::calculate(double rightOperand) {
    if (pendingOperator.isEmpty()) {
        currentValue = rightOperand;
    } else {
        // Effectuer le calcul en fonction de l'opérateur et de l'opérande en attente
        // Mettre à jour currentValue et l'affichage
    }
    waitingForOperand = true;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    CalculatorApp calculator;
    calculator.show();
    return app.exec();
}
```

# Ressources

Voici des références pour les concepts clés nécessaires à la résolution de l'exercice de création d'une application de calculatrice avec une interface graphique Qt en C++ :

1. **Qt Framework**:
   - Documentation officielle de Qt pour débutants : [Qt for beginners](https://doc.qt.io/qt-5/qtforbeginners.html)
   - Tutoriels et exemples Qt : [Qt Examples and Tutorials](https://doc.qt.io/qt-5/examplesandtutorials.html)

2. **Classe principale**:
   - Introduction aux Widgets Qt : [Qt Widgets](https://doc.qt.io/qt-5/widget-classes.html)
   - Guide de programmation orientée objet avec Qt : [Object-Oriented Programming with Qt](https://doc.qt.io/archives/3.3/oop.html)

3. **Signaux et slots**:
   - Signaux et slots dans la documentation de Qt : [Signals & Slots](https://doc.qt.io/qt-5/signalsandslots.html)

4. **Gestion des événements**:
   - Explication des événements et des signaux/slots : [Events and Signals in Qt5](https://doc.qt.io/qt-5/eventsandfilters.html)

5. **Logique de la calculatrice**:
   - Concept de développement d'interface utilisateur : [Qt UI Tools](https://doc.qt.io/qt-5.9/designer-using-a-ui-file.html)
   - Documentation sur les layouts : [Layout Management](https://doc.qt.io/qt-5/layout.html)

6. **Gestion de l'interface utilisateur**:
   - Guide des layouts Qt : [Layout Examples](https://doc.qt.io/qt-5/layout.html)

7. **Boucle d'événement principale**:
   - Explication de la boucle d'événements : [Event Loop in Qt](https://doc.qt.io/qt-5/qcoreapplication.html#exec)

8. **Bonnes pratiques de programmation**:
   - Conseils de programmation en C++ : [Effective C++](https://www.aristeia.com/books.html) par Scott Meyers (livre non spécifique à Qt mais incontournable pour les bonnes pratiques en C++)
   - Guide de style C++ : [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)

Ces ressources vous donneront une base solide pour comprendre comment construire des applications en utilisant le framework Qt et pour approfondir vos connaissances en programmation C++.





