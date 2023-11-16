
#include "Animal.h"

// Implémentation du constructeur
Animal::Animal(std::string n) : nom(n) {}

// Implémentation du destructeur virtuel
Animal::~Animal() {}

// Implémentation de la méthode getNom()
std::string Animal::getNom() const {
    return nom;
}
