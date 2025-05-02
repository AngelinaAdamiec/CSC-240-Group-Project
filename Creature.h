#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <vector>
#include <iostream>

// This class represents an enemy creature in the game.
// Each creature has a type, health, attack power, and some resistances to certain spell types.
// Each creature can be of type: GOBLIN, ORC, ELF, DRAGON. 
// Each creature can have elemental type: FIRE, WATER, EARTH, WIND. 
class Creature {
public:
    std::string type;
    std::string element;
    int health;
    int attackPower;
    std::vector<std::string> resistances;

    // Default constructor
    // Pre:  None. 
    // Post: Creates a Creature object with random type, random element, health & attack based on type & element, 
    //       and a resistance based on the creature's elemental type. 
    Creature(); 

    // Parameterized constructor that initializes a creature's stats. 
    // Pre:  None. 
    // Post: Creates a Creature object with passed arguments. Resistances defaults to none. 
    Creature(std::string creatureType, std::string elementalType, int health, int attack, std::vector<std::string> res = {"NONE"});

    // Function: Simulates creature performing an attack. 
    // Pre:  None. 
    // Post: Returns attack power that scales with creature type and creature instance health. 
    int attack();

    // Function: Reduces the creature's health
    // Pre:  None. 
    // Post: If the spell type is something the creature resists, damage is reduced. 
    void takeDamage(int amount, std::string spellType);

    // Function: Simulates defeat. 
    // Pre:  None. 
    // Post: Returns true if the creature's health is 0 or below
    bool isDefeated();
};

#endif
