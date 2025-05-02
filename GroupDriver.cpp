#include "Spell.h"
#include "Wizard.h"
#include "Creature.h"
#include <iostream>
#include <string>

void printMenu() {
    std::cout << "\nChoose an action:\n";
    std::cout << "1. Cast Fireball (Damage)\n";
    std::cout << "2. Cast Healing Light (Heal)\n";
    std::cout << "3. Exit\n";
}

int main() {
    std::string wizardName;
    std::cout << "Enter wizard's name: ";
    std::cin >> wizardName;

    // Create a wizard
    Wizard player(wizardName);

    // Create a goblin for simplicity
    Creature goblin("GOBLIN", "FIRE", 50, 50);

    // Create spells
    Spell fireball("Fireball", 20, "damage", 30);
    Spell healingLight("Healing Light", 10, "heal", 20);

    std::cout << "A wild " << goblin.getType() << " appears!\n";

    // Game loop where the player fights until the goblin is defeated
    while (!goblin.isDefeated()) {
        printMenu();

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                // Cast Fireball on Goblin
                fireball.apply(player, goblin);
                break;

            case 2:
                // Cast Healing Light on the Wizard
                healingLight.apply(player, goblin); // Healing Light is applied to wizard
                break;

            case 3:
                std::cout << "Exiting game.\n";
                return 0;

            default:
                std::cout << "Invalid choice, try again.\n";
        }

        // Check if the goblin is defeated
        if (goblin.isDefeated()) {
            std::cout << goblin.getType() << " has been defeated!\n";
        } else {
            std::cout << goblin.getType() << " is still alive.\n";
        }
    }

    return 0;
}

