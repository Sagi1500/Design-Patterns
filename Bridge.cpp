/*
 * Created by Sagi Wilentzik on 15/02/2022.
 */

#include <iostream>

using namespace std;

class Houselmp {
public:
    virtual void paintDoor() = 0;

    virtual void paintWindow() = 0;

    virtual void paintRoof() = 0;

};

class House {
protected:
    Houselmp *lmp;
public:
    House(Houselmp *houselmp) : lmp(houselmp) {};

    virtual void paint() = 0;

    virtual ~House() {
        delete lmp;
    }

};

class Woodlmp : public Houselmp {
public:
    void paintDoor() {
        std::cout << "painting wood door" << std::endl;
    }

    virtual void paintWindow() {
        std::cout << "painting wood window" << std::endl;
    }

    virtual void paintRoof() {
        std::cout << "painting wood roof" << std::endl;
    }

};

class Bricklmp : public Houselmp {
public:
    virtual void paintDoor() {
        std::cout << "painting wood door" << std::endl;
    }

    virtual void paintWindow() {
        std::cout << "painting wood window" << std::endl;
    }

    virtual void paintRoof() {
        std::cout << "painting wood roof" << std::endl;
    }

};

class SmallHouse : public House {
public:
    SmallHouse(Houselmp *house_lmp) : House(house_lmp) {}

    void paint() {
        std::cout << "Small house: " << std::endl;
        this->lmp->paintDoor();
        this->lmp->paintRoof();
        this->lmp->paintWindow();
    }

    ~SmallHouse() {
        cout << "delete " << "SmallHouse" << endl;
    }
};

class BigHouse : public House {
public:
    BigHouse(Houselmp *lmp) : House(lmp) {}

    void paint() {
        std::cout << "Big house: " << std::endl;
        this->lmp->paintDoor();
        this->lmp->paintRoof();
        this->lmp->paintWindow();
    }

    ~BigHouse() {
        cout << "delete " << "BigHouse" << endl;
    }
};

int main() {
    House *house1 = new BigHouse(new Woodlmp());
    house1->paint();
    std::cout << "end of house1 \n " << std::endl;

    House *house2 = new SmallHouse(new Bricklmp());
    house2->paint();
    std::cout << "end of house2" << std::endl;

    delete house1;
    delete house2;


}







