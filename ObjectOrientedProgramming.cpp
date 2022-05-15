// ObjectOrientedProgramming.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std; // save us some typing

class GameStructure { // create root class
public:
    virtual void Help() {} // virtual empty method
};

class Character: public GameStructure { // create character class, inheriting from gamestructure
private:
    int Health = 100; // start health at 100, this property is private
public:
    string Name;
    int getHealth() { // health getter method
        return Health;
    }
    void setHealth(int health) { // health setter method
        Health = health;
        if (Health <= 0) { // character is dead if health is less than or equal to zero
            Health = 0; // in case health is less than zero, reset it to zero
            cout << Name << " has Expired..." << endl;
        }
    }
    void defend(int hitPoints) {
        int newHealth = getHealth() - hitPoints; // what will the health be after attack?
        setHealth(newHealth); // set the new health
    }
    void Talk(string stuffToSay) { // method for character to speak
        cout << endl << stuffToSay << endl << endl;
    }
    void Talk(string name, string stuffToSay) { // another method for character to speak, but allows name to be passed in as well
        cout << endl << "I'm " << name << ", and " << stuffToSay << endl << endl;
    }
    virtual int Attack() { // default attack method for character results in 10 hit points
        return 10; // attack returns 10 hit points
    }
    void Help() {} // overriding help method
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
        cout << endl << "Ninjas are quiet and swift; you can use them to throw stars!" << endl << endl;
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
        cout << endl << "Pirates are loud and forceful; you can use them to attack with swords!" << endl << endl;
    }
};

void intro() {
    // intro stuff here
    cout << "Hi, welcome to PIRATES & NINJAS!!!" << endl << "In this game, a pirate and a ninja fight the ultimate battle to the death!" << endl;
}

int RandomRoll() {
    srand((unsigned)time(0));
    int randomNumber;
    randomNumber = (rand() % 100) + 1;
    return randomNumber;
}

string CharacterName(string charType) { // method for retrieving string from user for character name
    string enteredName;
    cout << endl << "enter a name for " << charType << endl;
    cin >> enteredName;
    return enteredName;
}

int main()
{
    intro(); // call intro method
    int choice; // declare choice, for use later

    string pirateName = CharacterName("PIRATE"); // get pirate name from user
    string ninjaName = CharacterName("NINJA"); // get ninja name from user

    Pirate pirate(pirateName); // instantiate pirate object
    Ninja ninja(ninjaName); // instantiate ninja object

    for (;;) { // main loop
        int attackHP; // declare attackHP for use later
        cout << "1. Ninja attacks Pirate" << endl << "2. Pirate attacks Ninja" << endl << "3. Display character health" << endl << "4. Reset character health to full" << endl; // display menu options
        cout << "5. Ninja attacks Pirate with random HP" << endl << "6. Pirate attacks Ninja with random HP" << endl << "8. Help" << endl <<"9. EXIT" << endl; // display more menu options
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
                ninja.Talk(ninja.Name, "you've dishonored me, so NOW I MUST ATTACK YOU EXTRA HARD TO RESTORE KARMIC BALANCE TO THE UNIVERSE!");
                cout << endl << ninja.Name << " ATTACKS " << pirate.Name << " FOR " << attackHP << " hitpoints!" << endl << endl;
                continue;
            case 6: // pirate attacks ninja random
                attackHP = RandomRoll(); // define attackHP
                ninja.defend(attackHP); // subtract pirate's attack from ninja's health
                pirate.Talk(pirate.Name, "YOU'LL WALK THE PLANK FOR THAT, ya SCALLYWAG! YARRRRR!!!");
                cout << endl << pirate.Name << " ATTACKS " << ninja.Name << " FOR " << attackHP << " hitpoints!" << endl << endl;
                continue;
            case 8: // help
                pirate.Help();
                ninja.Help();
                continue;
            case 9: // end game sequence
                cout << endl << endl;
                if (pirate.getHealth() > ninja.getHealth()) { // pirate wins
                    cout << pirate.Name << " the pirate has won the game!";
                }
                else if (ninja.getHealth() > pirate.getHealth()) { // ninja wins
                    cout << ninja.Name << " the ninja has won the game!";
                }
                else { // tie game
                    cout << pirate.Name << " and " << ninja.Name << " have tied.  There is no clear winner.";
                }
                cout << endl << "BYE! THANKS FOR PLAYING!" << endl;
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
