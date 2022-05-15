#pragma once
#include <string>

using namespace std;

class GameStructure { // create root class
public:
    virtual void Help(); // virtual empty method
};

class Character : public GameStructure { // declare Character class, derived from GameStructure
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

class Ninja : public Character { // declare Ninja class, derived from Character
public:
    Ninja(string N, int H); // constructor
    void ThrowStars(); // declare methods:
    int Attack();
    void Help();

};

class Pirate : public Character { // declare Pirate class, derived from Character
public:
    Pirate(string N, int H); // constructor
    void UseSword(); // declare methods:
    int Attack();
    void Help();
};