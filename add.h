#pragma once
#include <string>

using namespace std;

class GameStructure { // create root class
public:
    virtual void Help(); // virtual empty method
};

class Character : public GameStructure { // create character class, inheriting from gamestructure
private:
    int Health;
public:
    string Name;
    int getHealth();

    void setHealth(int health);

    void defend(int hitPoints);

    void Talk(string stuffToSay);

    void Talk(string name, string stuffToSay);

    virtual int Attack();

    void Help(); // overriding help method
};

class Ninja : public Character {
public:
    void ThrowStars();
    Ninja(string N, int H);
    int Attack();
    void Help();

};

class Pirate : public Character {
public:
    void UseSword();
    Pirate(string N, int H);
    int Attack();
    void Help();
};