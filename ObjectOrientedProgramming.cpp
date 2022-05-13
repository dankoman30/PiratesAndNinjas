// ObjectOrientedProgramming.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class GameStructure {
public:
    int RandomRoll() {
        srand((unsigned)time(0));
        int randomNumber;
        randomNumber = (rand() % 100) + 1;
        return randomNumber;
    }
    virtual void Help() {}
};

class Character: public GameStructure {
private:
    int Health = 100; // start health at 100
public:
    string Name;
    int getHealth() {
        return Health;
    }
    void setHealth(int hitPoints) {
        Health -= hitPoints; // subtract hitPoints from Health
        if (Health < 0) { // character is dead
            Health = 0;
            cout << "Character has Expired..." << endl;
        }
    }
    void Talk(string stuffToSay) {
        cout << stuffToSay << endl;
    }
    void Talk(string name, string stuffToSay) {
        cout << "I'm " << name << ", and " << stuffToSay << endl;
    }
    virtual int Attack() {
        return 10; // attack returns 10 hit points
    }
    void Help() {}
};

class Ninja : public Character {
public:
    void ThrowStars() {
        cout << "I am throwing stars!" << endl;
    }
    Ninja(string N) { // constructor
        Name = N;
    }
    int Attack() {
        return 25; // overrride superclass method
    }
    void Help() {
        cout << "Ninjas are quiet and swift; you can use them to throw stars!" << endl;
    }

};

class Pirate : public Character {
public:
    void UseSword() {
        cout << "I am Swooshing my Sword!" << endl;
    }
    Pirate(string N) { // constructor
        Name = N;
    }
    int Attack() {
        return 25; // overrride superclass method
    }
    void Help() {
        cout << "Pirates are loud and forceful; you can use them to attack with swords!" << endl;
    }
};

void intro() {
    // intro stuff here
}

int main()
{
    intro();
    int choice;
    GameStructure game;
    for (;;) { // main loop
        cout << "1. Something" << endl << "2. Something else" << endl << "3. RandomRoll" << endl << "9. EXIT" << endl;
        cout << "enter a choice" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "do stuff" << endl;
                continue; // repeat loop from beginning
            case 2:
                cout << "do other stuff" << endl;
                continue; // repeat loop from beginning
            case 3:
                cout << "YOU ROLLED A " << game.RandomRoll() << endl;
                continue;
            case 9:
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
