#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <vector>
#include <iostream>

// This class represents an enemy creature in the game.
// Each creature has a type, health, attack power, and some resistances to certain spell types.

class Creature {
public:
    std::string type;
    int health;
    int attackPower;
    std::vector<std::string> resistances;

    // Constructor that initializes a creature's stats
    Creature(std::string t, int hp, int atk, std::vector<std::string> res);

    // This method simulates the creature performing an attack
    // For now it just returns the attackPower
    int attack();

    // This method reduces the creature's health
    // If the spell type is something the creature resists, damage is reduced
    void takeDamage(int amount, std::string spellType);

    // Returns true if the creature's health is 0 or below
    bool isDefeated();
};

#endif
