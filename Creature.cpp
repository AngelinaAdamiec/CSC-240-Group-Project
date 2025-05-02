#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>

#include "Creature.h"

// Default constructor implementation
Creature::Creature() {

    // Seed and get random parameters. 
    std::srand(std::time(0));
    int randomType = std::rand() % 4;
    int randomElem = std::rand() % 4;
    int randomHealth = (std::rand() % 25) + 1; 

    // Set random creature type. 
    switch (randomType) {
        case 0:
            type = "GOBLIN";
            break;
        case 1:
            type = "ORC";
            break;
        case 2:
            type = "ELF";
            break;
        case 3: 
            type = "DRAGON";
            break;
    }

    // Set random elemental type. 
    switch (randomElem) {
        case 0:
            element = "FIRE";
            break;
        case 1:
            element = "WATER";
            break;
        case 2:
            element = "EARTH";
            break;
        case 3: 
            element = "WIND";
            break;
    }

    // Set random health. 
    switch(randomType) {
        case 0:
            type = "GOBLIN";
            health = randomHealth; 
            break;
        case 1:
            type = "ORC";
            health = randomHealth; 
            break;
        case 2:
            type = "ELF";
            health = 50 + randomHealth; 
            break;
        case 3: 
            type = "DRAGON";
            health = 50 + randomHealth;
            break;
    }

    // Set random attackPower. 
    switch(randomType) {
        case 0:
            type = "GOBLIN";
            attackPower = health; 
            break;
        case 1:
            type = "ORC";
            health = health * 2; 
            break;
        case 2:
            type = "ELF";
            attackPower = health; 
            break;
        case 3: 
            type = "DRAGON";
            health = health * 2;
            break;
    }

    // Set resistances. 
    switch(randomElem) {
        case 0:
            element = "FIRE";
            resistances.push_back("WATER");
            break;
        case 1:
            element = "WATER";
            resistances.push_back("EARTH");
            break;
        case 2:
            element = "EARTH";
            resistances.push_back("WATER");
            break;
        case 3: 
            element = "WIND";
            resistances.push_back("FIRE");
            break;
        }          
}

// Parameterized constructor implementation
Creature::Creature(std::string t, int hp, int atk, std::vector<std::string> res)
    : type(t), health(hp), attackPower(atk), resistances(res) {}

// Attacks at some value randomly chosen from the difference between max attack power and health. 
int Creature::attack() {
    std::srand(std::time(0));
    int attackVariance = attackPower - health;
    int attackDamage = std::rand() % attackVariance;
    return attackDamage;
}

// Takes damage unless the spell type is resisted, then damage is reduced by half. 
void Creature::takeDamage(int amount, std::string spellType) {
    if (resistances.at(0) == spellType) {
        health -= amount / 2; 
    }
    health -= amount; 
    std::cout << type << " resists " << spellType << " spells! Damage reduced." << std::endl;
    if (health < 0) health = 0;
    std::cout << type << " takes " << amount << " damage. Remaining health: " << health << std::endl;
}

// Checks if the creature has been defeated.
bool Creature::isDefeated() {
    return health <= 0;
}
