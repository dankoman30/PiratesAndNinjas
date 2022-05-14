// ObjectOrientedProgramming.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std; // save us some typing

class GameStructure {
public:
    virtual void Help() {} // virtual empty method
};

class Character: public GameStructure {
private:
    int Health = 100; // start health at 100
public:
    string Name;
    int getHealth() {
        return Health;
    }
    void setHealth(int health) {
        Health = health;
        if (Health <= 0) { // character is dead
            Health = 0;
            cout << Name << " has Expired..." << endl;
        }
    }
    void defend(int hitPoints) {
        int newHealth = getHealth() - hitPoints; // what will the health be after attack?
        setHealth(newHealth); // set the new health
    }
    void Talk(string stuffToSay) {
        cout << endl << stuffToSay << endl << endl;
    }
    void Talk(string name, string stuffToSay) {
        cout << endl << "I'm " << name << ", and " << stuffToSay << endl << endl;
    }
    virtual int Attack() {
        return 10; // attack returns 10 hit points
    }
    void Help() {}
};

class Ninja : public Character {
public:
    void ThrowStars() {
        Talk(Name, "I am throwing stars!");
    }
    Ninja(string N) { // constructor
        Name = N;
    }
    int Attack() {
        ThrowStars(); // throw some stars
        return 25; // overrride superclass method
    }
    void Help() {
        cout << endl << "Ninjas are quiet and swift; you can use them to throw stars!" << endl;
    }

};

class Pirate : public Character {
public:
    void UseSword() {
        Talk(Name, "I am Swooshing my Sword!");
    }
    Pirate(string N) { // constructor
        Name = N;
    }
    int Attack() {
        UseSword(); // use the sword
        return 25; // overrride superclass method
    }
    void Help() {
        cout << endl << "Pirates are loud and forceful; you can use them to attack with swords!" << endl;
    }
};

void intro() {
    // intro stuff here
}

int RandomRoll() {
    srand((unsigned)time(0));
    int randomNumber;
    randomNumber = (rand() % 100) + 1;
    return randomNumber;
}

int main()
{
    intro();
    int choice;
    Pirate pirate("Smee"); // instantiate pirate object
    Ninja ninja("Bruce"); // instantiate ninja object

    for (;;) { // main loop
        int attackHP; // declare attackHP for use later
        cout << "1. Ninja attacks Pirate" << endl << "2. Pirate attacks Ninja" << endl << "3. Display character health" << endl << "4. Reset character health to full" << endl; // display menu options
        cout << "5. Ninja attacks Pirate with random HP" << endl << "6. Pirate attacks Ninja with random HP" << endl << "9. EXIT" << endl; // display more menu options
        cout << "enter a choice: "; // instruct user to make a choice
        cin >> choice; // take user input

        switch (choice) { // use a switch
            case 1: // ninja attacks
                attackHP = ninja.Attack(); // define attackHP
                cout << endl << ninja.Name << " ATTACKS " << pirate.Name << " FOR " << attackHP << " hitpoints!" << endl << endl; // ninja attacks
                pirate.defend(attackHP); // subtract ninja's attack from pirate's health
                continue; // repeat loop from beginning
            case 2: // pirate attacks
                attackHP = pirate.Attack(); // define attackHP
                cout << endl << pirate.Name << " ATTACKS " << ninja.Name << " FOR " << attackHP << " hitpoints!" << endl << endl; // pirate attacks
                ninja.defend(attackHP); // subtract pirate's attack from ninja's health
                continue; // repeat loop from beginning
            case 3: // display character health
                cout << endl << "CURRENT HEALTH:" << endl << "===============" << endl; // display health
                cout << pirate.Name << ": " << pirate.getHealth() << endl;
                cout << ninja.Name << ": " << ninja.getHealth() << endl;
                cout << "===============" << endl << endl;
                continue;
            case 4: // reset everyone's health to full
                pirate.setHealth(100);
                ninja.setHealth(100);
                cout << "FULL HEALTH FOR ALL!" << endl << endl;
                continue;
            case 5: // ninja attacks pirate random
                attackHP = RandomRoll(); // define attackHP
                pirate.defend(attackHP); // subtract ninja's attack from pirate's health
                ninja.Talk(ninja.Name, "you've dishonored me, so NOW I MUST ATTACK YOU EXTRA HARD TO RESTORE KARMIC BALANCE!");
                cout << endl << ninja.Name << " ATTACKS " << pirate.Name << " FOR " << attackHP << " hitpoints!" << endl << endl;
                continue;
            case 6: // pirate attacks ninja random
                attackHP = RandomRoll(); // define attackHP
                ninja.defend(attackHP); // subtract pirate's attack from ninja's health
                pirate.Talk(pirate.Name, "YOU'LL WALK THE PLANK FOR THAT, ya SCALLYWAG! YARRRRR!!!");
                cout << endl << pirate.Name << " ATTACKS " << ninja.Name << " FOR " << attackHP << " hitpoints!" << endl << endl;
                continue;
            case 8:
                pirate.Help();
                ninja.Help();
                continue;
            case 9:
                cout << endl << "BYE! THANKS FOR PLAYING!" << endl; // exit game
                break; // exit switch
        }
        break;
    }
}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
