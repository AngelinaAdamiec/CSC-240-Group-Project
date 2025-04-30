#include "Wizard.h"

Wizard::Wizard(std::string n, int h, int m)
    : name(n), health(h), mana(m) {}

// Adds health to the wizard, used when casting healing spells
void Wizard::heal(int amount) {
    health += amount;
    if (health > 100) health = 100;

    std::cout << name << " is healed for " << amount 
              << " points. Current health: " << health << std::endl;
}
