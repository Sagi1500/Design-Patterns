/*
 * Created by Sagi Wilentzik on 15/02/2022.
 */

#include <iostream>
#include <cstring>

using namespace std;

class Student {
    char *name;
public:
    Student(const char *name1) {
        name = new char[strlen(name1) + 1];
        strcpy(name, name1);
    }

    void sleep() {
        cout << "I'm sleeping!! (" << name << ")" << endl;
    }

    void eat() {
        cout << "Yummy (" << name << ")" << endl;
    }
};

class Command {
public:
    virtual void execute() = 0;
};

class SleepCommand : public Command {
    Student *student;
public:
    void execute() {
        student->sleep();
    }

    SleepCommand(Student *student1) {
        student = student1;
    }
};

class EatCommand : public Command {
    Student *student;
public:
    EatCommand(Student *student1) {
        student = student1;
    }

    void execute() {
        student->eat();
    }
};

class Parent {
    Command **commands;
public:
    Parent(Student *student) {
        commands = new Command *[2];
        commands[0] = new SleepCommand(student);
        commands[1] = new EatCommand(student);
    }

    void makeStudentSleep() {
        commands[0]->execute();
    }

    void makeStudentEat() {
        commands[1]->execute();
    }
};


int main() {
    Student student("Sagi");
    Parent p(&student);
    p.makeStudentEat();
    p.makeStudentSleep();
}