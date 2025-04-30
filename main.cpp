#include "Spell.h"
#include "Wizard.h"
#include "Creature.h"

int main() {
    // Create a wizard
    Wizard player("Merlin");

    // Create a creature that is weak to magic (no resistances)
    Creature goblin("Goblin", 50, 10, {});

    // Create a damaging spell
    Spell fireball("Fireball", 20, "damage", 30);

    // Cast spell on goblin
    fireball.apply(player, goblin);

    // Check if goblin is defeated
    if (goblin.isDefeated()) {
        std::cout << goblin.type << " has been defeated!" << std::endl;
    } else {
        std::cout << goblin.type << " is still alive." << std::endl;
    }

    // Create a healing spell
    Spell healingLight("Healing Light", 10, "heal", 20);

    // Cast healing spell on wizard
    healingLight.apply(player, goblin); // even though target is goblin, healing affects wizard

    return 0;
}
