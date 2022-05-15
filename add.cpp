#include "add.h"
#include <string>
#include <iostream>

void GameStructure::Help() {} // virtual empty method


// CHARACTER STUFF
int Character::getHealth() { // health getter method
    return Health;
}
void Character::setHealth(int health) { // health setter method
    Health = health;
    if (Health <= 0) { // character is dead if health is less than or equal to zero
        Health = 0; // in case health is less than zero, reset it to zero
        cout << Name << " has Expired..." << endl;
    }
}
void Character::defend(int hitPoints) {
    int newHealth = getHealth() - hitPoints; // what will the health be after attack?
    setHealth(newHealth); // set the new health
}
void Character::Talk(string stuffToSay) { // method for character to speak
    cout << endl << stuffToSay << endl << endl;
}
void Character::Talk(string name, string stuffToSay) { // another method for character to speak, but allows name to be passed in as well
    cout << endl << "I'm " << name << ", and " << stuffToSay << endl << endl;
}
int Character::Attack() { // default attack method for character results in 10 hit points
    return 10; // attack returns 10 hit points
    }
void Character::Help() {} // overriding help method


// NINJA STUFF:
Ninja::Ninja(string N, int H) { // constructor
    Name = N; // define name
    setHealth(H); // initialize starting health
}
void Ninja::ThrowStars() {
    Talk(Name, "I am throwing stars!");
}
int Ninja::Attack() {
    ThrowStars(); // throw some stars
    return 25; // overrride superclass method
}
void Ninja::Help() {
    cout << endl << "Ninjas are quiet and swift; you can use them to throw stars!" << endl << endl;
}


// PIRATE STUFF:
Pirate::Pirate(string N, int H) { // constructor
    Name = N; // define name
    setHealth(H); // initialize starting health

}
void Pirate::UseSword() {
    Talk(Name, "I am Swooshing my Sword!");
}
int Pirate::Attack() {
    UseSword(); // use the sword
    return 25; // overrride superclass method
}
void Pirate::Help() {
    cout << endl << "Pirates are loud and forceful; you can use them to attack with swords!" << endl << endl;
}