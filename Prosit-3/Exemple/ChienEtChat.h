
#ifndef CHIENETCHAT_H
#define CHIENETCHAT_H
#include "Animal.h"

// Classe dérivée 'Chien'
class Chien : public Animal
{
public:
    Chien(std::string nom);
    std::string parler() const; // Surcharge de la méthode parler
};


// Classe dérivée 'Chat'
class Chat : public Animal
{
public:
    Chat(std::string nom);
    std::string parler() const; // Surcharge de la méthode parler
};

// Classe dérivée 'ChienDeChasse'
class ChienDeChasse : public Chien
{
public:
    ChienDeChasse(std::string nom);
    std::string parler() const; // Surcharge de la méthode parler
};

#endif
