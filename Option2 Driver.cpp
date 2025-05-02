#include "Spell.h"
#include "Wizard.h"
#include "Creature.h"
#include <iostream>
#include <string>
#include <vector>

// Function to print the available menu choices
void printMenu() {
    std::cout << "\nChoose an action:\n";
    std::cout << "1. Cast Fireball (Damage)\n";
    std::cout << "2. Cast Healing Light (Heal)\n";
    std::cout << "3. Level Up Wizard\n";
    std::cout << "4. Exit\n";
}

// Function to print available creatures
void printCreatureMenu() {
    std::cout << "\nChoose a creature to fight:\n";
    std::cout << "1. Goblin (Health: 50, Attack: 20)\n";
    std::cout << "2. Orc (Health: 80, Attack: 30)\n";
    std::cout << "3. Elf (Health: 60, Attack: 25)\n";
    std::cout << "4. Dragon (Health: 100, Attack: 50)\n";
    std::cout << "5. Exit\n";
}

// Function to level up the wizard
void levelUpWizard(Wizard &wizard) {
    wizard.mana += 20;   // Increase mana by 20
    wizard.health += 20; // Increase health by 20
    std::cout << wizard.name << " has leveled up! New health: " << wizard.health << ", New mana: " << wizard.mana << "\n";
}

int main() {
    std::string wizardName;
    std::cout << "Enter wizard's name: ";
    std::cin >> wizardName;

    // Create a wizard
    Wizard player(wizardName);

    // Available spells
    Spell fireball("Fireball", 20, "damage", 30);
    Spell healingLight("Healing Light", 10, "heal", 20);

    // Game loop
    while (true) {
        // Let the user choose a creature to fight
        printCreatureMenu();
        int creatureChoice;
        std::cin >> creatureChoice;

        Creature *currentCreature = nullptr;
        switch (creatureChoice) {
            case 1:
                currentCreature = new Creature("GOBLIN", "FIRE", 50, 20);
                break;
            case 2:
                currentCreature = new Creature("ORC", "EARTH", 80, 30);
                break;
            case 3:
                currentCreature = new Creature("ELF", "WIND", 60, 25);
                break;
            case 4:
                currentCreature = new Creature("DRAGON", "FIRE", 100, 50);
                break;
            case 5:
                std::cout << "Exiting game.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Try again.\n";
                continue;
        }

        std::cout << "A wild " << currentCreature->getType() << " appears!\n";

        // Game loop where the player fights until the creature is defeated
        while (!currentCreature->isDefeated()) {
            printMenu();

            int choice;
            std::cin >> choice;

            switch (choice) {
                case 1:
                    // Cast Fireball on Creature
                    fireball.apply(player, *currentCreature);
                    break;

                case 2:
                    // Cast Healing Light on the Wizard
                    healingLight.apply(player, *currentCreature);
                    break;

                case 3:
                    // Level up wizard
                    levelUpWizard(player);
                    break;

                case 4:
                    std::cout << "Exiting game.\n";
                    delete currentCreature;  // Don't forget to delete the creature when exiting
                    return 0;

                default:
                    std::cout << "Invalid choice, try again.\n";
            }

            // Check if the creature is defeated
            if (currentCreature->isDefeated()) {
                std::cout << currentCreature->getType() << " has been defeated!\n";
                delete currentCreature; // Clean up creature object
            } else {
                std::cout << currentCreature->getType() << " is still alive.\n";
            }
        }
    }

    return 0;
}
