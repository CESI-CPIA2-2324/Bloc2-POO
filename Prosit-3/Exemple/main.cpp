
#include <iostream>
#include "ChienEtChat.h"

int main() {
    Chien chien("Buddy");
    Chat chat("Whiskers");

    // Démonstration de l'héritage
    std::cout << chien.getNom() << std::endl; // Attendu : "Buddy"
    std::cout << chat.getNom() << std::endl;  // Attendu : "Whiskers"
    
    // Démonstration du polymorphisme
    std::cout << chien.parler() << std::endl; // Attendu : "Buddy dit Wouf!"
    std::cout << chat.parler() << std::endl;  // Attendu : "Whiskers dit Miaou!"
    
    return 0;
}
