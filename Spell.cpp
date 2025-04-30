#include "Spell.h"
#include "Wizard.h"
#include "Creature.h"

// Constructor for initializing a new Spell object
Spell::Spell(std::string n, int cost, std::string type, int pow)
    : name(n), manaCost(cost), effectType(type), power(pow) {}

// This method applies the effect of the spell.
// It first checks if the wizard has enough mana to cast it.
// Then it applies either healing or damage depending on the type.
void Spell::apply(Wizard &caster, Creature &target) {
    if (caster.mana < manaCost) {
        std::cout << "Not enough mana to cast " << name << "." << std::endl;
        return;
    }

    caster.mana -= manaCost;

    if (effectType == "damage") {
        target.takeDamage(power, "magic");
        std::cout << caster.name << " casts " << name 
                  << " dealing " << power << " damage." << std::endl;
    } else if (effectType == "heal") {
        caster.heal(power);
        std::cout << caster.name << " casts " << name 
                  << " and heals for " << power << " health." << std::endl;
    } else {
        std::cout << "Unknown spell effect." << std::endl;
    }
}
