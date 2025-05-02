#ifndef WIZARD_H
#define WIZARD_H

#include <string>
#include <iostream>

// This is a simplified Wizard class for testing purposes.
// It only includes the fields and methods needed to test spell casting.

class Wizard {
public:
    std::string name;
    int health;
    int mana;

    Wizard(std::string n, int h = 100, int m = 100);

    void heal(int amount);
};

#endif
