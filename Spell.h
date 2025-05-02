#ifndef SPELL_H
#define SPELL_H

#include <string>
#include <iostream>

// This class defines a Spell that can be cast by a wizard.
// Each spell has a name, mana cost, an effect type (either "damage" or "heal"),
// and a power value that determines how strong the effect is.

class Spell {
public:
    std::string name;
    int manaCost;
    std::string effectType;
    int power;

    // Constructor to set the spell's properties when it is created
    Spell(std::string n, int cost, std::string type, int pow);

    // This function applies the spell effect.
    // If it's a healing spell, it increases the wizard's health.
    // If it's a damaging spell, it reduces the creature's health.
    // The wizard loses mana equal to the spell's cost.
    void apply(class Wizard &caster, class Creature &target); 
};

#endif
