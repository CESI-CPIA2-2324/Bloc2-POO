
#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>

// Classe de base 'Animal'
class Animal {
public:
    std::string nom;
    Animal(std::string nom); // Constructeur
    virtual ~Animal(); // Destructeur virtuel
    virtual std::string parler() const = 0; // Méthode virtuelle pure pour être surchargée
    std::string getNom() const;
};



#endif
