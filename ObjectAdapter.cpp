/*
 * Created by Sagi Wilentzik on 15/02/2022.
 */


#include <iostream>

using namespace std;

class EnemyAttacker {
public:
    virtual void fireWeapon()=0;
    virtual void driveForward()=0;
    virtual void assignDriver()=0;
};

class EnemyRobot {
public:
    void smashWithHands(){
        cout << "Smash with hands!" << endl;
    }
    void walkForward(){
        cout << "Walking forwards!" << endl;
    }
    void reactToHumans(){
        cout << "Hi human!" << endl;
    }

};


class EnemyRobotAdapter : public EnemyAttacker {
private:
    EnemyRobot* robot;
public:
    EnemyRobotAdapter(EnemyRobot* robot1) {
        robot = robot1;
    }
    void fireWeapon() override {
        robot->smashWithHands();
    }

    void driveForward() {
        robot->walkForward();
    }

    void assignDriver() {
        robot->reactToHumans();
    }
};

class EnemySoldier : public EnemyAttacker {
private:
    string name;
public:
    EnemySoldier(string name1) {
        name = name1;
    }

    void fireWeapon() override {
        cout << "fire!" << endl;
    }

    void driveForward() {
        cout << "driving forward!" << endl;
    }

    void assignDriver() {
        cout << "assigning new driver!" << endl;
    }
};

int main(){

    EnemySoldier* soldier = new EnemySoldier("soldier1");
    EnemyRobot* robot = new EnemyRobot();
    EnemyRobotAdapter* adapter = new EnemyRobotAdapter(robot);

    adapter->fireWeapon();
    adapter->assignDriver();
    adapter->driveForward();

    soldier->fireWeapon();
    soldier->assignDriver();
    soldier->driveForward();

    delete soldier;
    delete robot;
    delete adapter;

    return 1;
}
