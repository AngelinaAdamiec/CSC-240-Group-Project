#include "Creature.h"

// Constructor implementation
Creature::Creature(std::string t, int hp, int atk, std::vector<std::string> res)
    : type(t), health(hp), attackPower(atk), resistances(res) {}

// When the creature attacks, it simply deals a fixed amount of damage for now
int Creature::attack() {
    return attackPower;
}

// Takes damage unless the spell type is resisted, then damage is reduced by half
void Creature::takeDamage(int amount, std::string spellType) {
    for (const std::string &resist : resistances) {
        if (resist == spellType) {
            amount /= 2; // reduce damage by 50% if resistance applies
            std::cout << type << " resists " << spellType << " spells! Damage reduced." << std::endl;
            break;
        }
    }

    health -= amount;
    if (health < 0) health = 0;

    std::cout << type << " takes " << amount << " damage. Remaining health: " << health << std::endl;
}

// Checks if the creature has been defeated
bool Creature::isDefeated() {
    return health <= 0;
}
