
#include "ChienEtChat.h"

// Implémentation pour 'Chien'
Chien::Chien(std::string nom) : Animal(nom) {}

std::string Chien::parler() const {
    return nom + " dit Wouf!";
}

// Implémentation pour 'Chat'
Chat::Chat(std::string nom) : Animal(nom) {}

std::string Chat::parler() const {
    return nom + " dit Miaou!";
}

// Implémentation pour 'ChienDeChasse'

ChienDeChasse::ChienDeChasse(std::string nom) : Chien(nom) {}

std::string ChienDeChasse::parler() const {
    return nom + " dit Wouf! Wouf!";
}
