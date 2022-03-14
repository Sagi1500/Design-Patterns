/*
 * Created by Sagi Wilentzik on 15/02/2022.
 */

#include <stdlib.h>
#include <cstdint>
#include <iostream>
#include <vector>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Character {
protected:
    int health;
public:
    Character() { health = 0; }

    void setHealth(int health) {
        health = health;
    }

    int getHealth() const {
        return health;
    }

    virtual void print(int i, int j) = 0;
};

class Robot: public Character{
public:
    Robot(int health1) {
        health = health1;
    }
    void print(int i, int j) {
        cout << "Robot=" << this << " is at [" << i << ", " << j<<  "] with health=" << health << endl;
    }

};

class Airplane: public Character {
public:
    Airplane(int health1) {
        health = health1;
    }
    void print(int i, int j) {
        cout << "Airplane=" << this << " is at [" << i << "," << j<<  "] with health=" << health << endl;
    }
};


class flyweight {
protected:
    vector<Character *> game_characters;
    virtual Character *newCharacter(int health) = 0;


public:
    Character* getCharacter(int health) {
        for(Character* character: game_characters) {
            if(character->getHealth() == health){
                return character;
            }
        }
        Character* character1 = newCharacter(health);
        game_characters.push_back(character1);
        return character1;
    }

    ~ flyweight() {
        for_each(game_characters.begin(), game_characters.end(), [](Character* c) {delete c;});
    }
};


class RobotFlyweight : public flyweight {
    Character *newCharacter(int health) override {
        return new Robot(health);
    }
};

class AirplaneFlyweight : public flyweight {
    Character *newCharacter(int health) override {
        return new Airplane(health);
    }
};

int main() {
    Character *table[4][4];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            table[i][j] = nullptr;
        }
    }
    flyweight *robotFlyweight = new RobotFlyweight();
    flyweight *airplaneFlyweight = new AirplaneFlyweight();
    table[0][0] = robotFlyweight->getCharacter(100);
    table[1][0] = robotFlyweight->getCharacter(100);
    table[0][2] = airplaneFlyweight->getCharacter(50);
    table[1][2] = airplaneFlyweight->getCharacter(50);
    table[1][3] = airplaneFlyweight->getCharacter(50);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (table[i][j])
                table[i][j]->print(i, j);
        }
    }
    cout << "An airplane was hit: Airplane [1,2] health=10" << endl;
    table[1][2] = airplaneFlyweight->getCharacter(10);
    cout << "After change:" << endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (table[i][j])
                table[i][j]->print(i, j);
        }
    }

    delete robotFlyweight;
    delete airplaneFlyweight;
}
